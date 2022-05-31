#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void doPermutations(vector<vector<int>>& answer, vector<int> nums, int l, int r, int n){
        
        if(l==r){
            answer.push_back(nums);
            return;
        }
        // for(auto i:nums){
        //     cout << i << " ";
        // }
        // cout << endl;

        for(int i=l; i<=r; i++){
            if(nums[l] != nums[r]){
                swap(nums[l], nums[i]);
                doPermutations(answer, nums, l+1, r, n);
                swap(nums[l], nums[i]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        int n = nums.size();
        doPermutations(answer, nums, 0, n-1, n);
        return answer;
        
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1, 1, 2};
    auto answer = obj.permuteUnique(nums);
    for(auto i:answer){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    } 
}