#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MCM_Recursive(int arr[], int i, int j) {
        if(i>=j)
            return 0;

        int ans=INT_MAX;
        for(int k=i; k<=j-1; k++){
            ans = min(ans, MCM_Recursive(arr, i, k) + MCM_Recursive(arr, k+1, j) + arr[i-1]*arr[j]*arr[k]);
        }
        return ans;

    }
};

int main(){
    Solution obj;
    int arr[] = {1,2,3,4,3};
    int l = sizeof(arr)/sizeof(arr[0]);
    auto answer = obj.MCM_Recursive(arr, 1 , l-1);
    cout << "Answer is: " << answer << endl;
    return 0;
}