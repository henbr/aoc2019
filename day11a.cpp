#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <limits>
#include <array>

using namespace std;


static vector<int64_t> program = {3,8,1005,8,337,1106,0,11,0,0,0,104,1,104,0,3,8,102,-1,8,10,101,1,10,10,4,10,1008,8,1,10,4,10,101,0,8,29,3,8,1002,8,-1,10,101,1,10,10,4,10,1008,8,0,10,4,10,102,1,8,51,1,1008,18,10,3,8,102,-1,8,10,1001,10,1,10,4,10,108,1,8,10,4,10,102,1,8,76,1006,0,55,1,1108,6,10,1,108,15,10,3,8,102,-1,8,10,1001,10,1,10,4,10,1008,8,1,10,4,10,101,0,8,110,2,1101,13,10,1,101,10,10,3,8,102,-1,8,10,1001,10,1,10,4,10,108,0,8,10,4,10,1001,8,0,139,1006,0,74,2,107,14,10,1,3,1,10,2,1104,19,10,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,1002,8,1,177,2,1108,18,10,2,1108,3,10,1,109,7,10,3,8,1002,8,-1,10,1001,10,1,10,4,10,108,0,8,10,4,10,101,0,8,210,1,1101,1,10,1,1007,14,10,2,1104,20,10,3,8,102,-1,8,10,1001,10,1,10,4,10,108,0,8,10,4,10,102,1,8,244,1,101,3,10,1006,0,31,1006,0,98,3,8,102,-1,8,10,1001,10,1,10,4,10,1008,8,1,10,4,10,1002,8,1,277,1006,0,96,3,8,1002,8,-1,10,101,1,10,10,4,10,1008,8,0,10,4,10,1002,8,1,302,1,3,6,10,1006,0,48,2,101,13,10,2,2,9,10,101,1,9,9,1007,9,1073,10,1005,10,15,99,109,659,104,0,104,1,21101,937108976384,0,1,21102,354,1,0,1105,1,458,21102,1,665750077852,1,21101,0,365,0,1105,1,458,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,21101,21478178856,0,1,21101,412,0,0,1105,1,458,21102,3425701031,1,1,21102,1,423,0,1106,0,458,3,10,104,0,104,0,3,10,104,0,104,0,21102,984458351460,1,1,21102,1,446,0,1105,1,458,21101,0,988220908388,1,21101,457,0,0,1105,1,458,99,109,2,22101,0,-1,1,21102,1,40,2,21101,489,0,3,21101,479,0,0,1105,1,522,109,-2,2106,0,0,0,1,0,0,1,109,2,3,10,204,-1,1001,484,485,500,4,0,1001,484,1,484,108,4,484,10,1006,10,516,1102,0,1,484,109,-2,2105,1,0,0,109,4,1201,-1,0,521,1207,-3,0,10,1006,10,539,21102,1,0,-3,21201,-3,0,1,21202,-2,1,2,21101,1,0,3,21101,558,0,0,1105,1,563,109,-4,2105,1,0,109,5,1207,-3,1,10,1006,10,586,2207,-4,-2,10,1006,10,586,22102,1,-4,-4,1106,0,654,21202,-4,1,1,21201,-3,-1,2,21202,-2,2,3,21102,1,605,0,1106,0,563,21201,1,0,-4,21102,1,1,-1,2207,-4,-2,10,1006,10,624,21102,1,0,-1,22202,-2,-1,-2,2107,0,-3,10,1006,10,646,22101,0,-1,1,21102,646,1,0,106,0,521,21202,-2,-1,-2,22201,-4,-2,-4,109,-5,2106,0,0};

// 0 = absolute address mode, 1 = immediate operand, 2 = relative address mode
constexpr int MODE_ADR = 0;
constexpr int MODE_IMM = 1;
constexpr int MODE_REL = 2;

enum class CpuState {
    Init,
    Running,
    Error,
    Halt,
    Input,
    Output
};

