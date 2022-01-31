#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Atmost you can hold one stock unit at any time.
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int lowestPrice = prices[0];
        int profit=0;
        for(int i=1; i<n; i++){
            profit = max(profit, prices[i]-lowestPrice);
            lowestPrice = min(lowestPrice, prices[i]);
        }
        
        return profit;
    }

    // you can make any transactions, but atmost you can hold one stock unit
    int maxProfit2(vector<int>& prices) {
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

    //Buy and sell with cool down
    //https://www.youtube.com/watch?v=GY0O57llkKQ
    int maxProfit3(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> DayState(n, vector<int>(3, 0)); // 0 -> Buy, 1-> Sell, 2-> Cooldown
        DayState[0][0] = -1*prices[0];
        for(int i=1; i<n; i++){
            DayState[i][0] = max(DayState[i-1][0], DayState[i-1][2]-prices[i]);
            DayState[i][1] = max(DayState[i-1][1], DayState[i-1][0]+prices[i]);
            DayState[i][2] = max(DayState[i-1][2], DayState[i-1][1]);
        }
        return DayState[n-1][1];
    }

    //Buy and sell with transaction fee
    int maxProfit4(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> DayState(n, vector<int>(2, 0)); // 0 -> Buy, 1-> Sell, 2-> Cooldown
        DayState[0][0] = -1*prices[0];
        for(int i=1; i<n; i++){
            DayState[i][0] = max(DayState[i-1][0], DayState[i-1][1]-prices[i]);
            DayState[i][1] = max(DayState[i-1][1], DayState[i-1][0]+prices[i]-fee);
        }
        return DayState[n-1][1];
    }
};

    int main(){
    Solution obj;
    vector<int> nums = {1,3,7,5,10,3};
    auto answer = obj.maxProfit4(nums, 3);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}