#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Jump Game
    // bool canJump(vector<int>& nums) {
    //     int reachableIndex=0;
    //     int n = nums.size();
    //     for(int i=0; i<n; i++){
    //         if(reachableIndex<i)
    //             return false;
    //         reachableIndex = max(reachableIndex, i+nums[i]);
    //     }
    //     return true;
    // }

    // Jump Game II
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int reachableMax=nums[0], steps=1, currentPos=0;
        while(reachableMax<n-1){
            int maxdis=reachableMax;
            for(int i=currentPos; i<=maxdis; i++){
                if(i+nums[i] > reachableMax){
                    currentPos = i;
                    reachableMax = i+nums[i];
                }
            }
            steps++;
        }
        return steps;
    }
};

    int main(){
    Solution obj;
    vector<int> nums = {3,4,3,2,5,4,3};
    auto answer = obj.jump(nums);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}