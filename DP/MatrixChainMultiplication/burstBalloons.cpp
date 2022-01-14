// https://www.youtube.com/watch?v=YzvF8CqPafI

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n ;i++, j++){
                int curMax = INT_MIN;
                for(int k=i; k<=j; k++){
                    int left = 0, right = 0;
                    if(k!=i){
                        left = dp[i][k-1];
                    }
                    if(k!=j){
                        right = dp[k+1][j];
                    }
                    int val = nums[k];
                    if(i >0){
                        val = val*nums[i-1];
                    }
                    if(j < n-1){
                        val = val*nums[j+1];
                    }
                    int totalCoins = left+right+val;
                    curMax = max(curMax, totalCoins);
                }
                dp[i][j] = curMax;


            }
        }
        return dp[0][n-1];
    }
};

int main(){
    Solution obj;
    vector<int> nums = {3,1,5,8};
    auto answer = obj.maxCoins(nums);
    cout << "Answer: " << answer << endl;
    return 0;
}