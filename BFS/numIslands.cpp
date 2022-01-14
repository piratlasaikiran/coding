#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int islands = 0;
    int rr[4] = {1, 0, -1, 0};
    int cc[4] = {0, 1, 0, -1};

    void markIsland(vector<vector<char>> &grid, int r, int c, int rows, int columns){
        if(r<0 || r>= rows || c<0 || c>= columns || grid[r][c] != '1')
            return;
        grid[r][c] = '2';
        for(int i=0; i<4; i++){
            markIsland(grid, r+rr[i], c+cc[i], rows, columns);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    markIsland(grid, i, j, rows, columns);
                }
            }
        }
        return islands;
    }
};

int main(){
    Solution obj;
    vector<vector<char>> grid;
    grid.push_back({'1','1','0','0','0'});
    grid.push_back({'1','1','0','0','0'});
    grid.push_back({'0','0','1','0','0'});
    grid.push_back({'0','0','0','1','1'});

    auto answer = obj.numIslands(grid);
    cout << "Answer is: " << answer << endl;
    return 0;
}