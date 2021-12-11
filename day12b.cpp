#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <unordered_set>
#include <numeric>

using namespace std;

struct Moon {
    int x, y, z;
    Moon(int x, int y, int z) : x(x), y(y), z(z) {}
};

struct Dim {
    vector<int> pos;
    vector<int> vel;

    bool operator==(const Dim &other) const {
        for (int i = 0; i < pos.size(); i++) {
            if (pos[i] != other.pos[i] || vel[i] != other.vel[i]) {
                return false;
            }
        }
        return true;
    }
};

namespace std {

  template <>
  struct hash<Dim> {
    size_t operator()(const Dim& d) const {
        size_t hash = 0;
        for (int i = 0; i < d.pos.size(); i++) {
            hash = ((hash << 1) ^ d.pos[i]) >> 1;
            hash = ((hash << 1) ^ d.vel[i]) >> 1;
        }
        return hash;
    }
  };
};

struct DimRepeat {
    Dim d;
    bool found = false;
    uint64_t repeat = 0;
    unordered_set<Dim> dimset;
};

int calculate_velocity(int pos, int other_pos) {
    if (pos < other_pos) {
        return 1;
    } else if (pos > other_pos) {
        return -1;
    } else {
        return 0;
    }
}

void update_velocity(Dim &d) {
    for (auto i = 0U; i < d.pos.size(); i++) {
        for (auto j = 0U; j < d.pos.size(); j++) {
            d.vel[i] += calculate_velocity(d.pos[i], d.pos[j]);
        }
    }
}

void update_position(Dim &d) {
    for (auto i = 0U; i < d.pos.size(); i++) {
        d.pos[i] += d.vel[i];
    }
}

void update_repeat(DimRepeat &dr) {
    if (!dr.found) {
        auto res = dr.dimset.insert(dr.d);
        if (!res.second) {
            dr.found = true;
        } else {
            dr.repeat++;
        }
    }
}



static vector<Moon> moons = {Moon(-4, -14, 8),
                      Moon(1, -8, 10),
                      Moon(-15, 2, 1),
                      Moon(-17, -17, 16)};


/*
static vector<Moon> moons = {Moon(-1, 0, 2),
                             Moon(2, -10, -7),
                             Moon(4, -8, 8),
                             Moon(3, 5, -1)};

*/
/*

static vector<Moon> moons = {Moon(-8, -10, 0),
                             Moon(5, 5, 10),
                             Moon(2, -7, 3),
                             Moon(9, -8, -3)};
*/


int main() {
    DimRepeat x, y, z;

    for (auto &moon : moons) {
        x.d.pos.push_back(moon.x);
        y.d.pos.push_back(moon.y);
        z.d.pos.push_back(moon.z);
        x.d.vel.push_back(0);
        y.d.vel.push_back(0);
        z.d.vel.push_back(0);
    }

    while (!x.found || !y.found || !z.found) {
        update_velocity(x.d);
        update_velocity(y.d);
        update_velocity(z.d);
        update_position(x.d);
        update_position(y.d);
        update_position(z.d);
        update_repeat(x);
        update_repeat(y);
        update_repeat(z);
    }

    uint64_t res = lcm(x.repeat, lcm(y.repeat, z.repeat));

    cout << "Result: " << res << endl;
}
