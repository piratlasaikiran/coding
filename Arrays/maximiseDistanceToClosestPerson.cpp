#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int curDistance = 0;
        int curStart = 0;
        int bestDistance = 0;
        int n = seats.size();
        for(int curEnd = 0; curEnd < n; curEnd++){
            if(seats[curEnd] == 1){
                curStart = curEnd + 1;
                curDistance = 0;
            }
            else{
                curDistance++;
                if(curStart == 0 || curEnd == n-1){
                    bestDistance = max(bestDistance, curDistance);
                }
                else{
                    bestDistance = max(bestDistance, (curDistance+1)/2);
                }
            }
        }
        return bestDistance;
    }
};