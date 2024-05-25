#include<iostream>
#include<unordered_set>

using std::string;
using std::unordered_set;

class Solution {
private:
    unordered_set<string> codes = {
        "1","2","3","4","5","6","7","8","9","10",
        "11","12","13","14","15","16","17","18",
        "19","20","21","22","23","24","25","26"
    };

public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;

        int curr = 1, prev = 1, prevprev = 1;
        string sub;

        for(int i = 1; i < s.length(); i++)
        {
            curr = 0;
            sub = "";
            sub += s[i];
            if(codes.count(sub))
                curr += prev;
            
            sub = s.substr(i-1,2);
            if(codes.count(sub))
                curr += prevprev;
            
            prevprev = prev;
            prev = curr;
        }
        return curr;
    }
};

int main()
{
    Solution s;
    s.numDecodings("1116");
}