//https://www.youtube.com/watch?v=aVIFpdAg33U

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int modulo = 1e9+7;
    int numTilings(int n) {
        if(n==0 || n==1 || n==2)
            return n;

        vector<long long int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for(int i=4; i<=n; i++){
            dp[i] = 2*dp[i-1] + dp[i-3];
        }

        return dp[n]%modulo;
    }
};

int main(){
    Solution obj;
    auto answer = obj.numTilings(30);
    cout << "Answer: " << answer << endl;
    return 0;
}