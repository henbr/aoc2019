#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <math.h>
#include <fstream>
#include <algorithm>

using namespace std;

static string input = "59790677903322930697358770979456996712973859451709720515074487141246507419590039598329735611909754526681279087091321241889537569965210074382210124927546962637736867742660227796566466871680580005288100192670887174084077574258206307557682549836795598410624042549261801689113559881008629752048213862796556156681802163843211546443228186862314896620419832148583664829023116082772951046466358463667825025457939806789469683866009241229487708732435909544650428069263180522263909211986231581228330456441451927777125388590197170653962842083186914721611560451459928418815254443773460832555717155899456905676980728095392900218760297612453568324542692109397431554";

//static string input = "80871224585914546619083218645595";
                     //10201020
//static string input = "12345678";

//static string input = "03036732577212944063491565474664";


struct Interval {
    int start = 0;
    int sum = 0;
    int offset = 0;
};

Interval inc_interval(const string &signal, const Interval &old, int len, int new_len) {
    Interval ni = old;
    ni.start = ni.offset * new_len - 1;

    if (ni.start >= signal.size()) {
        return ni;
    }

    int signal_size = signal.size();
    int mult = ni.offset % 2 == 0 ? 1 : -1;
    int old_end = min(signal_size, old.start + len);
    for (int i = old.start; i < old_end && i < ni.start; i++) {
        ni.sum -= (signal[i] - '0') * mult;
    }

    int start = max(ni.start, old_end);
    int end = min(signal_size, ni.start + new_len);
    for (int i = start; i < end; i++) {
        ni.sum += (signal[i] - '0') * mult;
    }

    return ni;
}

string fft_phase(const string &in, int output_start) {
    auto size = in.size();
    string res(in.size(), '0');

    int offset = 0;
    vector<Interval> intervals;
    while(true) {
        Interval i;
        i.start = offset;
        i.sum = 0;
        i.offset = offset + 1;
        offset += 2;
        i = inc_interval(in, i, 1, output_start+1);
        intervals.push_back(i);
        if (i.start >= size) {
            break;
        }
    }

    int len = output_start+1;
    for (int out = output_start; out < size; out++) {
        int sum = 0;
        for (auto &i : intervals) {
            if (i.start >= size) {
                break;
            }

            sum += i.sum;
            i = inc_interval(in, i, len, len+1);
        }
        res[out] = abs(sum) % 10 + '0';
        len++;
    }

    return res;
}

int main() {
    int offset = 0;
    for (int i = 0; i < 7; i ++) {
        offset *= 10;
        offset += (input[i] - '0') % 10;
    }

    string res;

    for (int i = 0; i < 10000; i++) {
        res.append(input);
    }

    for (int i = 0; i < 100; i++) {
        res = fft_phase(res, offset);
    }

    res = res.substr(offset, 8);

    cout << res << endl;
    return 1;
}
