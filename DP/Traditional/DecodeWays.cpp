
//https://www.youtube.com/watch?v=jFZmBQ569So&t=1391s
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i=1; i<n; i++){
            if(s[i]=='0' && s[i-1]=='0')
                dp[i] = 0;
            else if(s[i]=='0' && s[i-1]!='0'){
                if((s[i-1]=='1' || s[i-1]=='2'))
                    dp[i] = dp[i-1];
                else
                    dp[i] = 0;
            }
            else if(s[i]!='0' && s[i-1]=='0')
                dp[i] = dp[i-1];
            else {
                dp[i] = dp[i]+dp[i-1];
                if((s[i-1]=='1' ) || (s[i-1]=='2' && s[i] < '7'))
                    dp[i]+= i>1 ? dp[i-2] : 1;
            }
        }
        return dp[n-1];
    }
};

int main(){
    Solution obj;
    auto answer = obj.numDecodings("226");

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}