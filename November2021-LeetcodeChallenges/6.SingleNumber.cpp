#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<int>ans;
        for(auto x:mp){
            if(x.second==1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,1,3,2,5};
    auto answer = obj.singleNumber(nums);

    // cout << "Answer: " << answer << endl;

    for(auto j:answer)
        cout << j << " ";
    cout << endl;

    return 0;
}