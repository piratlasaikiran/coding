#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int curMax = prices[0];
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>curMax){
                curMax = prices[i];
                profit += curMax-curMin;
                curMin = prices[i];
            }
            else{
                curMin = curMax = prices[i];
            }
        }
        return profit;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,3,7,5,10,3};
    auto answer = obj.maxProfit(nums);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}