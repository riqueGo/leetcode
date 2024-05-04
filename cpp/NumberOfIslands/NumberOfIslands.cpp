#include<iostream>
#include<vector>
using std::vector;



class Solution {
    private:
        int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int columnSize;
        int rowSize;

        void dfs(vector<vector<char>>& grid, int i, int j)
        {
            if(i >= columnSize || i < 0 || j >= rowSize || j < 0 || grid[i][j] == '0')
                return;
            
            grid[i][j] = '0';

            for(int* direction : directions)
                dfs(grid, direction[0] + i, direction[1] + j);
        }

    public:
        int numIslands(vector<vector<char>>& grid) {
            int result = 0;
            columnSize = grid.size();
            rowSize = grid[0].size();
            
            for (int i = 0; i < columnSize; i++)
            {
                for(int j = 0; j < rowSize; j++)
                {
                    if (grid[i][j] == '1')
                    {
                        dfs(grid, i, j);
                        result++;
                    }
                }
            }
            return result;
        }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };

    Solution solution;
    std::cout << solution.numIslands(grid);
}