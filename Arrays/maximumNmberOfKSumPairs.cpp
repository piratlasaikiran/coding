#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> frequencyKeeper;
        int n = nums.size();
        int maxOperations = 0;
        for(int i=0; i<n; i++){
            frequencyKeeper[nums[i]]++;
        }

        for(auto it : frequencyKeeper){
            if(it.first == k-it.first)
                maxOperations += it.second/2;
            else{
                maxOperations += min(frequencyKeeper[it.first], frequencyKeeper[k-it.first]);
                frequencyKeeper[it.first] = 0;
            }
        }
        return maxOperations;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2};
    int k = 3;
    auto answer = obj.maxOperations(nums, k);
    cout << "Answer: " << answer << endl;
    return 0;
}

