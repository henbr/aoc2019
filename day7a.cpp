#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <limits>

using namespace std;

//static vector<int> program = {3,23,3,24,1002,24,10,24,1002,23,-1,23,101,5,23,23,1,24,23,23,4,23,99,0,0};

static vector<int> program = {3,8,1001,8,10,8,105,1,0,0,21,42,67,88,101,114,195,276,357,438,99999,3,9,101,3,9,9,1002,9,4,9,1001,9,5,9,102,4,9,9,4,9,99,3,9,1001,9,3,9,1002,9,2,9,101,2,9,9,102,2,9,9,1001,9,5,9,4,9,99,3,9,102,4,9,9,1001,9,3,9,102,4,9,9,101,4,9,9,4,9,99,3,9,101,2,9,9,1002,9,3,9,4,9,99,3,9,101,4,9,9,1002,9,5,9,4,9,99,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,99,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,99,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,102,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,1,9,4,9,99,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,2,9,9,4,9,99};

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

int run_program(vector<int> mem, vector<int> input) {
    auto itr = mem.begin();
    bool error = false;
    bool halt = false;

    while(itr != mem.end() && !error && !halt) {
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
                if (!input.empty()) {
                    param1 = fetch(itr, mem.end(), error);
                    param2 = input.back();
                    input.pop_back();

                    store(param1, param2, mem, error);
                } else {
                    error = true;
                }
                break;
            case 4: // Output
                param1 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;

                return param1;
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
                halt = true;
                break;
            default:
                error = true;
        }
    }

    throw runtime_error("ERROR! End of program reached!");
}

int run_amplifiers(vector<int> &mem, vector<int> phase_settings) {
    int output = 0;
    for (auto phase : phase_settings) {
        vector<int> input = {output, phase};
        output = run_program(mem, input);
    }
    return output;
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
    vector<int> initial_perm = {0,1,2,3,4};
    vector<vector<int>> permutations;
    generate_permutations(permutations, initial_perm.size(), initial_perm);

    int max_output = numeric_limits<int>::min();
    for (auto &phase_settings : permutations) {
        auto res = run_amplifiers(program, phase_settings);
        max_output = max(max_output, res);
    }
    cout << "Result: " << max_output << endl;

    return 0;
}
