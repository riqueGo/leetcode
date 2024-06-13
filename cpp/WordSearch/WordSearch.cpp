#include<iostream>
#include<vector>

using std::vector;
using std::string;
using std::to_string;

class Solution {
private:
    string word;
    int directions[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int rowSize;
    int columnSize;

    bool isOutOfBound(int i, int j) {
        return i < 0 || j < 0 || i >= columnSize || j >= rowSize;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, int indexLetter) {
        if(indexLetter >= word.length()) {
            return true;
        }

        if(isOutOfBound(i,j) || board[i][j] != word[indexLetter]) {
            return false;
        }

        char currentLetter = board[i][j];
        board[i][j] = '0';

        for(int k = 0; k < 4; k++) {
            if(dfs(board, directions[k][0]+i, directions[k][1]+j, indexLetter+1)) {
                return true;
            }
        }
        board[i][j] = currentLetter;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        columnSize = board.size();
        rowSize = board[0].size();

        for(int i = 0; i < columnSize; i++) {
            for(int j = 0; j < rowSize; j++) {
                if(board[i][j] == word[0] && dfs(board, i, j, 0)) {
                    return true;
                }
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