#include <bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=Wv6DlL0Sawg
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi=1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 && 1+dp[j]>dp[i])
                    dp[i] = dp[j]+1;
                    maxi = max(maxi, dp[i]);
            }
        }
        vector<int> answer;
        int prev = -1;
        for(int i=n-1; i>=0; i--){
            if(dp[i]==maxi && (prev==-1 || prev%nums[i]==0)){
                answer.push_back(nums[i]);
                maxi--;
                prev = nums[i];
            }
        }
        return answer;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,4,8};

    auto answer = obj.largestDivisibleSubset(nums);
    for(auto i:answer)
        cout << i << " ";
    cout << endl;
    return 0;
}