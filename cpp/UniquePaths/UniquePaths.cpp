#include<iostream>
#include<vector>

using std::vector;

class Solution {
private:
    int m, n;

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return 0;

        if(matrix[i][j] != 0)
            return matrix[i][j];
        
        matrix[i][j] += dfs(matrix, i, j+1);
        matrix[i][j] += dfs(matrix, i+1, j);
        return matrix[i][j];
    }

public:
    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;

        vector<vector<int>> matrix(m,vector<int>(n,0));
        matrix[m-1][n-1] = 1;
        return dfs(matrix, 0, 0);
    }
};