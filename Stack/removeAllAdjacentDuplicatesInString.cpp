#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void popKTimes(stack<pair<char, int>> &duplicateCounter, int k){
        while(k-- > 0){
            duplicateCounter.pop();
        }
    }

    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>> duplicateCounter;
        for(int i=0; i<n; i++){
            if(duplicateCounter.empty()){
                duplicateCounter.push({s[i], 1});
            }
            else{
                if(duplicateCounter.top().first == s[i]){
                    if(duplicateCounter.top().second == k-1){
                        popKTimes(duplicateCounter, k-1);
                    }
                    else{
                        duplicateCounter.push({s[i], duplicateCounter.top().second+1});
                    }
                }
                else{
                    duplicateCounter.push({s[i], 1});
                }
            }
        }
        string answer = "";
        while(!duplicateCounter.empty()){
            answer.push_back(duplicateCounter.top().first);
            duplicateCounter.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main(){
    Solution obj;
    string s = "deeedbbcccbdaa";
    auto answer = obj.removeDuplicates(s, 3);
    cout << "Answer:  " << answer << endl;
    return 0;
}