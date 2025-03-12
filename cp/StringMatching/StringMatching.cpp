#include <iostream>
#include <vector>

using std::vector;
using std::string;

vector<int> buildLPS(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int l = 0;

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[l]) {
            l++;
            lps[i] = l;
            i++;
        } else {
            if (l != 0) {
                l = lps[l - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmpSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = buildLPS(pattern);
    int matches = 0;

    int i = 0;
    int j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            matches++;
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return matches;
}

int main() {
    string s1, s2;
    std::cin >> s1 >> s2;
    std::cout << kmpSearch(s1, s2) << std::endl;
}
