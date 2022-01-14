#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> tripData;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<tripData, vector<tripData>, greater<tripData>> startData;
        priority_queue<tripData, vector<tripData>, greater<tripData>> endData;
        int n = trips.size();
        for(int i=0; i<n; i++){
            int passengersInTrip = trips[i][0];
            int sourceOfTrip = trips[i][1];
            int destinationOfTrip = trips[i][2];
            startData.push({sourceOfTrip, passengersInTrip});
            endData.push({destinationOfTrip, passengersInTrip});
        }
        int curCapacity = 0;
        while(!startData.empty()){
            pair<int, int> tmpStartData = startData.top();
            startData.pop();
            int curPassengers = tmpStartData.second;
            int curSource = tmpStartData.first;
            
            while(!endData.empty() && endData.top().first <= curSource){
                curCapacity-=endData.top().second;
                endData.pop();
            }
            if(curCapacity+curPassengers <= capacity){
                curCapacity += curPassengers;
            }
            else{
                return false;
            }
        }
        return true;        
    }
};

int main(){
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    Solution obj;
    int capacity = 5;
    auto answer= obj.carPooling(trips, capacity);
    cout << "Answer: " << answer << endl;
}