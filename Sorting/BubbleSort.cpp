#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {11,3,6,5,4,9,7,2,1,8,10,12};
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i;j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }

    for(auto i:arr)
        cout << i << " ";
    cout << endl;

    return 0;
}