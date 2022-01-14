#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l1=s.size();
        string s2 = s;
        reverse(s.begin(), s.end());
        int l2=l1;
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=0; i<=l1; i++){
            for(int j=0; j<=l2; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
            }
        }

        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(s[i-1]==s2[j-1])
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
    string s1 = "AGBCBA";
    auto answer = obj.longestPalindromeSubseq(s1);
    cout << "Answer is: " << answer << endl;
    return 0;
}