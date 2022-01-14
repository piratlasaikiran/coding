#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isValidPosition(int x, int y, int rows, int columns){
        return (x>=0 && x<rows && y>=0 && y<columns);
    }

    void exploreBattleship(vector<vector<char>> &board, int rowPos, int colPos, int bottom, int right, int rows, int columns){
        if(!isValidPosition(rowPos, colPos, rows, columns) || board[rowPos][colPos] == 'V' || board[rowPos][colPos] == '.')
            return;
        board[rowPos][colPos] = 'V';
        exploreBattleship(board, rowPos+bottom, colPos+right, bottom, right, rows, columns);
    }

    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        int battleshipsCount = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(board[i][j] == 'X'){
                    board[i][j] = 'V';
                    battleshipsCount++;
                    if(isValidPosition(i, j+1, rows, columns) && board[i][j+1] == 'X'){
                        exploreBattleship(board, i, j+1, 0, 1, rows, columns);
                    }
                    else if(isValidPosition(i+1, j, rows, columns) && board[i+1][j] == 'X'){
                        exploreBattleship(board, i+1, j, 1, 0, rows, columns);
                    }

                }
            }
        }
        return battleshipsCount;   
    }
};

int main(){
    vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    Solution obj;
    auto answer = obj.countBattleships(board);
    cout << "Answer: " << answer << endl;
}