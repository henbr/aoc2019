#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <optional>

using namespace std;

vector<int> program = {1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,1,5,19,23,1,23,5,27,1,27,13,31,1,31,5,35,1,9,35,39,2,13,39,43,1,43,10,47,1,47,13,51,2,10,51,55,1,55,5,59,1,59,5,63,1,63,13,67,1,13,67,71,1,71,10,75,1,6,75,79,1,6,79,83,2,10,83,87,1,87,5,91,1,5,91,95,2,95,10,99,1,9,99,103,1,103,13,107,2,10,107,111,2,13,111,115,1,6,115,119,1,119,10,123,2,9,123,127,2,127,9,131,1,131,10,135,1,135,2,139,1,10,139,0,99,2,0,14,0};


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

int run_program(int noun, int verb, vector<int> mem) {
    mem[1] = noun;
    mem[2] = verb;

    auto itr = mem.begin();
    bool error = false;

    while(itr != mem.end() && !error) {
        int opcode = fetch(itr, mem.end(), error);

        if (opcode == 99) {
            break;
        }

        int in_addr1 = fetch(itr, mem.end(), error);
        int in_addr2 = fetch(itr, mem.end(), error);
        int out_addr = fetch(itr, mem.end(), error);
        
        int res = 0;
        switch(opcode) {
            case 1:
                res = read(in_addr1, mem, error) + read(in_addr2, mem, error);
                break;
            case 2:
                res = read(in_addr1, mem, error) * read(in_addr2, mem, error);
                break;
            default:
                error = true;
            }

         if (error) {
             break;
         } 
         
         store(out_addr, res, mem, error);
    }

    return mem[0];
}

int main() {
    int noun = 0;
    int verb = 0;
    
    while(verb != 100) {
        int res = run_program(noun, verb, program);
        if (res == 19690720) {
            break;
        
        }
        noun++;
        if (noun == 100) {
            noun = 0;
            verb++;
        }
    }

    if (verb == 100) {
        cout << "nothing found\n";
    } else {
        cout << "noun: " << noun << ", verb: " << verb << endl;
    }


    return 0;
}
