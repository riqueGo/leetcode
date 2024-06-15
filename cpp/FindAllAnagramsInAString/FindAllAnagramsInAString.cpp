#include<iostream>
#include<vector>
#include<unordered_map>

using std::vector;
using std::unordered_map;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.length() > s.length()) {
            return result;
        }

        unordered_map<char,int> quantityByLetters;
        for(int i = 0; i < p.length(); i++) {
            quantityByLetters[p[i]]++;
        }

        int i = 0, j = 0;
        while(j < p.length()-1) {
            if(quantityByLetters.count(s[j])) {
                quantityByLetters[s[j]]--;
            }
            j++;
        }

        while(j < s.length()) {
            if(quantityByLetters.count(s[j])) {
                quantityByLetters[s[j]]--;
            }

            bool isAnagram = true;
            for(auto it = quantityByLetters.begin(); it != quantityByLetters.end(); it++) {
                if(it->second != 0) {
                    isAnagram = false;
                    break;
                }
            }

            if(isAnagram) {
                result.push_back(i);
            }

            if(quantityByLetters.count(s[i])) {
                quantityByLetters[s[i]]++;
            }
            i++;
            j++;
        }
        return result;
    }
};

/*
s.length() = 10
p.length() = 3

s = "cbaebabacd", p = "abc"
quantityByLetters = {
    a : 1
    b : 1
    c : 0
}
i = 8, j = 10
result = [0,6]
*/