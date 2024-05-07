#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::sort;
using std::max;

struct VectorVectorComparator {
    bool operator()(const vector<int>& v1, const vector<int>& v2) const {
        return v1[0] < v2[0];
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), VectorVectorComparator());

        vector<vector<int>> result;
        result.push_back(intervals.at(0));
        int lastIndex = 0;

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= result[lastIndex][1])
                result[lastIndex][1] = max(intervals[i][1], result[lastIndex][1]);
            else
            {
                result.push_back(intervals[i]);
                lastIndex++;
            }
        }
        return result;
    }
};