#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> meetingData;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> meetingTimingsWithPerson(n);
        priority_queue<meetingData, vector<meetingData>, greater<meetingData> > timelyMeetings;
        int totalMeetings = meetings.size();
        int latestMeeting = INT_MIN;
        for(int i=0; i<totalMeetings; i++){
            timelyMeetings.push({meetings[i][2], {meetings[i][0], meetings[i][1]}});
            latestMeeting = max(latestMeeting, meetings[i][2]);
        }
        vector<int> answer;
        vector<bool> knowsSecret(n);
        knowsSecret[0] = knowsSecret[firstPerson] = true;
        while(!timelyMeetings.empty()){
            meetingData personToPersonMeet = timelyMeetings.top();
            timelyMeetings.pop();
            int person1 = personToPersonMeet.second.first;
            int person2 = personToPersonMeet.second.second;
            if(knowsSecret[person1]){
                knowsSecret[person2] = true;
            }
            else if(knowsSecret[person2]){
                knowsSecret[person1] = true;
            }
        }
        for(int i=0; i<n; i++){
            if(knowsSecret[i]){
                answer.push_back(i);
            }
        }
        return answer;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> meetings =  {{1,2,5},{2,3,8},{1,5,10}};
    auto answer = obj.findAllPeople(6, meetings, 1);
    for(auto i:answer)
        cout << i << " ";
    cout << endl;
    return 0;
}