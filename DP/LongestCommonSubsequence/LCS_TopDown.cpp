#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int LCSTopDown(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=0; i<=l1; i++){
            for(int j=0; j<=l2; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
            }
        }

        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[l1][l2];
    }
};

int main(){
    Solution obj;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    auto answer = obj.LCSTopDown(s1, s2);
    cout << "Answer is: " << answer << endl;
    return 0;
}