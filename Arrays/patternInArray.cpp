#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> numStack;
        vector<int> curMin(n, 0);
        for(int i=1; i<n; i++){
            curMin[i] = min(nums[i], curMin[i-1]);
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] > curMin[i]){
                while(!numStack.empty() && numStack.top()<=curMin[i]){
                    numStack.pop();
                }
                if(!numStack.empty() && numStack.top() < nums[i]){
                    return true;
                }
                numStack.push(nums[i]);
            }
        }
        return false;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {3,1,4,2};
    auto answer = obj.find132pattern(nums);
    cout << "Answer: " << answer << endl;
    return 0;
}