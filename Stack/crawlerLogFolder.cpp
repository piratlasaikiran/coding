#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> curLocation;
        int n = logs.size();
        for(int i=0; i<n; i++){            
            if(logs[i] == "../"){
                if(!curLocation.empty()){
                    curLocation.pop();
                }
            }
            else if(logs[i] == "./"){
                continue;
            }
            else{
                curLocation.push(logs[i]);
            }
        }
        return curLocation.size();
    }
};

int main(){
    vector<string> logs = {"./","../","./"};
    Solution obj;
    auto answer = obj.minOperations(logs);
    cout << "Answer: " << answer << endl;
    return 0;
}