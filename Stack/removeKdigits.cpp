#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> digitsRemovedNum;
        int n = num.size();
        for(int i=0; i<n; i++){
            char curDigit = num[i];
            while(k>0 && !digitsRemovedNum.empty() && digitsRemovedNum.top() > curDigit){
                k--;
                digitsRemovedNum.pop();
            }
            digitsRemovedNum.push(curDigit);
        }
        while(k-- > 0){
            digitsRemovedNum.pop();
        }
        string answer;
        while(!digitsRemovedNum.empty()){
            answer.push_back(digitsRemovedNum.top());
            digitsRemovedNum.pop();
        }
        
        reverse(answer.begin(), answer.end());
        cout << "Tmp: " << answer << endl;
        int startIndex=0;
        int answerLen = answer.size();
        for(int i=0; i<answerLen; i++){
            if(answer[i] == '0'){ 
                startIndex = i; 
                continue;
            }
            else{
                startIndex = i;
                break;
            }
        }
        answer = answer.substr(startIndex, answerLen-startIndex);
        if(answer.size() == 0){
            answer = "0";
        }
        return answer;
    }
};

int main(){
    Solution obj;
    string num = "100";
    int k = 1;
    auto answer = obj.removeKdigits(num, k);
    cout << "Answer: " << answer << endl;
    return 0;
}