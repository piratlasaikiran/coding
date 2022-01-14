#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        string s2 = s;
        reverse(s.begin(), s.end());
        int l1=s.size();
        int l2=s2.size();

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(s[i-1] == s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int palindrome_length = dp[l1][l2];

        return s.size() - palindrome_length;        
    }
};

int main(){
    Solution obj;
    string s1 = "AABEBCDD";
    auto answer = obj.minInsertions(s1);
    cout << "Answer is: " << answer << endl;
    return 0;
}