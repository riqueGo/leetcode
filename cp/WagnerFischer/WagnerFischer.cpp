#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::min;

int wagnerFischer(const string &a, const string &b) {
    int m = a.length();
    int n = b.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    int t;
    string a, b;

    std::cin >> t;
    std::getline(std::cin, a);

    for(int i = 0; i < t; i++) {
        std::getline(std::cin, a);
        std::getline(std::cin, b);
        std::cout << wagnerFischer(a, b) << std::endl;
    }
}