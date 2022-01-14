#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int MaxEndingHere=0;
        int MaxSum = INT_MIN;
        for(int i=0; i<n; i++){
            MaxEndingHere += nums[i];
            if(MaxEndingHere < nums[i])
                MaxEndingHere = nums[i];
            if(MaxSum < MaxEndingHere)
                MaxSum = MaxEndingHere;
        }
        return MaxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int MaxEndingHere=0;
        int MaxSum = INT_MIN;
        int CyclicIterMax = INT_MIN;
        int j=0;
        while(j<n){
            MaxEndingHere=0;
            for(int i=0; i<n; i++){
                MaxEndingHere += nums[(i+j)%n];
                if(MaxEndingHere < nums[(i+j)%n])
                    MaxEndingHere = nums[(i+j)%n];
                if(MaxSum < MaxEndingHere)
                    MaxSum = MaxEndingHere;
            }
            j++;
            CyclicIterMax = max(CyclicIterMax, MaxSum);
        }
        return MaxSum;
    }
};

    int main(){
    Solution obj;
    vector<int> nums = {3,-1,2,-1};
    auto answer = obj.maxSubarraySumCircular(nums);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}