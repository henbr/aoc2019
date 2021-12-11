#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <optional>

using namespace std;

constexpr int INPUT_START = 356261;
constexpr int INPUT_END = 846303;

int get_digit(int digit_place, int num) {
    int mult = 1;
    while(digit_place--) {
        mult *= 10;
    }
    return (num / mult) % 10;
}

bool is_six_digit(int num) {
    return num >= 100000 && num <= 999999;
}

bool is_within_range(int num) {
    return num >= INPUT_START && num <= INPUT_END;
}

bool has_double_digits(int num) {
    int prev = get_digit(0, num);
    for (int i = 1; i < 6; i++) {
        int cur = get_digit(i, num);
        if (cur == prev) {
            return true;
        }
        prev = cur;
    }

    return false;
}

bool is_not_decreasing(int num) {
    int prev = get_digit(0, num);
    for (int i = 1; i < 6; i++) {
        int cur = get_digit(i, num);
        if (cur > prev) {
            return false;
        }
        prev = cur;
    }
    return true;
}

bool is_number_ok(int num) {
  //  bool c1 = is_six_digit(num);
  //  bool c2 = is_within_range(num);
    bool c3 = has_double_digits(num);
    bool c4 = is_not_decreasing(num);

    return /*c1 && c2 &&*/ c3 && c4;
}

int main() {
    if (is_number_ok(356667)) {
        cout << "ok\n";
    } else {
        cout << "not ok\n";
    }



    int res = 0;
    for (int i = INPUT_START; i < INPUT_END; i++) {
        if (is_number_ok(i)) {
            cout << i << " ok\n";
        } else {
            cout << i << " not ok\n";
        }
        if (is_number_ok(i)) {
            cout << i << endl;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}