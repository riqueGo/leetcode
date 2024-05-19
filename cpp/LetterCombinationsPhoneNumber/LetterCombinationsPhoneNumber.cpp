#include<iostream>
#include<vector>
#include<unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
private:
    vector<string> result;
    string digits;
        unordered_map<char, string> lettersByNumber = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return result;

        this->digits = digits;
        string combinations;
        dfs(combinations, 0);
        return result;
    }

    void dfs(string& combinations, int index)
    {
        if(index == digits.length())
        {
            result.push_back(combinations);
            return;
        }

        for(char letter : lettersByNumber[digits[index]])
        {
            combinations.push_back(letter);
            dfs(combinations, index+1);
            combinations.pop_back();
        }
    }
};