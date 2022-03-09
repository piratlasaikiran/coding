#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void subsetMaker(vector<int>& nums, vector<int> curSet, vector<vector<int>> &answer, int index){
        int n = nums.size();
        if(index > n){
            return;
        }
        answer.push_back(curSet);

        for(int i=index; i<n; i++){
            curSet.push_back(nums[i]);
            subsetMaker(nums, curSet, answer, i+1);
            curSet.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> curSet;
        subsetMaker(nums, curSet, answer, 0);
        return answer;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution obj;
    auto answer = obj.subsets(nums);
    cout << "Answer: " << endl;
    for(auto i:answer){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}