#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int NumberOfSUbsetsWithGivenDIfference(vector<int>& nums, int diff) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int subset_sum = sum+diff, n = nums.size();
        if(subset_sum%2 != 0)
            return 0;
        subset_sum = subset_sum/2;
        int dp[n+1][subset_sum+1] = {0};

        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=subset_sum; j++){
                if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
            }
        }
        return dp[n][subset_sum];
    }
        
};

int main(){
    Solution obj;

    vector<int> nums = {1, 1, 2, 3};
    auto answer = obj.NumberOfSUbsetsWithGivenDIfference(nums, 1);
    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}