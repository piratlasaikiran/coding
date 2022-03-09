#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = t.size();
        vector<int> freqCounter(26, 0);
        for(int i=0; i<n; i++){
            freqCounter[t[i]-'a']++;
        }
        for(int i=0; i<n-1; i++){
            freqCounter[s[i]-'a']--;
        }
        char answer;
        for(int i=0; i<26; i++){
            cout << i << endl;
            if(freqCounter[i] != 0){
                answer = i+'a';
                break;
            }
        }
        return answer;
        
    }
};

int main(){
    Solution obj;
    string s = "abcd";
    string t = "abcde";
    auto answer = obj.findTheDifference(s, t);
    cout << "Answer: " << answer << endl;
    return 0;
}