// https://www.youtube.com/watch?v=XZueXHOhO5E
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0;
        int maxImpact = 0;
        for(int i=0; i<n; i++){
            maxImpact = max(maxImpact, arr[i]);
            if(maxImpact == i)
                chunks++;
        }
        return chunks!=0 ? chunks : 1;
    }

    int maxChunksToSorted2(vector<int>& arr) {
        
    }
};

int main(){
    vector<int> arr = {1,2,0,3};
    Solution obj;
    auto answer = obj.maxChunksToSorted(arr);
    cout << "Answer: " << answer << endl;
    return 0;
}