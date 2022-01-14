#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> waitingDays(n, 0);
        stack<int> daysIndex;
        for(int i=0; i<n; i++){
            while(!daysIndex.empty() && temperatures[daysIndex.top()] < temperatures[i]){
                waitingDays[daysIndex.top()] = i-daysIndex.top();
                daysIndex.pop();
            }
            daysIndex.push(i);
        }
        return waitingDays;
    }
};

int main(){
    Solution obj;
    vector<int> grid = {73,74,75,71,69,72,76,73};

    auto answer = obj.dailyTemperatures(grid);
    for(auto i:answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}