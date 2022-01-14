#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRod(vector<int>& price, int max_len) {
        int n = price.size();
        int dp[n+1][max_len+1];
        vector<int> values(n, 0);
        for(int i=0; i<n; i++){
            values[i] = i+1;
            cout << values[i] << " " ;
        }
        cout << endl;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<max_len+1; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(values[i-1] <= j)
                    dp[i][j] = max(price[i-1]+dp[i][j-values[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][max_len];
    }
};

int main(){
    Solution obj;
    vector<int> price = {1,5,8,9,10,17,17,20};
    auto answer = obj.cutRod(price, 8);
    cout << "Answer is: " << answer << endl;
    return 0;
}