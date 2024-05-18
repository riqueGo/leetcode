#include<iostream>
#include<vector>

using std::vector;
using std::string;
using std::to_string;

class Solution {
private:
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int columnSize;
    int rowSize;
    string word;

    bool isOutOfBoardBounds(int i, int j)
    {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    bool dfs(vector<vector<char>>& board, const int (&pos)[2], int indexWord)
    {
        if(indexWord == word.length())
            return true;

        int i = pos[0], j = pos[1];
        if(isOutOfBoardBounds(i, j) || word[indexWord] != board[i][j])
            return false;
        
        board[i][j] = '#';

        for(int k = 0; k < 4; k++)
        {
            if(dfs(board, {directions[k][0] + i, directions[k][1] + j}, indexWord+1))
                return true;
            
        }
        board[i][j] = word[indexWord];
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        columnSize = board.size();
        rowSize = board[0].size();
        bool foundWord = false;
        
        for(int i = 0; i < columnSize; i++)
        {
            for(int j = 0; j < rowSize; j++)
            {
                if(board[i][j] == word[0] && dfs(board, {i,j}, 0))
                    return true;
            }
        }
        return false;
    }
};


int main()
{
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'}
    };
    Solution s;
    std::cout << s.exist(board, "ABCEFSADEESE");
}