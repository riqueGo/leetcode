#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

class Solution {
private:
    int _nPairs;
    vector<string> _result;

    void generate(int open, int close, string str) {
        if (open == _nPairs && close == _nPairs) {
            _result.push_back(str);
            return;
        }
        if (open < _nPairs) {
            generate(open + 1, close, str + '(');
        }
        if (open > close) {
            generate(open, close + 1, str + ')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        _nPairs = n;
        generate(0, 0, "");
        return _result;
    }
};