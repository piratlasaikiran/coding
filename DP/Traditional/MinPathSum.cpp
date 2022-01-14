#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>> dp (rows, vector<int>(columns, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(i==0 && j==0)
                    dp[i][j] = grid[0][0];
                else if(i==0)
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(j==0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[rows-1][columns-1];
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};

    auto answer = obj.minPathSum(grid);
    // for(auto i:answer){
    //     for(auto j:i)
    //         cout << j << " ";
    // cout << endl;
    // }
    cout << "Answer: " << answer << endl;
    return 0;
}