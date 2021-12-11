#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;



vector<string> input = {
    /*".#....#####...#..",
    "##...##.#####..##",
    "##...#...#.#####.",
    "..#.....#...###..",
    "..#.#.....#....##",*/



    "##.###.#.......#.#....#....#..........#.",
    "....#..#..#.....#.##.............#......",
    "...#.#..###..#..#.....#........#......#.",
    "#......#.....#.##.#.##.##...#...#......#",
    ".............#....#.....#.#......#.#....",
    "..##.....#..#..#.#.#....##.......#.....#",
    ".#........#...#...#.#.....#.....#.#..#.#",
    "...#...........#....#..#.#..#...##.#.#..",
    "#.##.#.#...#..#...........#..........#..",
    "........#.#..#..##.#.##......##.........",
    "................#.##.#....##.......#....",
    "#............#.........###...#...#.....#",
    "#....#..#....##.#....#...#.....#......#.",
    ".........#...#.#....#.#.....#...#...#...",
    ".............###.....#.#...##...........",
    "...#...#.......#....#.#...#....#...#....",
    ".....#..#...#.#.........##....#...#.....",
    "....##.........#......#...#...#....#..#.",
    "#...#..#..#.#...##.#..#.............#.##",
    ".....#...##..#....#.#.##..##.....#....#.",
    "..#....#..#........#.#.......#.##..###..",
    "...#....#..#.#.#........##..#..#..##....",
    ".......#.##.....#.#.....#...#...........",
    "........#.......#.#...........#..###..##",
    "...#.....#..#.#.......##.###.###...#....",
    "...............#..#....#.#....#....#.#..",
    "#......#...#.....#.#........##.##.#.....",
    "###.......#............#....#..#.#......",
    "..###.#.#....##..#.......#.............#",
    "##.#.#...#.#..........##.#..#...##......",
    "..#......#..........#.#..#....##........",
    "......##.##.#....#....#..........#...#..",
    "#.#..#..#.#...........#..#.......#..#.#.",
    "#.....#.#.........#............#.#..##.#",
    ".....##....#.##....#.....#..##....#..#..",
    ".#.......#......#.......#....#....#..#..",
    "...#........#.#.##..#.#..#..#........#..",
    "#........#.#......#..###....##..#......#",
    "...#....#...#.....#.....#.##.#..#...#...",
    "#.#.....##....#...........#.....#...#...",


};

struct Point {
    int x = 0;
    int y = 0;
    int divisor = -1;
};

vector<vector<Point>> lookup = vector<vector<Point>>(input.size(), vector<Point>(input[0].length()));



void init_lookup() {
    for (int y = 0; y < lookup.size(); y++) {
        for (int x = 0; x < lookup[0].size(); x++) {
           int divisor = gcd(x, y);
           if (divisor != 0) {
               lookup[y][x].divisor = divisor;
               lookup[y][x].x = x / divisor;
               lookup[y][x].y = y / divisor;
           } else {
               lookup[y][x].divisor = 0;
           }
        }
    }
}

const Point get_gcd(int x, int y) {
    const int ax = abs(x);
    const int ay = abs(y);


    auto res = lookup[ay][ax];

    res.x = x < 0 ? res.x * -1 : res.x;
    res.y = y < 0 ? res.y * -1 : res.y;

    return res;
}

vector<Point> get_visible_asteroids(int xpos, int ypos) {
    vector<vector<Point>> vis = vector<vector<Point>>(input.size(), vector<Point>(input[0].length()));
    vector<Point> visible;


    for (int y = 0; y < input.size(); y++) {
        for (int x = 0; x < input[0].length(); x++) {
            if (input[y][x] == '.') {
                continue;
            }

            if (x == xpos && y == ypos) {
                continue;
            }

            const int dx = x - xpos;
            const int dy = y - ypos;
            const auto dgcd = get_gcd(dx, dy);

            int vx = xpos + dgcd.x;
            int vy = ypos + dgcd.y;

            if (vis[vy][vx].divisor == -1 || vis[vy][vx].divisor > dgcd.divisor) {
                vis[vy][vx] = dgcd;
            }
        }
    }

    for (int y = 0; y < input.size(); y++) {
        for (int x = 0; x < input[0].length(); x++) {
            if (vis[y][x].divisor != -1) {
                Point p;
                p.x = xpos + vis[y][x].x * vis[y][x].divisor;
                p.y = ypos + vis[y][x].y * vis[y][x].divisor;
                p.divisor = vis[y][x].divisor;
                visible.push_back(p);
            }
        }
    }

    return visible;
}

double pointToDegrees(double x, double y) {
    return -(-180+atan2(x,y) / M_PI * 180);
}

constexpr int X = 31;
constexpr int Y = 20;

int main() {
    init_lookup();


    input[Y][X] = 'X';
    vector<Point> visible;
    while(true) {
        auto tmp = get_visible_asteroids(X,Y);
        if (tmp.empty()) {
            break;
        }
        sort(tmp.begin(), tmp.end(), [](const auto &a, const auto &b) {
            return pointToDegrees(a.x-X, a.y-Y) < pointToDegrees(b.x-X, b.y-Y);
        });
        for (auto &p : tmp) {
            input[p.y][p.x] = '.';
            visible.push_back(p);
        }
    }

    int c = 0;
    for (auto p : visible) {

        if (c < 9) {
            input[p.y][p.x] = '1' + c;

        } else {
            input[p.y][p.x] = 'x';
        }

   //     cout << p.x << ", " << p.y << ", " <<  pointToDegrees(p.x-X, p.y-Y)  << endl;
        c++;

    }

    for (auto i : input) {
        cout << i << endl;
    }

    cout << visible[199].x << ", " << visible[199].y << endl;



    return 0;
}
