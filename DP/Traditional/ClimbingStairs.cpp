#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> minCost(n+1, 0);
        for(int i=2; i<=n; i++){
            minCost[i] = min(cost[i-1] + minCost[i-1], cost[i-2] + minCost[i-2]);
        }
        return minCost[n];
  
    }
};

    int main(){
    Solution obj;
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    auto answer = obj.minCostClimbingStairs(cost);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}
/*
i = 0  1  2 
c = 10 15 20
m = 0  0  
*/