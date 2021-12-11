#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>
#include <limits>
#include <array>
#include <stack>
#include <queue>

using namespace std;


static vector<int64_t> program = {3,1033,1008,1033,1,1032,1005,1032,31,1008,1033,2,1032,1005,1032,58,1008,1033,3,1032,1005,1032,81,1008,1033,4,1032,1005,1032,104,99,1001,1034,0,1039,1001,1036,0,1041,1001,1035,-1,1040,1008,1038,0,1043,102,-1,1043,1032,1,1037,1032,1042,1105,1,124,102,1,1034,1039,1001,1036,0,1041,1001,1035,1,1040,1008,1038,0,1043,1,1037,1038,1042,1106,0,124,1001,1034,-1,1039,1008,1036,0,1041,1001,1035,0,1040,101,0,1038,1043,101,0,1037,1042,1106,0,124,1001,1034,1,1039,1008,1036,0,1041,1002,1035,1,1040,102,1,1038,1043,1001,1037,0,1042,1006,1039,217,1006,1040,217,1008,1039,40,1032,1005,1032,217,1008,1040,40,1032,1005,1032,217,1008,1039,37,1032,1006,1032,165,1008,1040,5,1032,1006,1032,165,1102,1,2,1044,1105,1,224,2,1041,1043,1032,1006,1032,179,1102,1,1,1044,1106,0,224,1,1041,1043,1032,1006,1032,217,1,1042,1043,1032,1001,1032,-1,1032,1002,1032,39,1032,1,1032,1039,1032,101,-1,1032,1032,101,252,1032,211,1007,0,64,1044,1106,0,224,1101,0,0,1044,1105,1,224,1006,1044,247,1002,1039,1,1034,101,0,1040,1035,102,1,1041,1036,102,1,1043,1038,101,0,1042,1037,4,1044,1106,0,0,13,40,97,1,18,1,79,93,56,16,38,41,78,11,78,25,46,84,31,38,76,17,96,5,78,50,8,67,77,54,42,82,39,2,8,5,11,85,37,93,37,7,97,12,94,2,44,70,74,78,34,45,94,75,19,8,84,72,2,9,69,74,6,11,75,79,42,35,86,83,23,82,88,40,81,70,8,58,46,57,77,65,76,68,79,61,24,80,61,88,70,42,32,71,16,23,99,77,73,57,45,99,39,29,97,4,90,76,3,5,86,11,95,94,90,59,13,37,94,29,57,42,99,4,45,96,22,74,33,73,70,24,96,4,82,10,3,79,37,81,97,72,42,66,3,27,98,4,73,49,55,86,12,41,65,38,21,66,27,80,87,53,86,26,85,80,42,26,92,17,79,76,58,69,2,71,7,88,12,61,73,16,67,48,83,87,8,21,72,67,50,70,7,71,9,53,46,81,99,47,3,70,11,23,68,22,86,43,32,92,30,78,94,61,81,32,60,89,97,58,23,27,52,99,85,90,41,20,11,87,73,57,83,30,79,2,58,93,32,81,16,86,35,87,38,73,88,11,6,65,32,20,81,87,89,12,11,66,42,84,12,79,14,23,72,37,85,95,15,48,80,92,59,56,7,95,85,21,82,53,93,45,73,29,79,6,17,68,79,34,72,47,39,81,93,63,83,51,67,99,1,74,56,89,47,86,95,51,94,46,3,95,18,81,20,85,19,90,60,24,65,65,46,91,17,82,37,87,21,83,80,22,28,75,17,68,72,40,67,82,19,9,79,42,86,55,93,91,41,76,55,22,74,61,91,42,96,73,11,1,79,60,85,82,40,76,88,84,2,14,97,89,29,69,39,43,65,19,58,97,68,45,50,2,91,54,52,93,82,61,76,22,15,77,63,76,60,81,42,89,77,45,80,3,92,17,10,98,16,92,38,71,2,46,81,81,11,7,43,82,68,82,93,25,44,87,60,49,48,7,47,82,82,26,65,93,50,75,57,92,57,78,11,39,99,2,93,42,69,6,66,60,96,79,50,20,75,84,48,98,57,5,93,98,62,78,85,53,85,32,37,90,90,30,43,74,57,81,19,35,19,94,50,65,60,98,65,46,86,75,68,16,31,83,75,56,93,35,42,89,32,69,35,2,60,82,58,53,1,87,18,66,82,41,73,73,7,99,91,89,48,83,20,81,31,66,17,93,23,41,86,65,57,72,13,13,82,94,79,77,54,89,90,62,95,35,74,82,37,43,33,66,77,3,86,26,87,35,69,19,24,85,62,18,9,72,42,69,25,95,57,34,41,82,36,90,24,36,27,67,49,30,70,75,82,44,33,67,70,35,36,69,33,85,10,87,50,72,8,74,97,18,95,25,97,5,84,16,65,60,89,15,86,81,9,75,73,58,72,39,91,10,55,3,11,86,96,18,98,97,28,22,98,49,89,19,84,18,98,34,92,67,37,80,17,8,65,72,2,91,95,55,76,19,30,78,40,96,78,34,91,99,23,14,71,38,37,71,59,93,78,83,61,24,31,97,25,85,8,16,84,15,65,77,14,96,98,6,89,33,98,59,4,84,66,18,74,48,12,41,86,31,45,33,74,97,86,55,85,16,34,54,91,77,3,19,65,70,18,90,41,98,25,55,22,95,15,92,14,67,20,88,5,51,69,92,33,69,75,56,36,91,3,80,13,78,36,88,50,88,79,65,24,66,5,99,45,98,88,66,30,92,98,84,5,90,13,67,95,96,33,77,30,80,39,99,81,95,55,86,0,0,21,21,1,10,1,0,0,0,0,0,0};

