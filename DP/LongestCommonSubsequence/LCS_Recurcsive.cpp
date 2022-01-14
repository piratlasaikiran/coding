#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int LCSRecursice_helper(string s1, string s2, int l1, int l2){
        if(l1==0 || l2==0)
            return 0;
        if(s1[l1-1]==s2[l2-1])
            return 1+LCSRecursice_helper(s1, s2, l1-1, l2-1);
        else
            return max(LCSRecursice_helper(s1, s2, l1-1, l2), LCSRecursice_helper(s1, s2, l1, l2-1));
    }

    int LCSRecursice(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        return LCSRecursice_helper(s1, s2, l1, l2);        
    }
};

int main(){
    Solution obj;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    auto answer = obj.LCSRecursice(s1, s2);
    cout << "Answer is: " << answer << endl;
    return 0;
}