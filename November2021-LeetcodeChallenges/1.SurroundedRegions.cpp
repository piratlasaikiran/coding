#include <bits/stdc++.h>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    bool flippable=false;
    int r[4] = {1, 0, -1, 0};
    int c[4] = {0, 1, 0, -1};

    void CanThisBeFlipped(vector<vector<char>>& board, int i, int j, int rows, int columns, vector<vector<bool>>& visited){
        if(i<0 || i>=rows || j<0 || j>= columns || board[i][j]=='X' || visited[i][j])
            return ;
        visited[i][j] = true;
        CanThisBeFlipped(board, i+r[0], j+c[0], rows, columns, visited);
        CanThisBeFlipped(board, i+r[1], j+c[1], rows, columns, visited);
        CanThisBeFlipped(board, i+r[2], j+c[2], rows, columns, visited);
        CanThisBeFlipped(board, i+r[3], j+c[3], rows, columns, visited);
    }

    void MarkTheBoard(vector<vector<char>>& board, int i, int j, int rows, int columns){
        if(i<0 || i>=rows || j<0 || j>= columns || board[i][j]=='X')
            return ;

        board[i][j] = 'X';
        MarkTheBoard(board, i+r[0], j+c[0], rows, columns);
        MarkTheBoard(board, i+r[1], j+c[1], rows, columns);
        MarkTheBoard(board, i+r[2], j+c[2], rows, columns);
        MarkTheBoard(board, i+r[3], j+c[3], rows, columns);
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        for(int i=1; i<rows-1; i++){
            for(int j=1; j<columns-1; j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    flippable = false;
                    CanThisBeFlipped(board, i, j, rows, columns, visited);
                    if(!flippable)
                        MarkTheBoard(board, i, j, rows, columns);
                    flippable = true;
                }
            }
        }
        
    }
};

    int main(){
    Solution obj;

    
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(3);
    // root->right->right->right = new TreeNode(4);

    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    obj.solve(board);

    cout << "Answer: " << endl;

    for(auto j:board){
        for(auto i:j){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}