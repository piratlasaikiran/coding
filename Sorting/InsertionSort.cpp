#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {11,3,6,5,4,9,7,2,1,8,10,12};
    int n = arr.size();
    int key, j;
    for(int i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(auto i:arr)
        cout << i << " ";
    cout << endl;

    return 0;
}