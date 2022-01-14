#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> rightLeftMax(n, 0);
        rightLeftMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightLeftMax[i] = max(rightLeftMax[i+1], height[i]);
        }
        vector<int> leftRightMax(n, 0);
        leftRightMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftRightMax[i] = max(leftRightMax[i-1], height[i]);
        }
       
        int waterCollected=0;
        for(int i=0; i<n; i++){
            int minBuilding = min(leftRightMax[i], rightLeftMax[i]);
            if(minBuilding>height[i])
                waterCollected+=(minBuilding-height[i]);
        }
        return waterCollected;
        
    }
};

int main(){
    Solution obj;
    vector<int> nums = {3,1,2,4,0,1,3,2};
    auto answer = obj.trap(nums);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}