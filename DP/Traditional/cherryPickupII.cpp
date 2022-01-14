#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int columnVariations[3] = {-1, 0, 1};

    int cherryPickHelper(vector<vector<int>>& grid, int curRow, int column1, int column2, vector<vector<vector<int>>> &dp, int m, int n){
        if(curRow == m){
            return 0;
        }
        if(dp[curRow][column1][column2] != -1){
            return dp[curRow][column1][column2];
        }
        int cherries = column1 == column2 ? grid[curRow][column1] : grid[curRow][column1] + grid[curRow][column2];
        int maxCherries = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int nextColumn1 = column1 + columnVariations[i];
                int nextColumn2 = column2 + columnVariations[j];
                if((nextColumn1 >=0 && nextColumn1 < n) && (nextColumn2 >= 0 && nextColumn2 < n)){
                    maxCherries = max(maxCherries, cherryPickHelper(grid, curRow+1, nextColumn1, nextColumn2, dp, m, n));
                }
            }
        }
        return dp[curRow][column1][column2] = cherries + maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(columns, vector<int>(columns, -1)));
        int answer = cherryPickHelper(grid, 0, 0, columns-1, dp, rows, columns);
        return answer;
    }
};

int main(){
    vector<vector<int>> grid = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    Solution obj;
    auto answer = obj.cherryPickup(grid);
    cout << "Answer: " << answer << endl;
    return 0;
}