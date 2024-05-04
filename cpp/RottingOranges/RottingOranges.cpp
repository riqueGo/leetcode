#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using std::vector;
using std::string;
using std::pair;
using std::to_string;
using std::queue;

class Solution {
    private:
        int freshOranges = 0;
        int directions [4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int columnSize;
        int rowSize;

        bool isOutOfBoundry(int i, int j)
        {
            return i < 0 || i >= columnSize || j < 0 || j >= rowSize;
        }

        void rottenNeighbours(vector<vector<int>>& grid, queue<pair<int,int>>& rottenOranges)
        {
            pair<int,int> rottenPos = rottenOranges.front();
            rottenOranges.pop();

            for (int* direction : directions)
            {
                int i = rottenPos.first + direction[0];
                int j = rottenPos.second + direction[1];
                if(!isOutOfBoundry(i, j) && grid[i][j] == 1)
                {
                    grid[i][j] = 2;
                    rottenOranges.push(pair(i, j));
                    freshOranges--;
                }
            }
        }

    public:
        int orangesRotting(vector<vector<int>>& grid) {
            columnSize = grid.size();
            rowSize = grid[0].size();
            queue<pair<int,int>> rottenOranges;

            for(int i = 0; i < columnSize; i++)
            {
                for(int j = 0; j < rowSize; j++)
                {
                    if(grid[i][j] == 1)
                        freshOranges++;
                    else if (grid[i][j] == 2)
                        rottenOranges.push(pair(i,j));
                }
            }

            int minutes = 0;

            if(rottenOranges.empty() && freshOranges > 0)
                return -1;

            while(!rottenOranges.empty())
            {
                int rottenSize = rottenOranges.size();

                for(int i = 0; i < rottenSize; i++)
                {
                    rottenNeighbours(grid, rottenOranges);
                }
                minutes++;
            }

            if(minutes == 0)
                return minutes;

            return freshOranges == 0 ? minutes-1 : -1;
        }
};

int main()
{
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    Solution solution;
    std::cout << solution.orangesRotting(grid);
}