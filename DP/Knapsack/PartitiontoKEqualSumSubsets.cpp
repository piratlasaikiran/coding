#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k != 0)
            return false;
        sum = sum/k;
        int dp[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                    
            }
        }
        return dp[n][sum];
    }
};

int main(){
    Solution obj;
    vector<int> nums = {4,3,2,3,5,2,1};
    auto answer = obj.canPartitionKSubsets(nums, 5);
    cout << "Answer is: " << answer << endl;
    return 0;
}