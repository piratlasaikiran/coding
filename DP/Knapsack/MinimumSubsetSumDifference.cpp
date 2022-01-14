#include <bits/stdc++.h>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int MinimumSubsetSumDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int array_sum = sum;
        sum = sum/2;
        int dp[n+1][sum+1] = {0};
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }
        }
        // int s1;
        // for(int i=sum; i>sum/2; i++){
        //     if(dp[n][i] <= sum/2){
        //         s1 = dp[n][i];
        //         break;
        //     }
        // }
        cout << dp[n][sum] << endl;
        return array_sum-2*dp[n][sum];
    }
};

int main(){
    Solution obj;

    vector<int> nums = {2,7,4,1,8,1};
    auto answer = obj.MinimumSubsetSumDifference(nums);
    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}