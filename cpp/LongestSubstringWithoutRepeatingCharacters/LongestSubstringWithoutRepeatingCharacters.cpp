#include <iostream>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution
{
    public:
        int max(int a, int b){
            return a > b ? a : b;
        }

        int lengthOfLongestSubstring(string s)
        {
            int i = 0, j = 0, result = 0;
            unordered_set<char> nonRepeatedChar;

            while (j < s.length())
            {
                char ch = s.at(j);
                if (nonRepeatedChar.count(ch))
                {
                    result = max(result, j-i);
                    while (s.at(i) != ch)
                    {
                        nonRepeatedChar.erase(s.at(i));
                        i++;
                    }
                    i++;
                }
                nonRepeatedChar.insert(ch);
                j++;
            }
            return max(result, j-i);
        } 
};

int main() {
    Solution solution;
    solution.lengthOfLongestSubstring("abcabcbb");
}