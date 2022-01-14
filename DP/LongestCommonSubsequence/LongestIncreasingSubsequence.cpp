#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        int maxLen=1, prevMax=0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1){
                    dp[i] = dp[j] + 1;
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }
        return maxLen;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int inc=1, dec=1;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1])
                inc = dec+1;
            else if(nums[i]<nums[i-1])
                dec = inc+1;
        }
        return max(inc, dec);
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,7,4,9,2,5};
    auto answer = obj.wiggleMaxLength(nums);
    cout << "Answer is: " << answer << endl;
    return 0;
}