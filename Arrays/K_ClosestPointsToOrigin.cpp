#include <bits/stdc++.h>
using namespace std;
typedef pair<float, pair<int, int>> pointDist;

class Solution {
public:

    float calculateDistanceFromOrigin(int x, int y){
        float distance = sqrt(x*x + y*y);
        return distance;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pointDist, vector<pointDist>, greater<pointDist>> indexedData;
        int n = points.size();
        for(int i=0; i<n; i++){
            float curPointDist = calculateDistanceFromOrigin(points[i][0], points[i][1]);
            indexedData.push({curPointDist, {points[i][0], points[i][1]}});
        }
        vector<vector<int>> answer;
        while(k-- > 0){
            auto kthPoint = indexedData.top();
            indexedData.pop();
            answer.push_back({kthPoint.second.first, kthPoint.second.second});
        }
        return answer;
        
    }
};

int main(){
    Solution obj;
    vector<vector<int>> points = {{9997, 9997}, {9996, 9998}};
    auto answer = obj.kClosest(points, 1);
    for(auto i: answer){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}