#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <math.h>

using namespace std;


static array<int, 4> pattern = {{0, 1, 0, -1}};

static string input = "59790677903322930697358770979456996712973859451709720515074487141246507419590039598329735611909754526681279087091321241889537569965210074382210124927546962637736867742660227796566466871680580005288100192670887174084077574258206307557682549836795598410624042549261801689113559881008629752048213862796556156681802163843211546443228186862314896620419832148583664829023116082772951046466358463667825025457939806789469683866009241229487708732435909544650428069263180522263909211986231581228330456441451927777125388590197170653962842083186914721611560451459928418815254443773460832555717155899456905676980728095392900218760297612453568324542692109397431554";

int get_pattern_num(int index, int output_index) {
    return pattern[((index + 1) / (output_index + 1)) % pattern.size()];
}


string fft_phase(const string &in) {
    string out;

    for (int output_pos = 0; output_pos < in.size(); output_pos++) {
        int res = 0;
        for (int i = 0; i < in.size(); i++) {
            int num = in[i] - '0';
            res += num * get_pattern_num(i, output_pos);
        }
        res = abs(res) % 10;
        out.push_back('0' + res);
    }

    return out;
}

int main() {
    auto res = input;

    for (int i = 0; i < 100; i++) {
        res = fft_phase(res);
    }

    res = res.substr(0, 8);

    cout << res << endl;

    return 1;
}
