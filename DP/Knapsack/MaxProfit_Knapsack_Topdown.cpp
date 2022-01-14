#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int dp[101][1001];
    int maxProfit(vector<int>& values, vector<int>& weights, int weight, int n) 
    {
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<n+1; i++){
            for(int j=1; j<weight+1; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(weights[i-1]<=j){
                    dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
                    
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][weight];

    }
};
int main(){
    Solution obj;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int weight = 50;
    int n = values.size();
    auto answer = obj.maxProfit(values, weights, weight, n);
    cout << "Answer is: " << answer << endl;
    
    return 0;
}