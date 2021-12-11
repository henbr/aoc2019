#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <limits>

using namespace std;

//static vector<int> program = {3,26,1001,26,-4,26,3,27,1002,27,2,27,1,27,26,27,4,27,1001,28,-1,28,1005,28,6,99,0,0,5};

static vector<int> program = {3,8,1001,8,10,8,105,1,0,0,21,42,67,88,101,114,195,276,357,438,99999,3,9,101,3,9,9,1002,9,4,9,1001,9,5,9,102,4,9,9,4,9,99,3,9,1001,9,3,9,1002,9,2,9,101,2,9,9,102,2,9,9,1001,9,5,9,4,9,99,3,9,102,4,9,9,1001,9,3,9,102,4,9,9,101,4,9,9,4,9,99,3,9,101,2,9,9,1002,9,3,9,4,9,99,3,9,101,4,9,9,1002,9,5,9,4,9,99,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,99,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,99,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,102,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,99};

enum class CpuState {
    Init,
    Running,
    Error,
    Halt,
    Output
};

struct IntCpu {
    vector<int> memory;
    vector<int> input;
    int output = 0;
    CpuState state = CpuState::Init;
    int pc = 0;
};

int fetch(vector<int>::iterator &itr, vector<int>::iterator end, bool &error) {
    if (itr != end) {
        auto res = *itr;
        itr++;
        return res;
    } else {
        error = true;
        return 0;
    }
}

int read(int addr, vector<int> &mem, bool &error) {
    if (addr < 0 || addr >= mem.size()) {
        error = true;
        return 0;
    } else {
        return mem[addr];
    }
}

void store(int addr, int data, vector<int> &mem, bool &error) {
    if (addr < 0 || addr >= mem.size()) {
        error = true;
    } else {
        mem[addr] = data;
    }
}

void run_cpu(IntCpu &cpu) {
    vector<int> &mem = cpu.memory;
    auto itr = mem.begin() + cpu.pc;
    cpu.state = CpuState::Running;
    bool error = false;

    while(itr != mem.end() && cpu.state == CpuState::Running) {
        int opcode_packed = fetch(itr, mem.end(), error);

        int opcode = opcode_packed % 100;
        // 0 = address, 1 = immediate
        int param_mode_imm1 = (opcode_packed / 100) % 10;
        int param_mode_imm2 = (opcode_packed / 1000) % 10;
        int param_mode_imm3 = (opcode_packed / 10000) % 10;

        int param1 = 0;
        int param2 = 0;
        int param3 = 0;
        int res = 0;

        switch(opcode) {
            case 1: // Add
                param1 = fetch(itr, mem.end(), error);
                param2 = fetch(itr, mem.end(), error);
                param3 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;
                param2 = !param_mode_imm2 ? read(param2, mem, error) : param2;

                res = param1 + param2;

                store(param3, res, mem, error);
                break;
            case 2: // Mult
                param1 = fetch(itr, mem.end(), error);
                param2 = fetch(itr, mem.end(), error);
                param3 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;
                param2 = !param_mode_imm2 ? read(param2, mem, error) : param2;

                res = param1 * param2;

                store(param3, res, mem, error);
                break;
            case 3: // Input
                if (!cpu.input.empty()) {
                    param1 = fetch(itr, mem.end(), error);
                    param2 = cpu.input.back();
                    cpu.input.pop_back();

                    store(param1, param2, mem, error);
                } else {
                    error = true;
                }
                break;
            case 4: // Output
                param1 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;

                cpu.output = param1;
                cpu.state = CpuState::Output;
                break;
            case 5: // Jump if true
                param1 = fetch(itr, mem.end(), error);
                param2 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;
                param2 = !param_mode_imm2 ? read(param2, mem, error) : param2;

                if (param1) {
                    if (param2 < 0 || param2 >= mem.size()) {
                        error = true;
                    } else {
                        itr = mem.begin() + param2;
                    }
                }
                break;
            case 6: // Jump if false
                param1 = fetch(itr, mem.end(), error);
                param2 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;
                param2 = !param_mode_imm2 ? read(param2, mem, error) : param2;

                if (!param1) {
                    if (param2 < 0 || param2 >= mem.size()) {
                        error = true;
                    } else {
                        itr = mem.begin() + param2;
                    }
                }
            break;
            case 7: // Less than, param1 < param2
                param1 = fetch(itr, mem.end(), error);
                param2 = fetch(itr, mem.end(), error);
                param3 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;
                param2 = !param_mode_imm2 ? read(param2, mem, error) : param2;

                if (param1 < param2) {
                    store(param3, 1, mem, error);
                } else {
                    store(param3, 0, mem, error);
                }
            break;
            case 8: // Equal, param1 == param2
                param1 = fetch(itr, mem.end(), error);
                param2 = fetch(itr, mem.end(), error);
                param3 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;
                param2 = !param_mode_imm2 ? read(param2, mem, error) : param2;

                if (param1 == param2) {
                    store(param3, 1, mem, error);
                } else {
                    store(param3, 0, mem, error);
                }
            break;
            case 99: // Halt
                cpu.state = CpuState::Halt;
                break;
            default:
                error = true;
        }

        cpu.pc = itr - mem.begin();

        if (error) {
            cpu.state = CpuState::Error;
        }

        if (itr == mem.end() && cpu.state != CpuState::Error && cpu.state != CpuState::Halt) {
            cpu.state = CpuState::Error;
        }
    }
}

int run_amplifiers(vector<IntCpu> cpus, vector<int> phase_settings) {
    bool halt_detected = false;
    int last_cpu_output = 0;
    int output = 0;
    while(!halt_detected) {
        for (int i = 0; i < cpus.size(); i++) {
            if (cpus[i].state == CpuState::Init) {
                cpus[i].input = {output, phase_settings[i]};
            } else {
                cpus[i].input = {output};
            }
            run_cpu(cpus[i]);

            if (cpus[i].state == CpuState::Halt) {
                halt_detected = true;
                break;
            } else if (cpus[i].state == CpuState::Error) {
                throw runtime_error("Cpu error!");
            } else if (cpus[i].state == CpuState::Output) {
                output = cpus[i].output;
                if (i == cpus.size()-1) {
                    last_cpu_output = output;
                }
            }
        }
    }

    return last_cpu_output;
}

void generate_permutations(vector<vector<int>> &permutations, int k, vector<int> &current_permutation) {
    if (k == 1) {
        permutations.push_back(current_permutation);
    } else {
        for (int i = 0; i < k; i++) {
            generate_permutations(permutations, k-1, current_permutation);
            if (k % 2 == 0) {
                swap(current_permutation[i], current_permutation[k-1]);
            } else {
                swap(current_permutation[0], current_permutation[k-1]);
            }
        }
    }
}

int main() {
    vector<int> initial_perm = {5,6,7,8,9};
    vector<vector<int>> permutations;
    generate_permutations(permutations, initial_perm.size(), initial_perm);

    int max_output = numeric_limits<int>::min();
    for (auto &phase_settings : permutations) {
        vector<IntCpu> cpus;
        for (int i = 0; i < 5; i++) {
            cpus.push_back(IntCpu());
            cpus.back().memory = program;
        }

        auto res = run_amplifiers(cpus, phase_settings);
        max_output = max(max_output, res);
    }

    cout << "Result: " << max_output << endl;

    return 0;
}
