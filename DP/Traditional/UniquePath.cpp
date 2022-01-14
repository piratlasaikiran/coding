#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>> grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        if(rows==1 && columns==1)
            return !grid[0][0];
        vector<vector<int>> dp(rows, vector<int>(columns, 1));
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(i==0 && j==0)
                    continue;
                else if(i==0 && ((grid[i][j]==1) || dp[i][j-1]==0))
                    dp[i][j] = 0;
                else if(j==0 && ((grid[i][j]==1) || dp[i-1][j]==0))
                    dp[i][j] = 0;
                else
                    continue;
            }
        }

        for(int i=1; i<rows; i++){
            for(int j=1; j<columns; j++){
                if(grid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[rows-1][columns-1];       
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid = {{1}};

    auto answer = obj.uniquePaths(grid);
    cout << "Answer: " << answer << endl;
    // for(auto i:answer){
    //     for(auto j:i)
    //         cout << j << " ";
    // cout << endl;
    // }
    return 0;
}