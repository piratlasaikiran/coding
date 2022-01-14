#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int PalindromePartition_Recursive(string s, int i, int j){
        if(i>j || isPalindrome(s, i, j))
            return 0;
        int ans=INT_MAX;
        for(int k=i; k<j; k++){
            ans = min(ans, PalindromePartition_Recursive(s, i, k)+PalindromePartition_Recursive(s, k+1, j)+1);
        }
        return ans;

    }
};

int main(){
    Solution obj;
    string s = "nitin";
    auto answer = obj.PalindromePartition_Recursive(s, 0, s.size()-1);
    cout << "Answer is: " << answer << endl;
    return 0;
}