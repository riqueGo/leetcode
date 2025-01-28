#include<iostream>
#include<vector>

using std::string;
using std::vector;

int main() {
    string s;
    int m, l, r;

    std::cin >> s >> m;

    vector<int> dp (s.length(), 0);

    for(int i = 1; i < s.length(); i++) {
        dp[i] = dp[i-1];

        if(s[i] == s[i-1]) dp[i] += 1;
    }

    for(int i = 0; i < m; i++) {
        std::cin >> l >> r;
        std::cout << dp[r-1] - dp[l-1] << std::endl;
    }
}