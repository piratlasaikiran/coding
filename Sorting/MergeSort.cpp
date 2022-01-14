#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high){
    int subArray1Size = mid-low+1;
    int subArray2Size = high-mid;

    vector<int> leftArray(subArray1Size);
    vector<int> rightArray(subArray2Size);

    for(int i=0; i<subArray1Size; i++){
        leftArray[i] = arr[low+i];
    }
    for(int i=0; i<subArray2Size; i++){
        rightArray[i] = arr[mid+1+i];
    }
    int indexSubArray1=0, indexSubArray2=0, indexMergedArray=low;

    while(indexSubArray1 < subArray1Size && indexSubArray2 < subArray2Size){
        if(leftArray[indexSubArray1] <= rightArray[indexSubArray2]){
            arr[indexMergedArray] = leftArray[indexSubArray1];
            indexSubArray1++;
        }
        else{
            arr[indexMergedArray] = rightArray[indexSubArray2];
            indexSubArray2++;
        }
        indexMergedArray++;
    }

    while(indexSubArray1 < subArray1Size){
        arr[indexMergedArray] = leftArray[indexSubArray1];
        indexSubArray1++;
        indexMergedArray++;
    }

    while(indexSubArray2 < subArray2Size){
        arr[indexMergedArray] = rightArray[indexSubArray2];
        indexSubArray2++;
        indexMergedArray++;
    }


}

void mergeSort(vector<int>& arr, int low, int high){
    if(low>=high)
        return;

    int mid = low+(high-low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}


int main(){
    vector<int> arr = {11,3,6,5,4,9,7,2,1,8,10,12};
    int n = arr.size();
    int low = 0, high = n-1;
    mergeSort(arr, low, high);
    for(auto i:arr)
        cout << i << " ";
    cout << endl;

    return 0;
}