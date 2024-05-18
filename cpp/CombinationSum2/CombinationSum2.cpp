#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::sort;

class Solution {
private:
    vector<vector<int>> result;
    int target;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->target = target;
        vector<int> currCandidates;
        combinations(candidates, currCandidates, 0, 0);
        return result;
    }

    void combinations(vector<int>& candidates, vector<int>& currCandidates, int currIndex, int sum)
    {
        if(sum == target)
        {
            result.push_back(currCandidates);
            return;
        }

        int prev = -1;
        while(currIndex < candidates.size())
        {
            if(sum + candidates[currIndex] > target)
                break;

            while(currIndex < candidates.size() && prev == candidates[currIndex])
                currIndex++;

            if(currIndex >= candidates.size())
                return;
            
            prev = candidates[currIndex];

            currCandidates.push_back(candidates[currIndex]);
            combinations(candidates, currCandidates, currIndex+1, sum + candidates[currIndex]);
            currCandidates.pop_back();
            currIndex++;
        }
    }
};