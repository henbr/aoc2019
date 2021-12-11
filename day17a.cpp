#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <limits>
#include <array>
#include <stack>
#include <queue>
#include <functional>

using namespace std;


static vector<int64_t> program = {1,330,331,332,109,3132,1102,1,1182,16,1101,1467,0,24,101,0,0,570,1006,570,36,101,0,571,0,1001,570,-1,570,1001,24,1,24,1105,1,18,1008,571,0,571,1001,16,1,16,1008,16,1467,570,1006,570,14,21102,58,1,0,1106,0,786,1006,332,62,99,21102,1,333,1,21102,73,1,0,1106,0,579,1101,0,0,572,1101,0,0,573,3,574,101,1,573,573,1007,574,65,570,1005,570,151,107,67,574,570,1005,570,151,1001,574,-64,574,1002,574,-1,574,1001,572,1,572,1007,572,11,570,1006,570,165,101,1182,572,127,1001,574,0,0,3,574,101,1,573,573,1008,574,10,570,1005,570,189,1008,574,44,570,1006,570,158,1105,1,81,21101,0,340,1,1106,0,177,21101,0,477,1,1105,1,177,21101,514,0,1,21102,176,1,0,1106,0,579,99,21102,1,184,0,1106,0,579,4,574,104,10,99,1007,573,22,570,1006,570,165,1002,572,1,1182,21102,1,375,1,21101,0,211,0,1106,0,579,21101,1182,11,1,21102,1,222,0,1106,0,979,21102,388,1,1,21102,233,1,0,1105,1,579,21101,1182,22,1,21101,244,0,0,1106,0,979,21102,1,401,1,21101,255,0,0,1105,1,579,21101,1182,33,1,21102,266,1,0,1105,1,979,21102,1,414,1,21102,1,277,0,1105,1,579,3,575,1008,575,89,570,1008,575,121,575,1,575,570,575,3,574,1008,574,10,570,1006,570,291,104,10,21102,1,1182,1,21101,313,0,0,1105,1,622,1005,575,327,1101,0,1,575,21102,1,327,0,1106,0,786,4,438,99,0,1,1,6,77,97,105,110,58,10,33,10,69,120,112,101,99,116,101,100,32,102,117,110,99,116,105,111,110,32,110,97,109,101,32,98,117,116,32,103,111,116,58,32,0,12,70,117,110,99,116,105,111,110,32,65,58,10,12,70,117,110,99,116,105,111,110,32,66,58,10,12,70,117,110,99,116,105,111,110,32,67,58,10,23,67,111,110,116,105,110,117,111,117,115,32,118,105,100,101,111,32,102,101,101,100,63,10,0,37,10,69,120,112,101,99,116,101,100,32,82,44,32,76,44,32,111,114,32,100,105,115,116,97,110,99,101,32,98,117,116,32,103,111,116,58,32,36,10,69,120,112,101,99,116,101,100,32,99,111,109,109,97,32,111,114,32,110,101,119,108,105,110,101,32,98,117,116,32,103,111,116,58,32,43,10,68,101,102,105,110,105,116,105,111,110,115,32,109,97,121,32,98,101,32,97,116,32,109,111,115,116,32,50,48,32,99,104,97,114,97,99,116,101,114,115,33,10,94,62,118,60,0,1,0,-1,-1,0,1,0,0,0,0,0,0,1,0,10,0,109,4,1202,-3,1,587,20102,1,0,-1,22101,1,-3,-3,21101,0,0,-2,2208,-2,-1,570,1005,570,617,2201,-3,-2,609,4,0,21201,-2,1,-2,1105,1,597,109,-4,2105,1,0,109,5,2102,1,-4,630,20102,1,0,-2,22101,1,-4,-4,21101,0,0,-3,2208,-3,-2,570,1005,570,781,2201,-4,-3,653,20101,0,0,-1,1208,-1,-4,570,1005,570,709,1208,-1,-5,570,1005,570,734,1207,-1,0,570,1005,570,759,1206,-1,774,1001,578,562,684,1,0,576,576,1001,578,566,692,1,0,577,577,21101,702,0,0,1105,1,786,21201,-1,-1,-1,1105,1,676,1001,578,1,578,1008,578,4,570,1006,570,724,1001,578,-4,578,21101,0,731,0,1106,0,786,1106,0,774,1001,578,-1,578,1008,578,-1,570,1006,570,749,1001,578,4,578,21101,0,756,0,1105,1,786,1105,1,774,21202,-1,-11,1,22101,1182,1,1,21102,1,774,0,1106,0,622,21201,-3,1,-3,1106,0,640,109,-5,2106,0,0,109,7,1005,575,802,21002,576,1,-6,20101,0,577,-5,1105,1,814,21101,0,0,-1,21101,0,0,-5,21102,1,0,-6,20208,-6,576,-2,208,-5,577,570,22002,570,-2,-2,21202,-5,45,-3,22201,-6,-3,-3,22101,1467,-3,-3,1201,-3,0,843,1005,0,863,21202,-2,42,-4,22101,46,-4,-4,1206,-2,924,21102,1,1,-1,1105,1,924,1205,-2,873,21101,0,35,-4,1105,1,924,2102,1,-3,878,1008,0,1,570,1006,570,916,1001,374,1,374,2102,1,-3,895,1102,2,1,0,1201,-3,0,902,1001,438,0,438,2202,-6,-5,570,1,570,374,570,1,570,438,438,1001,578,558,921,21001,0,0,-4,1006,575,959,204,-4,22101,1,-6,-6,1208,-6,45,570,1006,570,814,104,10,22101,1,-5,-5,1208,-5,37,570,1006,570,810,104,10,1206,-1,974,99,1206,-1,974,1102,1,1,575,21101,0,973,0,1106,0,786,99,109,-7,2105,1,0,109,6,21101,0,0,-4,21102,0,1,-3,203,-2,22101,1,-3,-3,21208,-2,82,-1,1205,-1,1030,21208,-2,76,-1,1205,-1,1037,21207,-2,48,-1,1205,-1,1124,22107,57,-2,-1,1205,-1,1124,21201,-2,-48,-2,1106,0,1041,21102,1,-4,-2,1105,1,1041,21101,0,-5,-2,21201,-4,1,-4,21207,-4,11,-1,1206,-1,1138,2201,-5,-4,1059,1202,-2,1,0,203,-2,22101,1,-3,-3,21207,-2,48,-1,1205,-1,1107,22107,57,-2,-1,1205,-1,1107,21201,-2,-48,-2,2201,-5,-4,1090,20102,10,0,-1,22201,-2,-1,-2,2201,-5,-4,1103,2101,0,-2,0,1106,0,1060,21208,-2,10,-1,1205,-1,1162,21208,-2,44,-1,1206,-1,1131,1106,0,989,21102,1,439,1,1105,1,1150,21101,0,477,1,1106,0,1150,21102,1,514,1,21102,1,1149,0,1105,1,579,99,21101,1157,0,0,1106,0,579,204,-2,104,10,99,21207,-3,22,-1,1206,-1,1138,1201,-5,0,1176,2102,1,-4,0,109,-6,2106,0,0,8,9,36,1,7,1,36,1,1,13,30,1,7,1,5,1,30,1,7,1,5,1,7,11,12,1,7,1,5,1,7,1,9,1,12,1,7,1,5,1,7,1,1,13,8,1,7,1,5,1,7,1,1,1,7,1,3,1,8,1,7,1,5,1,7,1,1,1,7,1,3,1,8,1,7,1,5,1,7,1,1,1,7,1,3,10,5,9,1,13,3,1,3,1,14,1,1,1,7,1,5,1,1,1,3,1,3,1,3,1,8,9,5,9,1,1,3,1,3,1,3,1,8,1,5,1,7,1,1,1,7,1,3,1,3,1,3,1,8,1,5,1,7,1,1,1,7,1,3,1,3,1,3,1,8,1,5,1,7,1,1,1,7,1,3,1,3,1,3,1,8,1,5,1,7,1,1,1,7,9,3,1,8,1,5,1,7,1,1,1,11,1,7,1,8,1,5,1,7,1,1,11,1,9,8,1,5,1,7,1,11,1,18,13,1,1,11,1,24,1,5,1,1,1,11,1,24,9,11,1,30,1,13,1,30,1,13,1,30,1,13,1,30,1,13,9,22,1,21,1,22,11,11,1,32,1,11,1,32,1,11,1,32,1,11,1,32,1,11,1,32,1,11,1,32,1,11,1,32,1,11,1,32,13,2};

