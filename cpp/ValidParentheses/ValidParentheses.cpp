#include <iostream>
#include <unordered_map>
#include <stack>

using std::string;
using std::unordered_map;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> result;

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                result.push(c);
                continue;
            }

            if((result.empty()) ||
                (c == ')' && result.top() != '(') ||
                (c == ']' && result.top() != '[') ||
                (c == '}' && result.top() != '{')){
                    return false;
            }
            result.pop();
        }

        return result.empty();
    }

    bool isValidWithHashMap(string s) {
        stack<char> open;
        unordered_map<char, char> parens = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        
        for (char c : s) {
            if (parens.count(c)) {
                if (open.empty()) { return false; }

                if (open.top() != parens[c]) { return false; }

                open.pop();
            } else {
                open.push(c);
            }
        }
        
        return open.empty();
    }

};

int main() {
    Solution solution;
    std::cout << solution.isValid("()") << std::endl;
    std::cout << solution.isValid("()[]{}") << std::endl;
    std::cout << solution.isValid("(]") << std::endl;
    std::cout << solution.isValid("(){}}{") << std::endl;
}