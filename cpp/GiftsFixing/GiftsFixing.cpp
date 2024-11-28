#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>

using std::vector;

void solve() {
    int n, m, tmp, minA = INT_MAX, minB = INT_MAX;
    std::cin >> n;
    vector<int> as(n), bs(n);



    for(int i = 0; i < n; i++) {
        std::cin >> tmp;
        if(tmp < minA) {
            minA = tmp;
        }
        as[i] = tmp;
    }

    for(int i = 0; i < n; i++) {
        std::cin >> tmp;
        if(tmp < minB) {
            minB = tmp;
        }
        bs[i] = tmp;
    }

    int aiResult, biResult;
    long long moves = 0;

    for(int i = 0; i < n; i++) {
        aiResult = std::abs(as[i]-minA);
        biResult = std::abs(bs[i]-minB);
        moves += std::min(aiResult, biResult) + std::abs(aiResult - biResult); 
    }
    std::cout << moves << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        solve();
    }
}