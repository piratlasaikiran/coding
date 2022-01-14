#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1] = {0};

        for(int i=0; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(i==0)
                    dp[i][j] = INT_MAX-1;
                if(j==0)
                    dp[i][j] = 0;
            }
        }

        for(int j=1; j<=amount; j++){
            if(j%coins[0] == 0)
                dp[1][j] = j/coins[0];
            else
                dp[1][j] = INT_MAX-1;  
        }

        for(int i=2; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            }
        }
        return dp[n][amount];
        
    }
};

int main(){
    Solution obj;
    vector<int> coins = {1,2,5};
    auto answer = obj.coinChange(coins, 11);
    cout << "Answer is: " << answer << endl;
    return 0;
}