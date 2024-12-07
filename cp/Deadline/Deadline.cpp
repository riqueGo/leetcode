#include<iostream>
#include<cmath>

void solve() {
    double n, d, a, stop;
    std::cin >> n >> d;
    stop = d;

    if (d <= n) {
        std::cout << "YES" << std::endl;
        return;
    }

    for(long long x = 1; x <= n; x++){
        a = std::ceil(x + d/(x+1));

        if(a <= n) {
            std::cout << "YES" << std::endl;
            return;
        } else if (a <= stop) {
            stop = a;
        } else {
            break;
        }
    }

    std::cout << "NO" << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }
}