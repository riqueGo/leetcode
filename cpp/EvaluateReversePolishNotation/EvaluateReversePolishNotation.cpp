#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Solution {
private:
    stack<int> rpn;

    int popValue() {
        int value = rpn.top();
        rpn.pop();
        return value;
    }

    void sum() {
        int a = popValue();
        int b = popValue();
        rpn.push(b+a);
    }

    void subtract() {
        int a = popValue();
        int b = popValue();
        rpn.push(b-a);
    }

    void multiply() {
        int a = popValue();
        int b = popValue();
        rpn.push(b*a);
    }

    void divide() {
        int a = popValue();
        int b = popValue();
        rpn.push(b/a);
    }


public:
    int evalRPN(vector<string>& tokens){
        

        for(string t : tokens){
            if(t == "+") sum();
            else if (t == "-") subtract();
            else if (t == "*") multiply();
            else if (t == "/") divide();
            else rpn.push(std::stoi(t));
        }
        int result = rpn.top();
        rpn.pop();
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> input1 = {"2","1","+","3","*"};
    vector<string> input2 = {"4","13","5","/","+"};
    vector<string> input3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    std::cout << solution.evalRPN(input1) << std::endl;
    std::cout << solution.evalRPN(input2) << std::endl;
    std::cout << solution.evalRPN(input3) << std::endl;
}

