#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(columns+1, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                dp[i+1][j+1] = mat[i][j] + dp[i][j+1] + dp[i+1][j] - dp[i][j]; 
            }
        }
        for(auto j:dp){
            for(auto i:j)
                cout << i << " ";
        cout << endl;
        }
        cout << endl;
        vector<vector<int>> blockSum(rows, vector<int>(columns, 0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                int r0 = max(0, i-k), c0 = max(0, j-k), r1 = min(rows-1, i+k), c1 = min(columns-1, j+k); 
                blockSum[i][j] = dp[r1+1][c1+1] - dp[r0][c1+1] - dp[r1+1][c0] + dp[r0][c0];
            }
        }
        return blockSum;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};

    auto answer = obj.matrixBlockSum(grid, 1);
    for(auto i:answer){
        for(auto j:i)
            cout << j << " ";
    cout << endl;
    }
    return 0;
}

//[[12,21,16],[27,45,33],[24,39,28]]