// 0 = absolute address mode, 1 = immediate operand, 2 = relative address mode
constexpr int MODE_ADR = 0;
constexpr int MODE_IMM = 1;
constexpr int MODE_REL = 2;

enum class CpuState {
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
    CpuState state = CpuState::Running;
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


// ----------------------------------------------------------------------------
// Day 15 - Part 1
// ----------------------------------------------------------------------------

enum class Location {
    Unexplored,
    Wall,
    Floor,
    OxygenTank,
    Path,
    LastOxygen
};

enum class StateType {
    Exploring,
    FindingPath,
};

struct RobotState {
    vector<vector<Location>> ship;
    stack<int> exploreStack;
    StateType type = StateType::Exploring;
    int x = 0;
    int y = 0;
    int next_cmd = 1;
    int tankX = 0;
    int tankY = 0;
};


void show_ship(RobotState &rs) {
    int y = 0;
    for (auto &line : rs.ship) {
        int x = 0;
        for (auto v : line) {
            char c = 'X';
            switch(v) {
            case Location::Unexplored: c = ' '; break;
            case Location::Wall: c = '#'; break;
            case Location::Floor: c = '.'; break;
            case Location::OxygenTank: c = 'O'; break;
            case Location::Path: c = 'x'; break;
            case Location::LastOxygen: c = '@'; break;
            }

            if (x == rs.x && y == rs.y) {
                c = 'D';
            }

            cout << c;
            x++;
        }
        cout << endl;
        y++;
    }

    auto s = rs.exploreStack;
    int j = 0;
    while(!s.empty()) {
    //    cout << j << ": " << s.top() << endl;
        s.pop();
        j++;
    }

}

void grow_ship(RobotState &rs) {
    int current_size = rs.ship.size();
    if (!(rs.ship.empty() || rs.x < 0 || rs.x >= current_size || rs.y < 0 || rs.y >= current_size)) {
        return;
    }

    int growth = 10;
    int new_size = current_size + growth * 2;
    vector<vector<Location>> new_ship = vector<vector<Location>>(new_size, vector<Location>(new_size, Location::Unexplored));

    for (int y0 = 0; y0 < current_size; y0++) {
        int y = y0 + growth;
        for (int x0 = 0; x0 < current_size; x0++) {
            int x = x0 + growth;
            new_ship[y][x] = rs.ship[y0][x0];
        }
    }

    rs.ship = move(new_ship);

    rs.x += growth;
    rs.y += growth;
    rs.tankX += growth;
    rs.tankY += growth;
}

Location read_location(RobotState &rs) {
    grow_ship(rs);
    return rs.ship[rs.y][rs.x];
}

void write_location(RobotState &rs, Location value) {
    grow_ship(rs);

    if (rs.ship[rs.y][rs.x] != Location::Unexplored && rs.ship[rs.y][rs.x] != value) {
        throw runtime_error("Robot out of sync");
    } else {
        rs.ship[rs.y][rs.x] = value;
    }
}

int get_next_command(RobotState &rs) {
    return rs.next_cmd;
}

void update_position(RobotState &rs) {
    switch(rs.exploreStack.top()) {
    case 1: rs.y--; break;
    case 2: rs.y++; break;
    case 3: rs.x--; break;
    case 4: rs.x++; break;
    default: throw runtime_error("Invalid direction");
    }
    rs.next_cmd = rs.exploreStack.top();
}

void reverse_position(RobotState &rs) {
    switch(rs.exploreStack.top()-1) {
    case 1: rs.y++; rs.next_cmd = 2; break;
    case 2: rs.y--; rs.next_cmd = 1; break;
    case 3: rs.x++; rs.next_cmd = 4; break;
    case 4: rs.x--; rs.next_cmd = 3; break;
    default: throw runtime_error("Invalid direction");
    }
}

void explore(RobotState &rs, int reply) {
    switch(reply) {
    case 0:
        write_location(rs, Location::Wall);
        rs.exploreStack.pop();
        reverse_position(rs);
        break;
    case 1:
        write_location(rs, Location::Floor);
        break;
    case 2:
        write_location(rs, Location::OxygenTank);
        rs.tankX = rs.x;
        rs.tankY = rs.y;
        break;
    default: throw runtime_error("Invalid reply");
    }

    if (rs.exploreStack.empty()) {
        throw runtime_error("Stack is empty");
    }

    while(true) {
        if (rs.exploreStack.size() == 1 && rs.exploreStack.top() == 5) {
            rs.exploreStack.pop();
            break;
        } else if (rs.exploreStack.top() == 5) {
            rs.exploreStack.pop();
            reverse_position(rs);
            break;
        } else {
            update_position(rs);
            rs.exploreStack.top()++;
            rs.exploreStack.push(1);
            if (read_location(rs) != Location::Unexplored) {
                rs.exploreStack.pop();
                reverse_position(rs);
            } else {
                break;
            }
        }
    }

    if (rs.exploreStack.empty()) {
        rs.type = StateType::FindingPath;
    }
}

void accept_command(RobotState &rs, int cmd) {
    switch(rs.type) {
        case StateType::Exploring:
        explore(rs, cmd);
        break;
    case StateType::FindingPath:
        break;
    }
}


int get_offset(int x, int y) {
    return x + (y << 8);
}

pair<int, int> get_pos(int offset) {
    return pair(offset & 0xff, offset >> 8);
}

vector<int> reconstruct_path(int goal, int start, vector<int> came_from) {
    vector<int> visited;

    visited.push_back(goal);

    int current = goal;
    while(current != start) {
        int prev = came_from[current];
        visited.push_back(prev);
        current = prev;
    }

    vector<int> path;

    int prev = -1;
    for (auto itr = visited.rbegin(); itr != visited.rend(); itr++) {
        if (prev != -1) {
            auto ppos = get_pos(prev);
            auto cpos = get_pos(*itr);

            int dx = cpos.first - ppos.first;
            int dy = cpos.second - ppos.second;

            if (dx < 0) {
                path.push_back(3);
            } else if (dx > 0) {
                path.push_back(4);
            } else if (dy < 0) {
                path.push_back(1);
            } else {
                path.push_back(2);
            }
        }
        prev = *itr;
    }

    return path;
}

// https://en.wikipedia.org/wiki/A*_search_algorithm
vector<int> find_path(RobotState &rs) {
    auto size = 256 * 256;
    vector<int> came_from = vector<int>(size, -1);
    vector<int> scores = vector<int>(size, 1<<30);

    auto cmp_less = [&](int l, int r) {
        return scores[l] < scores[r];
    };
    vector<int> open;
    open.push_back(get_offset(rs.tankX, rs.tankY));
    scores[get_offset(rs.tankX, rs.tankY)] = 0;


    array<pair<int, int>, 4> dirs = {{{0,-1}, {0,1}, {-1,0}, {1,0}}};

    while(!open.empty()) {
        auto current_itr = open.begin();
        for (auto itr = open.begin(); itr != open.end(); itr++) {
            if (cmp_less(*itr, *current_itr)) {
                current_itr = itr;
            }
        }
        auto current = *current_itr;
        open.erase(current_itr);

        auto current_pos = get_pos(current);
        vector<int> neighbors;
        for (auto &dir : dirs) {
            int nx = current_pos.first + dir.first;
            int ny = current_pos.second + dir.second;

            if (nx < 0 || nx >= rs.ship.size() || ny < 0 || ny >= rs.ship.size()) {
                continue;
            }

            if (rs.ship[ny][nx] != Location::Wall) {
                neighbors.push_back(get_offset(nx, ny));
            }
        }

        for (auto n : neighbors) {
            int score = scores[current] + 1;
            if (score < scores[n]) {
                came_from[n] = current;
                scores[n] = score;

                bool found = false;
                for (int o : open) {
                    if (n == o) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    open.push_back(n);
                }
            }
        }
    }

    int highest_pos = get_offset(rs.tankX, rs.tankY);
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] > scores[highest_pos] && scores[i] < 1<<30) {
            highest_pos = i;
        }
    }

    return reconstruct_path(highest_pos, get_offset(rs.tankX, rs.tankY), came_from);
}

int main() {
    RobotState rs;
    rs.exploreStack.push(1);
    explore(rs, 1);

    IntCpu cpu;
    cpu.memory = program;

    bool halt_detected = false;
    while(cpu.state != CpuState::Halt && rs.type == StateType::Exploring) {
        run_cpu(cpu);
        if (cpu.state == CpuState::Error) {
            throw runtime_error("Cpu error!");
        } else if (cpu.state == CpuState::Input) {
            cpu.input = get_next_command(rs);
        } else if (cpu.state == CpuState::Output) {
            accept_command(rs, cpu.output);
        }
    }

    auto path = find_path(rs);

    int x = rs.tankX;
    int y = rs.tankY;
    for (auto d : path) {
        switch(d) {
        case 1: y--; break;
        case 2: y++; break;
        case 3: x--; break;
        case 4: x++; break;
        default: throw runtime_error("Invalid direction");
        }
        rs.ship[y][x] = Location::Path;
    }

    rs.ship[y][x] = Location::LastOxygen;

    show_ship(rs);

    cout << "Commands: " << path.size() << endl;

    return 0;
}
