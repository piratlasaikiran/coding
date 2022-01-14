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

    int uniquePaths = 0;
    int x[4] = {1,0,-1,0};
    int y[4] = {0, 1, 0, -1};

    bool validGrid(vector<vector<int>>& grid, int rows, int columns){
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == 0)
                    return false;
            }
        }
        return true;
    }

    void PathFinder(vector<vector<int>>& grid, int startX, int startY, int destX, int destY, int rows, int columns){
        if(startX<0 || startX>=rows || startY<0 || startY>=columns || grid[startX][startY]==-1 )
            return;
        if(startX==destX && startY==destY){
            if(validGrid(grid, rows, columns))
                uniquePaths++;
        }
        grid[startX][startY] = -1;
        for(int k=0; k<4; k++){
            int nextX = startX + x[k];
            int nextY = startY + y[k];
            if(nextX<0 || nextX>=rows || nextY<0 || nextY>=columns)
                continue;
            int tmp = grid[nextX][nextY];
            PathFinder(grid, nextX, nextY, destX, destY, rows, columns);
            grid[nextX][nextY] = tmp;
        }

    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int startX, startY, destX, destY;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == 1){
                    startX = i;
                    startY = j;
                }
                if(grid[i][j] == 2){
                    destX = i;
                    destY = j;
                }
            }
        }
        PathFinder(grid, startX, startY, destX, destY, rows, columns);
        return uniquePaths;
    }
};

    int main(){
    Solution obj;

    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    auto answer = obj.uniquePathsIII(grid);

    cout << "Answer: " << answer << endl;

    return 0;
}