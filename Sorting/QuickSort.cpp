#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low<high){
        int pivot = findPivot(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    vector<int> arr = {11,3,6,5,4,9,7,2,1,8,10,12};
    int n = arr.size();
    int low = 0, high = n-1;
    quickSort(arr, low, high);
    for(auto i:arr)
        cout << i << " ";
    cout << endl;

    return 0;
}