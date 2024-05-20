#include<iostream>

class Solution {
public:
    int climbStairs(int n) {
        int x = 1, y = 0, result;
        for(int i = 0; i < n; i++)
        {
            result = x + y;
            y = x;
            x = result;
        }
        return result;
    }
};