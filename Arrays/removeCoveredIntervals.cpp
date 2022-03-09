#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int curMaxLeft = -1;
        int curMaxRight = -1;
        int count = 0;
        for(int i=1; i<n; i++){
            if(intervals[i][0] > curMaxLeft && intervals[i][1]){
                count++;
                curMaxLeft = intervals[i][0];
            }
            curMaxRight = max(curMaxRight, intervals[i][1]);
        }
        return count;
    }
};

int main(){
    vector<vector<int>> intervals;
    intervals.push_back({1,4});
    intervals.push_back({3,6});
    intervals.push_back({2,8});
    Solution obj;
    auto answer = obj.removeCoveredIntervals(intervals);
    cout << "Answer: " << answer << endl;
    return 0;
}