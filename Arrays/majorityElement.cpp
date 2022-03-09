#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majorityIndex = 0;
        int majorityElementCount = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == nums[majorityIndex]){
                majorityElementCount++;
            }
            else{
                majorityElementCount--;
            }
            if(majorityElementCount==0){
                majorityIndex = i;
                majorityElementCount = 1;
            }
        }
        return nums[majorityIndex];
    }
};

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution obj;
    auto answer = obj.majorityElement(nums);
    cout << "Answer: " << answer << endl;
    return 0;
}