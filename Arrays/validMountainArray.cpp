#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return false;
        bool increasing = true;
        bool decreasing = false;
        bool incrementDone = false;
        for(int i=1; i<n; i++){
            if(arr[i]-arr[i-1]>0 && increasing){
                incrementDone = true;
                continue;
            }
            else if(arr[i]-arr[i-1] <0 && increasing && !decreasing){
                increasing = false;
                decreasing = true;
            }
            else if(arr[i]-arr[i-1] < 0 && decreasing){
                continue;
            }
            else{
                return false;
            }
        }
        return !increasing && decreasing && incrementDone;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {9,8,7,6,5,4,3,2,1,0};
    auto answer = obj.validMountainArray(arr);
    cout << "Answer: " << answer << endl;
    return 0;
}