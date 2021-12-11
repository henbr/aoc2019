#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>

using namespace std;

vector<int> program = {3,225,1,225,6,6,1100,1,238,225,104,0,2,218,57,224,101,-3828,224,224,4,224,102,8,223,223,1001,224,2,224,1,223,224,223,1102,26,25,224,1001,224,-650,224,4,224,1002,223,8,223,101,7,224,224,1,223,224,223,1102,44,37,225,1102,51,26,225,1102,70,94,225,1002,188,7,224,1001,224,-70,224,4,224,1002,223,8,223,1001,224,1,224,1,223,224,223,1101,86,70,225,1101,80,25,224,101,-105,224,224,4,224,102,8,223,223,101,1,224,224,1,224,223,223,101,6,91,224,1001,224,-92,224,4,224,102,8,223,223,101,6,224,224,1,224,223,223,1102,61,60,225,1001,139,81,224,101,-142,224,224,4,224,102,8,223,223,101,1,224,224,1,223,224,223,102,40,65,224,1001,224,-2800,224,4,224,1002,223,8,223,1001,224,3,224,1,224,223,223,1102,72,10,225,1101,71,21,225,1,62,192,224,1001,224,-47,224,4,224,1002,223,8,223,101,7,224,224,1,224,223,223,1101,76,87,225,4,223,99,0,0,0,677,0,0,0,0,0,0,0,0,0,0,0,1105,0,99999,1105,227,247,1105,1,99999,1005,227,99999,1005,0,256,1105,1,99999,1106,227,99999,1106,0,265,1105,1,99999,1006,0,99999,1006,227,274,1105,1,99999,1105,1,280,1105,1,99999,1,225,225,225,1101,294,0,0,105,1,0,1105,1,99999,1106,0,300,1105,1,99999,1,225,225,225,1101,314,0,0,106,0,0,1105,1,99999,108,226,677,224,102,2,223,223,1005,224,329,1001,223,1,223,1107,677,226,224,102,2,223,223,1006,224,344,1001,223,1,223,7,226,677,224,1002,223,2,223,1005,224,359,101,1,223,223,1007,226,226,224,102,2,223,223,1005,224,374,101,1,223,223,108,677,677,224,102,2,223,223,1006,224,389,1001,223,1,223,107,677,226,224,102,2,223,223,1006,224,404,101,1,223,223,1108,677,226,224,102,2,223,223,1006,224,419,1001,223,1,223,1107,677,677,224,1002,223,2,223,1006,224,434,101,1,223,223,1007,677,677,224,102,2,223,223,1006,224,449,1001,223,1,223,1108,226,677,224,1002,223,2,223,1006,224,464,101,1,223,223,7,677,226,224,102,2,223,223,1006,224,479,101,1,223,223,1008,226,226,224,102,2,223,223,1006,224,494,101,1,223,223,1008,226,677,224,1002,223,2,223,1005,224,509,1001,223,1,223,1007,677,226,224,102,2,223,223,1005,224,524,1001,223,1,223,8,226,226,224,102,2,223,223,1006,224,539,101,1,223,223,1108,226,226,224,1002,223,2,223,1006,224,554,101,1,223,223,107,226,226,224,1002,223,2,223,1005,224,569,1001,223,1,223,7,226,226,224,102,2,223,223,1005,224,584,101,1,223,223,1008,677,677,224,1002,223,2,223,1006,224,599,1001,223,1,223,8,226,677,224,1002,223,2,223,1006,224,614,1001,223,1,223,108,226,226,224,1002,223,2,223,1006,224,629,101,1,223,223,107,677,677,224,102,2,223,223,1005,224,644,1001,223,1,223,8,677,226,224,1002,223,2,223,1005,224,659,1001,223,1,223,1107,226,677,224,102,2,223,223,1005,224,674,1001,223,1,223,4,223,99,226};
//vector<int> program = {3,0,4,0,99};

// Part 1
//constexpr int INPUT = 1;
// Part 2
constexpr int INPUT = 5;

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

void run_program(vector<int> mem) {
    auto itr = mem.begin();
    bool error = false;
    bool halt = false;

    while(itr != mem.end() && !error && !halt) {
     //   cout << itr - mem.begin() << endl;

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
                param1 = fetch(itr, mem.end(), error);

                store(param1, INPUT, mem, error);
                break;
            case 4: // Output
                param1 = fetch(itr, mem.end(), error);

                param1 = !param_mode_imm1 ? read(param1, mem, error) : param1;

                cout << "Output: " << param1 << endl;
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
                halt = true;
                break;
            default:
                error = true;
        }
    }

    if (error) {
        cout << "ERROR!" << endl;
    }
}

int main() {
    run_program(program);

    return 0;
}
