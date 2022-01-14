#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outDegree(n+1, 0);
        vector<int> inDegree(n+1, 0);
        int trustSize = trust.size();
        for(int i=0; i<trustSize; i++){
            outDegree[trust[i][0]]++;
            inDegree[trust[i][1]]++;
        }
        for(int i=1; i<n+1; i++){
            if(outDegree[i]==0 && inDegree[i]==n-1){
                return i;
            }
        }
        return -1;
        
    }
};

int main(){
    Solution obj;
    vector<vector<int>> trust = {{1,3}, {2,3}};
    auto answer = obj.findJudge(3, trust);
    cout << "Answer: " << answer << endl;
    return 0;
}