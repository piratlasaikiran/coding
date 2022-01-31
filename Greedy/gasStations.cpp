#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalExcessFuel = 0;
        int curExcessFuel = 0;
        int indexFinshingGoal = 0;
        int n = gas.size();
        for(int i=0; i<n; i++){
            int excessFuelAtPos = gas[i] - cost[i];
            curExcessFuel+=excessFuelAtPos;
            if(curExcessFuel<0){
                curExcessFuel = 0;
                indexFinshingGoal = i+1;
            }
            totalExcessFuel+=excessFuelAtPos;
        }
        return totalExcessFuel<0 ? -1 : indexFinshingGoal;
    }
};

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    Solution obj;
    auto answer = obj.canCompleteCircuit(gas, cost);
    cout << "Answer: " << answer << endl;
    return 0;
}