#include <iostream>
#include <vector>
#include <stack>
#include <map>

using std::vector;
using std::stack;
using std::map;
using std::pair;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> posByTime;
        int countFleet = 0;

        for(int i = 0; i < position.size(); i++) {
            posByTime[position[i]] = (double) (target - position[i])/speed[i];
        }

        double maxTime = 0.0;

        for(auto it = posByTime.rbegin(); it != posByTime.rend(); it++) {
            if(it->second > maxTime){
                countFleet++;
                maxTime = it->second;
            }
        }
        return countFleet;
    }
};

int main() {

    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};

    Solution solution;
    int result = solution.carFleet(12, position, speed);

    std::cout << result << std::endl;
}

//time = (Target - initialPosition)/speed