#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curPos = 1;
        int prevElement = nums[0];
        int prevElementCount = 1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(prevElementCount == 0){
                prevElementCount++;
            }  
            else if(nums[i] == prevElement && prevElementCount == 1){
                prevElementCount++;
            }
            else if(nums[i] == prevElement && prevElementCount > 1){
                continue;
            }
            else{
                prevElement = nums[i];
                prevElementCount = 1;
            }
            nums[curPos] = nums[i];
            curPos++;
        }
        return curPos;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    auto answer = obj.removeDuplicates(nums);
    cout << "Answer: " << answer << endl;
    return 0;
}