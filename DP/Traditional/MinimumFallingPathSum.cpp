#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns, 0));
        dp[0] = matrix[0];
        for(int i=1; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(j==0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][0], dp[i-1][1]);
                }
                else if(j==columns-1){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][columns-2], dp[i-1][columns-1]);
                }
                else{
                    dp[i][j] = matrix[i][j] + min({dp[i-1][j-1], dp[i-1][j+1], dp[i-1][j]});
                }
            }
        }
        return *min_element(dp[columns-1].begin(), dp[columns-1].end());
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int columns = triangle[rows-1].size();
        vector<int> dp(rows, 0);
        dp[0] = triangle[0][0];
        for(int i=1; i<rows; i++){
            vector<int> ans = dp;
            for(int j=0; j<triangle[i].size(); j++){
                if(j==0){
                    dp[j] = triangle[i][j] + ans[0];
                }
                else if(j==triangle[i].size()-1){
                    dp[j] = triangle[i][j] + ans[triangle[i].size()-2];
                }
                else{
                    dp[j] = triangle[i][j] + min(ans[j-1], ans[j]);
                }
            }
        }
        // for(auto i:dp){
        //     for(auto j:i)
        //         cout << j << " ";
        // cout << endl;
        // }
        return *min_element(dp.begin(), dp.end());
    }
};

int main(){
    Solution obj;
    vector<vector<int>> matrix = {{2},{3,4},{6,5,7},{4,1,8,3}};
    auto answer = obj.minimumTotal(matrix);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}