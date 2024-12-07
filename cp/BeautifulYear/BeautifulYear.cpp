#include <iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

vector<int> splitToArray(int number) {
    vector<int> result;
    string str = std::to_string(number);

    for (char digit : str) {
        result.push_back(digit - '0');
    }

    return result;
}

void adjustDigits(vector<int>& digits) {
    int count = 0;
    for(int i = 3; i >= 0; i--) {
        digits[i] += count;
        count = 0;
        if(digits[i] > 9) {
            digits[i] = 0;
            count++;
        }
    }
}


bool checkRepeated(vector<int>& digits) {
    for(int i = 0; i < 3; i++) {
        for(int j = i+1; j < 4; j++) {
            if(digits[i] == digits[j]) return true;
        }
    }
    return false;
}

int main() {
    int y;
    std::cin >> y;
    y++;
    vector<int> digits = splitToArray(y);

    while (checkRepeated(digits)) {
        digits[3]++;
        if(digits[3] > 9) {
            adjustDigits(digits);
        }
    }

    std::cout << digits[0] << digits[1] << digits[2] << digits[3] << std::endl; 
}