#include<iostream>
#include<vector>
#include <utility>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if (intervals.empty())
            return vector<vector<int>>{newInterval};

        if(newInterval.at(0) > intervals.at(intervals.size()-1).at(1))
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        int i = 0;    
        vector<vector<int>> result;
        while (i < intervals.size() && newInterval.at(0) > intervals.at(i).at(1))
            i++;
        
        result.insert(result.end(), intervals.begin(), intervals.begin()+i);

        while (i < intervals.size() && newInterval.at(1) >= intervals.at(i).at(0))
        {
            newInterval = {
                min(newInterval.at(0), intervals.at(i).at(0)),
                max(newInterval.at(1), intervals.at(i).at(1))
            };
            i++;
        }
        result.push_back(newInterval);
        result.insert(result.end(), intervals.begin()+i, intervals.end());
        
        return result;
    }
};