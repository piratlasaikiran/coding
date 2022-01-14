#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(i<n-1 && intervals[i+1][0] <= end){
                end = max(end, intervals[i+1][1]);
                i++;
            }
            answer.push_back({start, end});
        }
        return answer;
    }
};

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution obj;
    auto answer = obj.merge(intervals);
    cout << "Answer: " << endl;
    for(auto i:answer){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}