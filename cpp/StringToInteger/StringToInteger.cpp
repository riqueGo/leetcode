#include<iostream>
#include <exception>

using std::string;
using std::exception;

class Solution {
private:
    string word;
    string number;

public:
    int myAtoi(string s) {
        word = s;
        int index = 0;
        ignoreLeadingWhiteSpaces(index);

        if(index >= s.length())
            return 0;
        
        bool isNegative = isNegativeNumber(index);

        if(index >= s.length())
            return 0;

        skipLeadingZeros(index);

        if(index >= s.length() || !isdigit(word[index]))
            return 0;
        
        getNumber(index);

        try {
            int result = stoi(number);
            return result;
        }
        catch (exception& e) { return isNegative ? INT_MIN : INT_MAX; }
    }

    void ignoreLeadingWhiteSpaces(int& index)
    {
        while(index < word.length() && word[index] == ' ')
            index++;
    }

    bool isNegativeNumber(int& index)
    {
        if(word[index] == '-')
        {
            number.push_back(word[index++]);
            return true;
        }
        else if(word[index] == '+')
            index++;
        return false;
    }

    void skipLeadingZeros(int& index)
    {
        while(index < word.length() && word[index] == '0')
            index++;
    }

    void getNumber(int& index)
    {
        while(index < word.length() && isdigit(word[index]))
            number.push_back(word[index++]);
    }
};