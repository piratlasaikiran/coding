#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        stack<int> beautifulArray = {};
        int elementsDeleted = 0;
        for(int i=0; i<n; i++){
            if(beautifulArray.size()%2 != 0){
                if(!beautifulArray.empty() && beautifulArray.top() == nums[i]){
                    elementsDeleted++;
                }
                else{
                    beautifulArray.push(nums[i]);
                }
            }
            else{
                beautifulArray.push(nums[i]);
            }
        }
        if(beautifulArray.size()%2 != 0){
            elementsDeleted++;
        }
        return elementsDeleted;
    }
};

int main(){
    vector<int> nums = {1,1,2,2,3,3};
    Solution obj;
    auto answer = obj.minDeletion(nums);
    cout << "Answer: " << answer << endl;
    return 0;
}