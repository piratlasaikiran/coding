#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int calculateHoursReqWithSpeed(vector<int>& piles, int eatingSpeed){
        int hoursRequired = 0;
        int n = piles.size();
        for(int i=0; i<n; i++){
            hoursRequired+=ceil(piles[i]/eatingSpeed);
            if(piles[i]%eatingSpeed != 0){
                hoursRequired++;
            }
        }
        return hoursRequired;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPileSize = *max_element(piles.begin(), piles.end());
        int lowSpeed = 1;
        int highSpeed = maxPileSize;
        int minRequiredSpeed = highSpeed;
        if(h == piles.size()){
            return minRequiredSpeed;
        }
        while(lowSpeed <= highSpeed){
            int curSpeed = lowSpeed + (highSpeed - lowSpeed)/2;
            int hoursRequired = calculateHoursReqWithSpeed(piles, curSpeed);
            if(hoursRequired <= h){
                highSpeed = curSpeed - 1;
                minRequiredSpeed = curSpeed;
            }
            else{
                lowSpeed = curSpeed + 1;    
            }
        }
        return minRequiredSpeed;       

    }
};

int main(){
    vector<int> piles = {312884470};
    int hours = 968709470;
    Solution obj;
    auto answer = obj.minEatingSpeed(piles, hours);
    cout << "Answer: " << answer << endl;
}