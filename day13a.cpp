#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <limits>
#include <array>

using namespace std;


static vector<int64_t> program = {1,380,379,385,1008,2151,871073,381,1005,381,12,99,109,2152,1102,1,0,383,1101,0,0,382,21001,382,0,1,20102,1,383,2,21102,37,1,0,1106,0,578,4,382,4,383,204,1,1001,382,1,382,1007,382,36,381,1005,381,22,1001,383,1,383,1007,383,21,381,1005,381,18,1006,385,69,99,104,-1,104,0,4,386,3,384,1007,384,0,381,1005,381,94,107,0,384,381,1005,381,108,1106,0,161,107,1,392,381,1006,381,161,1102,1,-1,384,1106,0,119,1007,392,34,381,1006,381,161,1101,0,1,384,21002,392,1,1,21102,1,19,2,21102,0,1,3,21102,1,138,0,1106,0,549,1,392,384,392,20101,0,392,1,21102,19,1,2,21102,3,1,3,21101,161,0,0,1106,0,549,1101,0,0,384,20001,388,390,1,21001,389,0,2,21102,1,180,0,1105,1,578,1206,1,213,1208,1,2,381,1006,381,205,20001,388,390,1,20101,0,389,2,21102,205,1,0,1105,1,393,1002,390,-1,390,1101,1,0,384,20102,1,388,1,20001,389,391,2,21101,228,0,0,1105,1,578,1206,1,261,1208,1,2,381,1006,381,253,21002,388,1,1,20001,389,391,2,21101,0,253,0,1105,1,393,1002,391,-1,391,1101,1,0,384,1005,384,161,20001,388,390,1,20001,389,391,2,21102,1,279,0,1105,1,578,1206,1,316,1208,1,2,381,1006,381,304,20001,388,390,1,20001,389,391,2,21102,304,1,0,1105,1,393,1002,390,-1,390,1002,391,-1,391,1102,1,1,384,1005,384,161,21002,388,1,1,20101,0,389,2,21102,0,1,3,21101,338,0,0,1106,0,549,1,388,390,388,1,389,391,389,21001,388,0,1,20102,1,389,2,21101,0,4,3,21102,1,365,0,1105,1,549,1007,389,20,381,1005,381,75,104,-1,104,0,104,0,99,0,1,0,0,0,0,0,0,180,16,16,1,1,18,109,3,22101,0,-2,1,21201,-1,0,2,21102,1,0,3,21101,414,0,0,1105,1,549,22102,1,-2,1,21201,-1,0,2,21102,429,1,0,1106,0,601,1202,1,1,435,1,386,0,386,104,-1,104,0,4,386,1001,387,-1,387,1005,387,451,99,109,-3,2105,1,0,109,8,22202,-7,-6,-3,22201,-3,-5,-3,21202,-4,64,-2,2207,-3,-2,381,1005,381,492,21202,-2,-1,-1,22201,-3,-1,-3,2207,-3,-2,381,1006,381,481,21202,-4,8,-2,2207,-3,-2,381,1005,381,518,21202,-2,-1,-1,22201,-3,-1,-3,2207,-3,-2,381,1006,381,507,2207,-3,-4,381,1005,381,540,21202,-4,-1,-1,22201,-3,-1,-3,2207,-3,-4,381,1006,381,529,22101,0,-3,-7,109,-8,2106,0,0,109,4,1202,-2,36,566,201,-3,566,566,101,639,566,566,1201,-1,0,0,204,-3,204,-2,204,-1,109,-4,2106,0,0,109,3,1202,-1,36,593,201,-2,593,593,101,639,593,593,21001,0,0,-2,109,-3,2105,1,0,109,3,22102,21,-2,1,22201,1,-1,1,21101,383,0,2,21101,0,250,3,21101,756,0,4,21101,630,0,0,1106,0,456,21201,1,1395,-2,109,-3,2105,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,2,2,0,2,0,0,0,0,0,0,2,2,0,2,2,0,2,2,0,0,2,2,2,0,0,0,0,2,2,2,0,1,1,0,0,0,0,2,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,2,0,2,0,2,2,2,2,0,2,0,0,0,1,1,0,0,2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,2,2,0,2,0,0,1,1,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,0,0,0,0,2,2,2,0,2,0,1,1,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,2,0,0,0,2,2,0,0,0,2,0,0,0,2,0,2,2,2,0,1,1,0,0,0,0,2,2,2,2,2,0,2,0,0,0,0,2,0,2,0,2,0,2,0,0,2,2,0,2,0,2,0,2,0,0,1,1,0,2,2,0,2,2,2,2,0,2,2,2,2,0,0,2,0,0,2,0,2,0,0,0,2,0,0,2,2,2,0,0,0,0,1,1,0,0,2,0,0,2,2,0,0,0,0,2,2,0,0,2,0,0,0,2,2,0,2,0,2,2,0,2,2,0,0,0,2,0,1,1,0,0,0,0,0,0,0,2,0,0,0,2,0,2,0,0,0,2,2,2,2,0,2,2,0,2,2,0,0,0,2,0,0,0,1,1,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,2,0,2,0,0,0,0,2,2,0,2,2,2,0,0,2,0,2,0,1,1,0,0,0,0,2,2,0,2,2,0,2,0,2,2,2,0,0,2,2,0,0,0,0,0,0,2,0,2,2,2,0,2,2,0,1,1,0,2,0,0,2,0,0,0,0,0,2,0,0,2,2,0,2,2,2,0,2,2,0,0,2,2,0,0,2,2,0,0,2,0,1,1,0,2,0,2,0,2,0,2,0,0,2,2,0,0,2,0,0,0,2,0,2,2,0,2,0,0,0,2,0,2,2,0,2,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,52,20,53,45,54,10,5,35,28,96,68,78,29,94,94,57,42,27,61,91,60,22,54,59,33,71,63,62,97,30,76,40,87,10,30,83,68,41,63,55,24,65,56,57,21,91,17,7,60,94,34,54,75,10,16,88,32,34,41,36,57,39,14,89,23,47,7,94,89,60,56,36,44,77,29,17,93,55,58,62,61,18,50,54,22,75,45,1,29,64,32,97,98,50,37,64,39,61,23,39,61,85,85,10,37,56,84,13,43,91,20,73,77,34,87,33,36,42,48,3,39,6,18,58,38,63,48,38,96,32,72,51,22,37,76,4,95,17,3,79,89,19,12,22,71,98,95,22,82,31,70,98,48,46,6,80,95,98,1,81,27,91,14,98,13,46,21,6,75,59,73,9,52,6,44,92,9,11,65,71,19,52,84,71,38,60,43,10,78,25,22,27,90,4,23,96,19,42,54,80,63,64,26,29,58,75,35,95,38,48,1,47,61,20,74,39,85,33,10,70,90,39,93,61,9,65,19,56,84,59,57,30,76,19,52,66,89,93,19,86,4,67,59,37,28,71,1,21,40,18,92,72,57,63,88,42,17,92,42,88,93,17,19,26,63,31,1,8,76,62,31,49,36,18,19,63,50,50,13,77,22,45,11,92,7,92,69,66,49,34,2,58,61,4,18,26,20,7,51,84,81,38,72,22,83,92,16,97,20,81,25,74,13,84,71,2,81,35,83,6,73,93,60,47,2,98,27,55,68,59,67,63,61,48,65,28,71,56,39,30,93,96,3,47,93,77,11,28,86,79,90,83,39,21,68,2,49,50,78,68,81,97,49,9,44,79,31,69,81,76,93,17,31,66,46,26,18,1,17,72,1,28,47,15,85,50,95,75,52,86,5,35,59,51,41,88,33,9,7,77,1,46,6,40,39,36,52,10,12,34,87,64,13,23,96,15,89,13,64,65,29,27,28,50,57,91,68,97,5,38,57,28,45,6,10,90,7,26,79,89,93,74,77,58,51,86,75,49,80,80,28,94,11,56,36,69,88,50,10,22,77,51,83,47,53,2,46,33,45,44,23,4,28,62,21,88,61,58,72,16,4,6,47,25,37,46,72,65,74,9,69,60,62,39,82,63,17,4,79,43,68,80,17,20,20,49,59,70,5,3,69,44,95,38,90,11,98,76,36,59,80,74,85,1,46,19,97,14,89,96,14,65,68,13,90,13,46,24,39,63,73,84,46,66,92,84,56,86,44,33,23,6,91,13,25,75,76,31,68,4,40,83,51,85,70,84,27,71,40,53,75,59,77,79,98,90,33,94,63,19,65,44,90,18,71,17,72,40,32,16,43,16,55,28,93,76,68,40,25,1,11,79,42,49,46,80,14,41,75,10,84,67,94,91,83,51,41,78,57,75,10,71,33,47,69,34,5,81,26,82,39,51,55,38,23,2,87,54,45,3,34,44,65,54,5,74,3,51,18,42,37,52,20,57,80,66,91,66,62,38,56,36,77,18,27,55,97,43,53,25,92,14,55,87,91,81,33,65,12,18,76,21,77,90,40,35,36,30,87,32,12,86,10,93,49,12,25,44,15,37,11,57,2,2,16,21,58,35,77,26,15,86,49,62,57,90,8,10,81,35,85,25,76,76,61,40,69,9,34,59,29,16,71,41,61,87,62,17,37,51,14,59,67,66,65,87,4,85,82,98,48,17,9,92,12,71,871073};

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

