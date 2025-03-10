#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

string longestCommonSubstring(const string &s1, const string &s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0, endIndex = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }
    
    return s1.substr(endIndex - maxLength + 1, maxLength);
}

int main() {
    string s1 = "abcdef";
    string s2 = "zbcdf";
    
    string result = longestCommonSubstring(s1, s2);
    std::cout << "Longest Common Substring: " << result << std::endl;
}