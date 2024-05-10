#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;
using std::pair;
using std::min;

class Solution {
private:
    int columnSize;
    int rowSize;
    queue<pair<int,int>> coordinates;
    int directions[4][2] = {
        {0,1},
        {-1,0},
        {0,-1},
        {1,0}
    };

    bool isOutOfBoundary(int i, int j)
    {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    bool hasZerosAround(vector<vector<int>>& mat, int i, int j)
    {
        int x,y;
        for(int k = 0; k < 4; k++)
        {
            x = i + directions[k][0];
            y = j + directions[k][1];

            if(!isOutOfBoundary(x,y) && mat[x][y] == 0)
                return true;
        }
        return false;
    }

    void putMinValueAround(vector<vector<int>>& mat, int i, int j)
    {
        int x,y,minValue = INT_MAX;
        for(int k = 0; k < 4; k++)
        {
            x = i + directions[k][0];
            y = j + directions[k][1];

            if(isOutOfBoundary(x,y))
                continue;

            if(mat[x][y] == INT_MAX)
                coordinates.push(pair(x,y));
            else
                minValue = min(minValue, mat[x][y]+1);
        }
        mat[i][j] = minValue;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        columnSize = mat.size();
        rowSize = mat[0].size();
        
        for(int i = 0; i < columnSize; i++)
            for(int j = 0; j < rowSize; j++)
                if (mat[i][j] == 1)
                {
                    if(hasZerosAround(mat, i, j))
                        coordinates.push(pair(i,j));
                    else
                        mat[i][j] = INT_MAX;
                }
        
        while(!coordinates.empty())
        {
            pair<int,int> currPoint = coordinates.front();
            coordinates.pop();
            putMinValueAround(mat, currPoint.first, currPoint.second);
        }

        return mat;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    s.updateMatrix(mat);
}

/*
[
    [2,2,1,1,1,1,0,1,2,2],
    [1,1,0,0,0,0,0,1,1,1],
    [0,1,0,1,1,1,1,0,0,0],
    [1,1,1,0,0,1,1,0,1,1],
    [1,0,1,1,1,0,1,1,2,2],
    [2,1,0,0,1,0,1,2,1,2],
    [1,0,1,0,0,0,1,1,0,1],
    [2,1,0,1,1,1,1,0,0,1],
    [4,2,1,1,0,0,0,1,1,0],
    [3,2,1,0,1,1,0,1,2,1]
]

*/