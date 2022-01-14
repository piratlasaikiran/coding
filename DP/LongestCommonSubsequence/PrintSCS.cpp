#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1=str1.size();
        int l2=str2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=0; i<=l1; i++){
            for(int j=0; j<=l2; j++){
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1]);
            }
        }
        string answer="";
        int i=l1, j=l2;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                answer.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                answer.push_back(str2[j-1]);
                j--;
            }
            else{
                answer.push_back(str1[i-1]);
                i--;
            }
        }
        while(i>0){
            answer.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            answer.push_back(str2[j-1]);
            j--;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main(){
    Solution obj;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    auto answer = obj.shortestCommonSupersequence(s1, s2);
    cout << "Answer is: " << answer << endl;
    return 0;
}