// 0 = absolute address mode, 1 = immediate operand, 2 = relative address mode
constexpr int MODE_ADR = 0;
constexpr int MODE_IMM = 1;
constexpr int MODE_REL = 2;

enum class CpuState {
    Running,
    Error,
    Halt
};

struct IntCpu {
    vector<int64_t> memory;
    CpuState state = CpuState::Running;
    int64_t pc = 0;
    int64_t bp = 0;
    function<int64_t(IntCpu &cpu)> input;
    function<void(IntCpu &cpu, int64_t output)> output;
};

int64_t read(IntCpu &cpu, int64_t addr) {
    auto mem_size = cpu.memory.size();
    if (addr < 0 || addr >= mem_size) {
        //cout << "Out of range memory read!\n";
        cpu.memory.resize(mem_size*2, 0);
    }
    int64_t real_addr = addr % mem_size;
    real_addr = real_addr < 0 ? mem_size + real_addr : real_addr;
    return cpu.memory[addr];
}

void store(IntCpu &cpu, int64_t addr, int64_t data) {
    auto mem_size = cpu.memory.size();
    if (addr < 0 || addr >= mem_size) {
      //  cout << "Out of range memory store!\n";
        cpu.memory.resize(mem_size*2, 0);
    }
    int64_t real_addr = addr % mem_size;
    real_addr = real_addr < 0 ? mem_size + real_addr : real_addr;
    cpu.memory[addr] = data;
}

