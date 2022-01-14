#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> balloonData;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<balloonData, vector<balloonData>, greater<balloonData>> increasingStartOfBalloon;
        int n = points.size();
        for(int i=0; i<n; i++){
            increasingStartOfBalloon.push({points[i][0], points[i][1]});
        }
        int arrowsRequired = 0;
        int curArrowPosition = INT_MIN;
        while(!increasingStartOfBalloon.empty()){
            balloonData curBalloonCordinates = increasingStartOfBalloon.top();
            increasingStartOfBalloon.pop();
            int balloonStart = curBalloonCordinates.first;
            int balloonEnd = curBalloonCordinates.second;
        
            if(INT_MIN == balloonStart){
                arrowsRequired++;
                curArrowPosition = balloonEnd;
            }
            if(curArrowPosition < balloonStart){
                arrowsRequired++;
                curArrowPosition = balloonEnd;
            }
            else if(curArrowPosition >= balloonStart && curArrowPosition <= balloonEnd){
                continue;
            }
            else if(curArrowPosition > balloonStart && curArrowPosition > balloonEnd){
                curArrowPosition = balloonEnd;
            }
            
        }
        return arrowsRequired;

    }
};

int main(){
    Solution obj;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    auto answer = obj.findMinArrowShots(points);
    cout << "Answer: " << answer << endl;
    return 0;
}