struct IntCpu {
    vector<int64_t> memory;
    int64_t output = 0;
    int64_t input = 0;
    int64_t input_address = 0;
    CpuState state = CpuState::Init;
    int64_t pc = 0;
    int64_t bp = 0;
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
    if (cpu.state == CpuState::Input) {
        store(cpu, cpu.input_address, cpu.input);
    }

    cpu.state = CpuState::Running;
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
                cpu.input_address = fetch(cpu);
                if (mode_param1 == MODE_REL) {
                    cpu.input_address += cpu.bp;
                }
                cpu.state = CpuState::Input;
                break;
            case 4: // Output
                param1 = fetch_param(cpu, mode_param1);
                cpu.output = param1;
                cpu.state = CpuState::Output;
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

constexpr int UNPAINTED = 3;
array<pair<int, int>, 4> DIRS = {{{0,-1}, {1, 0}, {0, 1}, {-1, 0}}};

struct RobotState {
    vector<vector<int>> hull;
    int x = 0;
    int y = 0;
    int dir = 0;
    bool paint = true;
};

void grow_hull(RobotState &rs) {
    int current_size = rs.hull.size();
    if (!(rs.hull.empty() || rs.x < 0 || rs.x >= current_size || rs.y < 0 || rs.y >= current_size)) {
        return;
    }

    int growth = 10;
    int new_size = current_size + growth * 2;
    vector<vector<int>> new_hull = vector<vector<int>>(new_size, vector<int>(new_size, UNPAINTED));

    for (int y0 = 0; y0 < current_size; y0++) {
        int y = y0 + growth;
        for (int x0 = 0; x0 < current_size; x0++) {
            int x = x0 + growth;
            new_hull[y][x] = rs.hull[y0][x0];
        }
    }

    rs.hull = move(new_hull);

    rs.x += growth;
    rs.y += growth;

    // Start at a painted tile
    if (current_size == 0) {
        rs.hull[rs.y][rs.x]= 1;
    }
}

int read_hull(RobotState &rs) {
    grow_hull(rs);
    int res = rs.hull[rs.y][rs.x];
    if (res == UNPAINTED) {
        res = 0;
    }
    return res;
}

void write_hull(RobotState &rs, int value) {
    grow_hull(rs);
    rs.hull[rs.y][rs.x]= value;
}

void turn_left(RobotState &rs) {
    rs.dir--;
    if (rs.dir < 0) {
        rs.dir = 3;
    }
}

void turn_right(RobotState &rs) {
    rs.dir++;
    if (rs.dir > 3) {
        rs.dir = 0;
    }
}

void step(RobotState &rs) {
    int xdir = DIRS[rs.dir].first;
    int ydir = DIRS[rs.dir].second;
    rs.x += xdir;
    rs.y += ydir;
}

int main() {
    RobotState rs;
    IntCpu cpu;
    cpu.memory = program;

    bool halt_detected = false;
    while(!halt_detected) {
        run_cpu(cpu);

        if (cpu.state == CpuState::Halt) {
            halt_detected = true;
            break;
        } else if (cpu.state == CpuState::Error) {
            throw runtime_error("Cpu error!");
        } else if (cpu.state == CpuState::Input) {
            cpu.input = read_hull(rs);
        } else if (cpu.state == CpuState::Output) {
            if (!(cpu.output == 1 || cpu.output == 0)) {
                throw runtime_error("Invalid output");
            }

            if (rs.paint) {
                write_hull(rs, cpu.output);
            } else {
                if (cpu.output == 0) {
                    turn_left(rs);
                } else {
                    turn_right(rs);
                }
                step(rs);
            }
            rs.paint = !rs.paint;
        }
    }

    int count = 0;
    for (auto &line : rs.hull) {
        for (auto v : line) {
            char c = '#';
            if (v != 1) {
                c = ' ';
            }

            if (v != UNPAINTED) {
                count++;
            }
            cout << c;
        }
        cout << endl;
    }
    cout << "Count: " << count << endl;

    return 0;
}
