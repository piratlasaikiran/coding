#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // House Robbery I
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> robberAmount (n+1, 0);
        robberAmount[1] = nums[0];
        for(int i=2; i<=n; i++){
            robberAmount[i] = max(robberAmount[i-1] , robberAmount[i-2] + nums[i-1]);
        }
        return robberAmount[n];

    }

    // House Robbery II
    // int robbery(vector<int> nums) {
    //     int n = nums.size();
    //     vector<int> robberAmount (n+1, 0);
    //     robberAmount[1] = nums[0];
    //     for(int i=2; i<=n; i++){
    //         robberAmount[i] = max(robberAmount[i-1] , robberAmount[i-2] + nums[i-1]);
    //     }
    //     return robberAmount[n];
    // }

    // int rob(vector<int>& nums){
    //     vector<int> case1 = {nums.begin(), nums.end()-1};
    //     vector<int> case2 = {nums.begin()+1, nums.end()};
    //     return max(robbery(case1), robbery(case2));
    // }

    // Delete and Earn
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        cout << "Sorted Array: ";
        for(auto j:nums)
            cout << j << " ";
        cout << endl;
        map<int, int> frequency;
        for(int i=0; i<nums.size(); i++){
            frequency[nums[i]]++;
        }
        vector<int> AccumulatedNums;
        int n = nums[nums.size()-1];
        for(int i=0; i<=n; i++){
            if(frequency.count(i) != 0)
                AccumulatedNums.push_back(i*frequency[i]);
            else
                AccumulatedNums.push_back(0);
        }
        cout << "Accumulated Array: ";
        for(auto j:AccumulatedNums)
            cout << j << " ";
        cout << endl;
        return rob(AccumulatedNums);
    }
};

    int main(){
    Solution obj;
    vector<int> nums = {3,1};
    auto answer = obj.deleteAndEarn(nums);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}
/*
i = 0  1  2  3
c = 1  2  3  1
m = 1    
*/