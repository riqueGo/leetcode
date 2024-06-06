#include<iostream>

using std::string;

class Solution {

private:
    string word;
    string result;

    void getLongestSubPalindrome(int i, int j)
    {
        while(i >= 0 && j < word.length() && word[i] == word[j])
        {
            i--;
            j++;
        }
        i++;
        j--;

        if(j-i+1 > result.length())
            result = word.substr(i, j-i+1);
    }

public:
    string longestPalindrome(string s) {
        word = s;

        for(int i = 0; i < word.length(); i++)
        {
            getLongestSubPalindrome(i,i);
            getLongestSubPalindrome(i,i+1);
        }
        return result;
    }
};