#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int toInt(string intInString){
        int answer = 0;
        int n = intInString.size();
        for(int i=0; i<n; i++){
            answer = answer*10+intInString[0];
        }
        return answer;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> durationIDs(n, 0);
        int logsSize = logs.size();
        vector<string> logDetails = {};
        string intermediate;
        stack<pair<int, int>> jobIDTimes;
        for(int i=0; i<logsSize; i++){
            logDetails.clear();
            stringstream logEvent(logs[i]);
            while(getline(logEvent, intermediate, ':')){
                logDetails.push_back(intermediate);
            }
            int jobID = stoi(logDetails[0]);
            int curTime = stoi(logDetails[2]);
            string event = logDetails[1];
            if(event == "start"){
                jobIDTimes.push({jobID, curTime});
            }
            else{
                auto curData = jobIDTimes.top();
                jobIDTimes.pop();
                int duration = curTime-curData.second+1;
                durationIDs[curData.first]+=duration;
                if(!jobIDTimes.empty()){
                    durationIDs[jobIDTimes.top().first]-=duration;
                }
            }
        }
        return durationIDs;        
    }
};

int main(){
    vector<string>logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    int n = 2;
    Solution obj;
    auto answer = obj.exclusiveTime(n, logs);
    cout << "Answer: " ;
    for(auto i:answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}