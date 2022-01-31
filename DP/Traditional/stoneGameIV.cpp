#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool winnerSquareGameHelper(int n, vector<int>& dp) {
        if(n==0)
            return false;
        if(dp[n] != -1)
            return dp[n];
        bool winner = false;
        for(int i=1; i*i<=n; i++){
            if(!winnerSquareGameHelper(n-i*i, dp)){
                winner = true;
                break;
            }
        }
        return dp[n] = winner;
    }

    bool winnerSquareGame(int n){
        vector<int> dp(100000, -1);
        return winnerSquareGameHelper(n, dp);
    }
};

int main(){
    Solution obj;
    auto answer = obj.winnerSquareGame(4);
    cout << "Answer: " << answer << endl;
    return 0;
}