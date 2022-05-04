#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> givenChars = {};
        for(int i=0; i<n; i++){
            char curChar = s[i];
            if(curChar == 'c'){
                if(!givenChars.empty()){
                    char topMostChar = givenChars.top();
                    givenChars.pop();
                    if(topMostChar=='b' && !givenChars.empty() && givenChars.top()=='a'){
                        givenChars.pop();
                        continue;
                    }
                    else{
                        givenChars.push(topMostChar);
                    }
                }
            }
            givenChars.push(curChar);
        }
        return givenChars.empty();
    }
};

int main(){
    string s = "aabcbc";
    Solution obj;
    auto answer = obj.isValid(s);
    cout << "Answer: " << answer << endl;
    return 0;
}