#include<iostream>
#include<vector>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN, i = 0, j = height.size()-1;

        while(i < j)
        {
            maxArea = max(maxArea, (j-i)* min(height[i],height[j]));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxArea;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    s.maxArea(height);
}