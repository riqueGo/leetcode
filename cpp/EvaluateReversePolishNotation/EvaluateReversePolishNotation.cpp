#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<string>

using std::vector;
using std::string;
using std::stack;
using std::unordered_set;
using std::stoi;

class Solution
{
    public:
        int evaluate(int first, int second, string op)
        {
            if (op == "+")
                return first + second;
            else if (op == "-")
                return first - second;
            else if (op == "*")
                return first * second;
            else
                return first / second;
        }

        int evalRPN(vector<string>& tokens)
        {
            unordered_set<string> uSet = {"+", "-", "*", "/"};
            stack<int> numbers;

            for (string token : tokens)
            {
                if(!uSet.count(token))
                {
                    numbers.push(stoi(token));
                    continue;
                }

                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();

                numbers.push(evaluate(first, second, token));
            }
            return numbers.top();
        }
};