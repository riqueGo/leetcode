#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;
using std::pair;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size, 0);
        stack<pair<int, int>> s;

        for (int i = 0; i < size; i++) {
            while(!s.empty() && s.top().first < temperatures[i]) {
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push(pair<int, int>(temperatures[i], i));
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> result = solution.dailyTemperatures(temperatures);

    for(int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}