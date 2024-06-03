#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using std::string;
using std::vector;
using std::unordered_set;
using std::sort;

class Solution {
private:
    string word;
    unordered_set<int> alreadyVisited;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        word = s;
        return dfs(0,wordDict);
    }

    bool dfs(int startIndex, vector<string>& wordDict)
    {
        if(startIndex == word.length())
            return true;
        
        if(alreadyVisited.count(startIndex))
            return false;
        
        alreadyVisited.insert(startIndex);
        
        int currWordLen = 0;
        string sub;
        
        for(int i = 0; i < wordDict.size(); i++)
        {
            if(currWordLen != wordDict[i].length())
            {
                currWordLen = wordDict[i].length();
                sub = word.substr(startIndex, currWordLen);
            }
            if(sub == wordDict[i] && dfs(startIndex+currWordLen, wordDict))
                return true;
        }
        return false;
    }
};