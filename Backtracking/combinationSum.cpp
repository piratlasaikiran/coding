#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> answer;

    void combinationSumHelper(vector<int> curCombination, vector<int>& candidates, int curSum, int targetSum, int curIndex){
        if(curSum == targetSum){
            answer.push_back(curCombination);
            return;
        }
        if(curSum > targetSum){
            return;
        }

        int n = candidates.size();
        for(int i=curIndex; i<n; i++){
            curSum+=candidates[i];
            curCombination.push_back(candidates[i]);
            combinationSumHelper(curCombination, candidates, curSum, targetSum, i);
            curSum-=candidates[i];
            curCombination.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curCombination;
        int curSum = 0;
        combinationSumHelper(curCombination, candidates, curSum, target, 0);
        return answer;
    }
};

int main(){
    vector<int> nums = {2,3,6,7};
    int target = 7;
    Solution obj;
    auto answer = obj.combinationSum(nums, target);
    cout << "Answer:" << endl;
    for(auto i:answer){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}