#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int dp[101][1001];
    int memoize(vector<int>& values, vector<int>& weights, int weight, int n)
    {
        if(n==0 || weight==0)
            return 0;

        if(dp[n][weight] != -1)
            return dp[n][weight];

        if(weights[n] <= weight){
            return dp[n][weight] = max((values[n] + memoize(values, weights, weight-weights[n], n-1)), memoize(values, weights, weight, n-1));
        }
        else{
            return dp[n][weight] = memoize(values, weights, weight, n-1);
        }
    }
    int maxProfit(vector<int>& values, vector<int>& weights, int weight, int n) 
    {
        memset(dp, -1, sizeof(dp));
        return memoize(values, weights, weight, n);

    }
};
int main(){
    Solution obj;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int weight = 50;
    int n = values.size();
    auto answer = obj.maxProfit(values, weights, weight, n);
    cout << "Answer is: " << answer << endl;
    
    return 0;
}