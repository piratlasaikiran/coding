#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> result(target + 1);
        result[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i >= x) result[i] += result[i - x];
            }
        }
        
        return result[target];
    }
};

int main(){
    Solution obj;
    vector<int> coins = {1,2,5};
    auto answer = obj.combinationSum4(coins, 5);
    cout << "Answer is: " << answer << endl;
    return 0;
}