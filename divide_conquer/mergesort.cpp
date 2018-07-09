#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int first = start;
    int second = mid+1;
    int temp[end - start + 1];
    int k=0;
    for(int i=start; i <=end; i++){
        //pointer to second sub array goes out of index
        if(second > end){
            temp[k] = arr[first];
            k++;
            first++;
        }
        //pointer to first sub array goes out of index
        else if(first > mid){
            temp[k] = arr[second];
            k++;
            second++;
        }
        //Copy ele of first sub array to temp
        else if(arr[first] < arr[second]){
            temp[k] = arr[first];
            k++;
            first++;
        }
        else {
            temp[k] = arr[second];
            k++;
            second++;
            //Copy ele of second sub array to temp
        }

    }
    for(int x=0;x<k;x++){
        // cout << temp[x] << "  ";
        arr[start] = temp[x];
        start++;
    }
    // cout << endl;
    //copy temp to main arr

    return;
}

void mergesort(int arr[], int low, int high){
    if(low >= high)
        return;
    int mid = (low + high)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);

}
int main(){
    int arr[] = {400, 11,-20};
    // cout << sizeof(arr);
    int size = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, size-1);
    for(int i=0; i<size;i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    return 0;
}