int64_t fetch(IntCpu &cpu) {
    int64_t res = read(cpu, cpu.pc);
    cpu.pc = (cpu.pc + 1) % cpu.memory.size();
    return res;
}

int64_t fetch_param(IntCpu &cpu, int mode) {
    auto data = fetch(cpu);
    switch(mode) {
    case MODE_ADR: return read(cpu, data);
    case MODE_IMM: return data;
    case MODE_REL: return read(cpu, cpu.bp + data);
    default: throw runtime_error("Illegal addressing mode!");
    }
}

void fetch_and_store_param(IntCpu &cpu, int64_t data, int mode) {
    if (mode == MODE_IMM) {
        throw runtime_error("Can't store to a immediate parameter!");
    }
    int64_t address = fetch(cpu);
    if (mode == MODE_REL) {
        address += cpu.bp;
    }
    store(cpu, address, data);
}

void run_cpu(IntCpu &cpu) {
    bool error = false;
    while(cpu.state == CpuState::Running) {
        int64_t opcode_packed = fetch(cpu);
        int64_t opcode = opcode_packed % 100;
        int mode_param1 = (opcode_packed / 100) % 10;
        int mode_param2 = (opcode_packed / 1000) % 10;
        int mode_param3 = (opcode_packed / 10000) % 10;

        int64_t param1 = 0;
        int64_t param2 = 0;
        int64_t res = 0;

        switch(opcode) {
            case 1: // Add
                param1 = fetch_param(cpu, mode_param1);
                param2 = fetch_param(cpu, mode_param2);
                res = param1 + param2;
                fetch_and_store_param(cpu, res, mode_param3);
                break;
            case 2: // Mult
                param1 = fetch_param(cpu, mode_param1);
                param2 = fetch_param(cpu, mode_param2);
                res = param1 * param2;
                fetch_and_store_param(cpu, res, mode_param3);
                break;
            case 3: // Input
                fetch_and_store_param(cpu, cpu.input(cpu), mode_param1);
                break;
            case 4: // Output
                param1 = fetch_param(cpu, mode_param1);
                cpu.output(cpu, param1);
                break;
            case 5: // Jump if true
                param1 = fetch_param(cpu, mode_param1);
                param2 = fetch_param(cpu, mode_param2);
                if (param1) {
                    if (param2 < 0 || param2 >= cpu.memory.size()) {
                        error = true;
                    } else {
                        cpu.pc = param2;
                    }
                }
                break;
            case 6: // Jump if false
                param1 = fetch_param(cpu, mode_param1);
                param2 = fetch_param(cpu, mode_param2);
                if (!param1) {
                    if (param2 < 0 || param2 >= cpu.memory.size()) {
                        error = true;
                    } else {
                        cpu.pc = param2;
                    }
                }
                break;
            case 7: // Less than, param1 < param2
                param1 = fetch_param(cpu, mode_param1);
                param2 = fetch_param(cpu, mode_param2);
                if (param1 < param2) {
                    fetch_and_store_param(cpu, 1, mode_param3);
                } else {
                    fetch_and_store_param(cpu, 0, mode_param3);
                }
                break;
            case 8: // Equal, param1 == param2
                param1 = fetch_param(cpu, mode_param1);
                param2 = fetch_param(cpu, mode_param2);
                if (param1 == param2) {
                    fetch_and_store_param(cpu, 1, mode_param3);
                } else {
                    fetch_and_store_param(cpu, 0, mode_param3);
                }
                break;
            case 9: // Set bp
                cpu.bp += fetch_param(cpu, mode_param1);
                break;
            case 99: // Halt
                cpu.state = CpuState::Halt;
                break;
            default:
                error = true;
        }

        if (error) {
            cpu.state = CpuState::Error;
        }

        if (cpu.pc == cpu.memory.size() && cpu.state != CpuState::Error && cpu.state != CpuState::Halt) {
            cpu.state = CpuState::Error;
        }
    }
}


