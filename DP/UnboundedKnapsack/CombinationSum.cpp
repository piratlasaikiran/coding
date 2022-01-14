#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=target; j++){
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        }
        for(int i=1; i<=target; i++){
            if(i%nums[0]==0)
                dp[1][i] = 1;
            else
                dp[1][i] = 0;
        }
        
        for(int i=2; i<=n; i++){
            for(int j=1; j<=target; j++){
                if(j-nums[i-1] >=0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-nums[i-1]];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        for(auto i:dp){
            for(auto j:i)
                cout << j << " ";
            cout << endl;
        }
        
        return dp[n][target];
        
    }
};

int main(){
    Solution obj;
    vector<int> coins = {1,2,3};
    auto answer = obj.combinationSum4(coins, 4);
    cout << "Answer is: " << answer << endl;
    return 0;
}