#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Moon {
    int x;
    int y;
    int z;
    int vx = 0;
    int vy = 0;
    int vz = 0;
    Moon(int x, int y, int z) : x(x), y(y), z(z) {}
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

Moon update_velocity(Moon moon, Moon &other) {
    moon.vx += calculate_velocity(moon.x, other.x);
    moon.vy += calculate_velocity(moon.y, other.y);
    moon.vz += calculate_velocity(moon.z, other.z);
    return moon;
}

Moon update_position(Moon moon) {
    moon.x += moon.vx;
    moon.y += moon.vy;
    moon.z += moon.vz;
    return moon;
}

void print_coords(const string &name, int x, int y, int z) {
    cout << name << "=<"
         << "x=" << setw(3) << x << ","
         << "y=" << setw(3) << y << ","
         << "z=" << setw(3) << z
         << ">";
}

void print_moon(const Moon &moon) {
    print_coords("pos", moon.x, moon.y, moon.z);
    cout << ", ";
    print_coords("vel", moon.vx, moon.vy, moon.vz);
    cout << endl;
}

void print_moons(const vector<Moon> &moons, int steps) {
    cout << "After " << steps << " steps:" << endl;
    for (auto &moon : moons) {
        print_moon(moon);
    }
}

int calculate_energy(const vector<Moon> &moons) {
    int total_energy = 0;

    for (auto &moon : moons) {
        int pot = abs(moon.x) + abs(moon.y) + abs(moon.z);
        int kin = abs(moon.vx) + abs(moon.vy) + abs(moon.vz);
        total_energy += (pot * kin);
    }

    return total_energy;
}


vector<Moon> moons = {Moon(-4, -14, 8),
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
constexpr int NUM_STEPS = 1000;

int main() {

    print_moons(moons, 0);
    for (int i = 1; i <= NUM_STEPS; i++) {
        for (auto &moon : moons) {
            for (auto &other : moons) {
                if (&moon == &other) {
                    continue;
                }
                moon = update_velocity(moon, other);
            }
        }

        for (auto &moon : moons) {
            moon = update_position(moon);
        }

        print_moons(moons, i);
    }

    cout << "Total energy after " << NUM_STEPS << " steps: "  << calculate_energy(moons) << endl;
}