// ----------------------------------------------------------------------------
// Day 17 - Part 1
// ----------------------------------------------------------------------------

struct State {
    vector<vector<int>> scaffold;
    vector<int> row;
};

char get(State &s, int x, int y) {
    if (x < 0 || x >= s.scaffold[0].size() || y < 0 || y >= s.scaffold.size()) {
        return ' ';
    } else {
        return s.scaffold[y][x];
    }
}

int main() {
    State s;

    IntCpu cpu;
    cpu.memory = program;
    cpu.input = [&](IntCpu &cpu) {
        return 0;
    };
    cpu.output = [&](IntCpu &cpu, int output) {
        if (output != 10) {
            s.row.push_back(output);
        } else if (!s.row.empty()) {
            s.scaffold.push_back(move(s.row));
        }
    };

    run_cpu(cpu);

    if (cpu.state == CpuState::Error) {
        throw runtime_error("Cpu error!");
    }

    for (auto &row : s.scaffold) {
        for (auto i : row) {
            cout << (char)i;
        }
        cout << endl;
    }

    int sum = 0;
    for (int y = 1; y < s.scaffold.size() - 1; y++) {
        for (int x = 1; x < s.scaffold[0].size() - 1; x++) {
            array<int, 5> v = {{
                get(s, x, y),
                get(s, x+1, y),
                get(s, x-1, y),
                get(s, x, y+1),
                get(s, x, y-1),
            }};
            if (v[0] == '#' && v[1] == '#' && v[2] == '#' &&v[3] == '#' &&v[4] == '#') {
                sum += x * y;
            }
        }
    }

    cout << "Result: " << sum << endl;

    return 0;
}
