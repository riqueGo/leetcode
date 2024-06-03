#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startRow = 0,
            startColumn = 0,
            endRow = matrix[0].size()-1,
            endColumn = matrix.size()-1;
        vector<int> result;
        bool stop = true;

        while(true)
        {
            stop = true;
            for(int i = startRow; i <= endRow; i++)
            {
                result.push_back(matrix[startColumn][i]);
                stop = false;
            }

            if(stop) break;
            stop = true;
            
            startColumn++;

            for(int i = startColumn; i <= endColumn; i++)
            {
                result.push_back(matrix[i][endRow]);
                stop = false;
            }

            if(stop) break;
            stop = true;
            
            endRow--;

            for(int i = endRow; i >= startRow; i--)
            {
                result.push_back(matrix[endColumn][i]);
                stop = false;
            }

            if(stop) break;
            stop = true;

            endColumn--;

            for(int i = endColumn; i >= startColumn; i--)
            {
                result.push_back(matrix[i][startRow]);
                stop = false;
            }

            if(stop) break;
            stop = true;

            startRow++;
        }

        return result;

    }
};