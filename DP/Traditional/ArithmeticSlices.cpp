#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isArithmeticSlice(vector<int> slice){
        int l = slice.size();
        int diff = slice[1]-slice[0];
        
        for(int i=1; i<l-1; i++){
            if(slice[i+1]-slice[i] != diff){
                return false;
            }
        }
        return true;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int answer=0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<=n-3; i++){
            vector<int> tmp = vector<int>(nums.begin()+i, nums.begin()+3+i);
            if(isArithmeticSlice(tmp))
                dp[i][i+2]++;
        }
        
        for(int start=0; start<=n-3; start++){
            for(int end=3; end<n; end++){
                if(dp[start][end-1] && nums[end]-nums[end-1] == nums[end-1]-nums[end-2])
                    dp[start][end] = 1;
            }
        }

        for(int start=0; start<n; start++){
            for(int end=0; end<n; end++){
                if(dp[start][end]==1)
                    answer++;
            }
        }
        return answer;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3,4};
    auto answer = obj.numberOfArithmeticSlices(nums);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}