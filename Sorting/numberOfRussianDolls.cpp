#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> env;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        priority_queue<env, vector<env>, greater<env>> dimensions;
        int n = envelopes.size();
        for(int i=0; i<n; i++){
            dimensions.push({envelopes[i][0], envelopes[i][1]});
        }
        vector<pair<int, int>> dimVec;
        while(!dimensions.empty()){
            dimVec.push_back(dimensions.top());
            cout << dimensions.top().first << " " << dimensions.top().second << endl;
            dimensions.pop();
        }
        int answer=1;
        int prevIndex = 0;
        for(int curIndex=1; curIndex<n; curIndex++){
            if((dimVec[curIndex].first > dimVec[prevIndex].first) && (dimVec[curIndex].second > dimVec[prevIndex].second)){
                prevIndex++;
                answer++;
            }
            if()
        }
        return answer;

    }
};

int main(){
    Solution obj;
    vector<vector<int>> envelopes = {{4,5},{4,6},{6,7},{2,3},{1,1},{1,1}};
    auto answer = obj.maxEnvelopes(envelopes);
    cout << "Answer: " << answer << endl;
    return 0;
}