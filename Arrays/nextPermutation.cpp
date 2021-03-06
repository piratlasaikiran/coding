#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                for(int j=n-1; j>i; j--){
                    if(nums[j]>nums[i]){
                        swap(nums[i], nums[j]);
                        sort(nums.begin()+i+1, nums.end());
                        return;
                    }
                }
            }
        }
        sort(nums.begin(), nums.end());
    }
};

int main(){
    vector <int> nums = {1,2,3};
    Solution obj;
    obj.nextPermutation(nums);
    cout << "Answer: ";
    for(auto i:nums){
        cout << i;
    }
    cout << endl;
    return 0;
}