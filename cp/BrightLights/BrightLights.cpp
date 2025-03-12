#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::pair;

struct Pole {
    int x, y, h;
    double angle;
    
    Pole(int x, int y, int h) : x(x), y(y), h(h) {
        angle = atan2(y, x);
    }
};

bool compare(const Pole &a, const Pole &b) {
    if (a.angle != b.angle) return a.angle < b.angle; 
    return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
}

int main() {
    int n;
    while (std::cin >> n && n) {
        vector<Pole> buildings;

        for (int i = 0; i < n; i++) {
            int x, y, h;
            std::cin >> x >> y >> h;
            buildings.emplace_back(x, y, h);
        }

        sort(buildings.begin(), buildings.end(), compare);

        vector<pair<int, int>> shadowed;
        unordered_map<double, int> maxHeight;

        for (const auto &b : buildings) {
            if (maxHeight[b.angle] >= b.h) {
                shadowed.emplace_back(b.x, b.y);
            } else {
                maxHeight[b.angle] = b.h;
            }
        }

        if (shadowed.empty()) {
            std::cout << "All the lights are visible." << std::endl;
        } else {
            std::cout << "Some lights are not visible:" << std::endl;
            sort(shadowed.begin(), shadowed.end());
            for (size_t i = 0; i < shadowed.size(); i++) {
                std::cout << "x = " << shadowed[i].first << ", y = " << shadowed[i].second;
                std::cout << (i == shadowed.size() - 1 ? "." : ";") << std::endl;
            }
        }
    }
}
