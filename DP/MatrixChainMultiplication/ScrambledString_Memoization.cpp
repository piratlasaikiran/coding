#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dp;
class Solution{
    public:

    int ScrambledStringRecursive(string s1, string s2){      
        int n=s1.size();
        if(dp.count(s1+"_"+s2) != 0)
            return dp[s1+"_"+s2];

        if(s1.size()<=0 || s2.size()<=0 || s1.size()!=s2.size())
            return false;

        if(s1.compare(s2) == 0)
            return dp[s1+"_"+s2] = true;

        for(int i=1; i<n; i++){
            if((ScrambledStringRecursive(s1.substr(0, i), s2.substr(n-i, i)) && ScrambledStringRecursive(s1.substr(i, n-i), s2.substr(0, n-i))) || (ScrambledStringRecursive(s1.substr(0, i), s2.substr(0, i)) && ScrambledStringRecursive(s1.substr(i, n-i), s2.substr(i, n-i))))
                return dp[s1+"_"+s2] = true;
        }
        return dp[s1+"_"+s2] = false;

    }
};

int main(){
    Solution obj;
    string s1 = "great";
    string s2 = "rgate";
    auto answer = obj.ScrambledStringRecursive(s1, s2);
    cout << "Answer is: " << answer << endl;
    return 0;
}