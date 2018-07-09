#include <iostream>
using namespace std;

bool binsearch(int arr[], int low ,int high, int key){
    if(low == high){
        if(arr[low] == key)
            return true;
        else
            return false;
    }
    int mid = (low+high)/2;
    if (key == arr[mid])
        return true;
    if(key < arr[mid])
        return binsearch(arr, low, mid-1, key);
    else
        return binsearch(arr, mid+1, high, key);
    return false;

}

int main(){
    int arr[] = {10, 20, 30};
    int size = sizeof(arr)/sizeof(arr[0]);
    if(binsearch(arr, 0, size-1, 1000))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}
