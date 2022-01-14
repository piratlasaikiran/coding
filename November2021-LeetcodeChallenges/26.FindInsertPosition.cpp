#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int searchInsert(vector<int>& nums, int target) {
        int startPos = 0;
        int endPos = nums.size();
        int midPos = 0;
        while(startPos <= endPos){
            if (startPos == endPos){
                midPos = startPos;
                break;
            }
            midPos = startPos + (endPos-startPos)/2;
            if (nums[midPos] > target) {
                endPos = midPos-1;
            }
            else if(nums[midPos] < target){
                startPos = midPos + 1;
            }
            else{
                break;
            }
        }
        if((midPos+1 <= nums.size()-1) && (nums[midPos] < target) && (nums[midPos+1] > target))
            return midPos+1;
        return midPos;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,3};
    auto answer = obj.searchInsert(nums, 2);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}