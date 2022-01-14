#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> messageFlow(n+1);
        int totalMessages = times.size();
        for(int i=0; i<totalMessages; i++){
            messageFlow[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> minTime(n+1, 101);
        vector<bool> visited(n+1, false);
        priority_queue<pi, vector<pi>, greater<pi>> dijkshtraQueue;
        dijkshtraQueue.push({0, k});
        minTime[k] = 0;

        while(!dijkshtraQueue.empty()){
            pair<int, int> sourceData = dijkshtraQueue.top();
            dijkshtraQueue.pop();
            int curTime = sourceData.first;
            int source = sourceData.second;
            if(visited[source])
                continue;
            vector<pair<int, int>> possibleSources = messageFlow[source];
            for(auto it:possibleSources){
                if(minTime[it.first] > curTime+it.second){
                    minTime[it.first] = curTime+it.second;
                    dijkshtraQueue.push({curTime+it.second, it.first});
                }
            }
            visited[source] = true;
        }
        int maxTimeRequired = *max_element(minTime.begin()+1, minTime.end());

        if(maxTimeRequired >= 101)
            return -1;
        return maxTimeRequired;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> times = {{4,2,76},{1,3,79},{3,1,81},{4,3,30},{2,1,47},{1,5,61},{1,4,99},{3,4,68},{3,5,46},{4,1,6},{5,4,7},{5,3,44},{4,5,19},{2,3,13},{3,2,18},{1,2,0},{5,1,25},{2,5,58},{2,4,77},{5,2,74}};
    auto answer = obj.networkDelayTime(times, 5, 3);
    cout << "Answer: " << answer << endl;
    return 0;
}