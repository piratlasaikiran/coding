#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string printLCS(string s1, string s2) {
        int l1=s1.size();
        int l2=s2.size();

        vector<vector<string>> dp(l1+1, vector<string>(l2+1, ""));
        for(int i=0; i<=l1; i++){
            for(int j=0; j<=l2; j++){
                if(i==0 || j==0)
                    dp[i][j] = "";
            }
        }

        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
              if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                else
                    dp[i][j] = dp[i-1][j].size()>dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1];
            }
        }
        return dp[l1][l2];

    }
};

int main(){
    Solution obj;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    auto answer = obj.printLCS(s1, s2);
    cout << "Answer is: " << answer << endl;
    return 0;
}