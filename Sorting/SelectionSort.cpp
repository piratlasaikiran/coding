#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int lowest_index=i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[lowest_index])
                lowest_index = j;
        }
        swap(arr[lowest_index], arr[i]);
    }
}


int main(){
    vector<int> arr = {11,3,6,5,4,9,7,2,1,8,10,12};
    int n = arr.size();
    int low = 0, high = n-1;
    selectionSort(arr);
    for(auto i:arr)
        cout << i << " ";
    cout << endl;

    return 0;
}