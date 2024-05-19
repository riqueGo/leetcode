#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

class Solution {
private:
    vector<vector<string>> result;
    string word;

    bool isPalindrome(string s)
    {
        int i = 0, j = s.length()-1;

        while(i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        word = s;
        vector<string> currPalindromes;
        dfs(currPalindromes, 0);
        return result;
    }

    void dfs(vector<string>& currPalindromes, int startIndex)
    {
        if(startIndex >= word.length())
        {
            result.push_back(currPalindromes);
            return;
        }

        string subString;
        for(int i = 1; i <= word.length() - startIndex; i++)
        {
            subString = word.substr(startIndex, i);
            if(!isPalindrome(subString))
                continue;

            currPalindromes.push_back(subString);
            dfs(currPalindromes, startIndex+i);
            currPalindromes.pop_back();
        }
    }
};