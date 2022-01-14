#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string s){
        int n = s.size();
        if(n == 1)
            return true;
        for(int i=0; i<=n/2; i++){
            if(s[i] != s[n-1-i]){
                return false;
            }
        }
        return true;
    }

    void partitionHelper(int curPos, string s, vector<vector<string>>& answer, vector<string>& onePossibility){
        int n = s.size();
        if(n==curPos){
            answer.push_back(onePossibility);
            return;
        }
        for(int i=curPos+1, count=1; i<=n && curPos+count<=n; i++, count++){
            string tmpStr = s.substr(curPos, count);
            if(isPalindrome(tmpStr)){
                onePossibility.push_back(tmpStr);
                partitionHelper(i, s, answer, onePossibility);
                onePossibility.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> onePossibility = {};
        partitionHelper(0, s, answer, onePossibility);
        return answer;
    }
};

int main(){
    string s = "saikiran";
    Solution obj;
    auto answer = obj.partition(s);
    for(auto i:answer){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}