constexpr int UNPAINTED = -1;

enum class OutputState {
    XPos,
    YPos,
    Type
};

array<OutputState, 3> output_states = {{OutputState::XPos, OutputState::YPos, OutputState::Type}};

struct ArcadeState {
    vector<vector<int>> board;
    int output_state = 0;
    int x = 0;
    int y = 0;
    int type = 0;
};

void grow_board(ArcadeState &as) {
    int current_size = as.board.size();
    if (!(as.board.empty() || as.x >= current_size || as.y >= current_size)) {
        return;
    }

    int growth = 10;
    int new_size = current_size + growth * 2;
    vector<vector<int>> new_board = vector<vector<int>>(new_size, vector<int>(new_size, UNPAINTED));

    for (int y0 = 0; y0 < current_size; y0++) {
        int y = y0; //+ growth;
        for (int x0 = 0; x0 < current_size; x0++) {
            int x = x0;// + growth;
            new_board[y][x] = as.board[y0][x0];
        }
    }

    as.board = move(new_board);

    grow_board(as);
}

void write_board(ArcadeState &as) {
    grow_board(as);
    as.board[as.y][as.x]= as.type;
}


int main() {
    ArcadeState as;
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
            throw runtime_error("Input?");
        } else if (cpu.state == CpuState::Output) {
            switch(output_states[as.output_state]) {
            case OutputState::XPos:
                as.x = cpu.output;
                break;
            case OutputState::YPos:
                as.y = cpu.output;
                break;
            case OutputState::Type:
                as.type = cpu.output;
                write_board(as);
                break;
            }
            as.output_state = (as.output_state + 1) % output_states.size();
        }
    }

    int count = 0;
    for (auto &line : as.board) {
        for (auto v : line) {
            char c = ' ';
            switch(v) {
            case 0: c = ' '; break;
            case 1: c = '|'; break;
            case 2: c = '#'; count++; break;
            case 3: c = '_'; break;
            case 4: c = 'o'; break;
            default: c = '.'; break;
            }
            cout << c;
        }
        cout << endl;
    }
    cout << "Count: " << count << endl;

    return 0;
}