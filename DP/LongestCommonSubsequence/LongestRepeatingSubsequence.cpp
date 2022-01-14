#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestRepeatingSubsequence(string str) {
        int l1=str.size();
        string s2 = str;
        int l2=s2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(str[i-1]==s2[j-1] && i!=j)
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
    string s1 = "AABEBCDD";
    auto answer = obj.longestRepeatingSubsequence(s1);
    cout << "Answer is: " << answer << endl;
    return 0;
}