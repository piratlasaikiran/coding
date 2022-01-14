#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns, 0));

        int curMax = 0;
        for(int i=rows-1; i>=0; i--){
            for(int j=columns-1; j>=0; j--){
                curMax = max(curMax, dp[i][j]);
                if(i==rows-1 || j==columns-1)
                    dp[i][j] = matrix[i][j]-'0';
                else{
                    if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1])) + 1;
                    curMax = max(curMax, dp[i][j]);
                    }
                }
            }
        }
        cout << "DP Grid is: " << endl;
        for(auto i:dp){
            for(auto j:i)
                cout << j << ' ';
        cout << endl;
        }
        return curMax*curMax;

    }
};

int main(){
    Solution obj;
    vector<vector<char>> grid = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};

    cout << "Grid is: " << endl;
    for(auto i:grid){
        for(auto j:i)
            cout << j << ' ';
    cout << endl;
    }
    auto answer = obj.maximalSquare(grid);
    cout << "Answer: " << answer << endl;
    return 0;
}