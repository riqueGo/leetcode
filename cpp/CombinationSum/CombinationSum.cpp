#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using std::vector;
using std::stack;
using std::sort;

class Solution
{

private:
    int target;
    vector<vector<int>> result;

    void greedy(vector<int>& candidates, vector<int> tempResult, int index, int total)
    {
        if (total == target)
        {
            result.push_back(tempResult);
            return;
        }

        for(int i = index; i < candidates.size(); i++)
        {
            int tempTotal = total + candidates.at(i);
            if(tempTotal > target)
                break;
            
            tempResult.push_back(candidates.at(i));
            greedy(candidates, tempResult, i, tempTotal);
            tempResult.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        greedy(candidates, vector<int>{}, 0, 0);
        return result;
    }
};

int main()
{
    vector<int> candidates = {2,3,6,7};
    Solution s;
    s.combinationSum(candidates, 7);
}