/* A sorted array is rotated at some unknown point, find the minimum element in it.

Following solution assumes that all elements are distinct.

Examples

Input: {5, 6, 1, 2, 3, 4}
Output: 1

Input: {1, 2, 3, 4}
Output: 1

Input: {1}
Output: 1

Input: {1, 2}
Output: 1

Input: {2, 1}
Output: 1

Input: {5, 6, 7, 1, 2, 3, 4}
Output: 1

Input: {1, 2, 3, 4, 5, 6, 7}
Output: 1

Input: {2, 3, 4, 5, 6, 7, 8, 1}
Output: 1

Input:  {3, 4, 5, 1, 2}
Output: 1

*/

#include <iostream>
using namespace std;

int getmin(int arr[], int low ,int high){
    if(low == high){
       return arr[low];
    }
    //Not rotated
    if(arr[low] < arr[high])
        return arr[low];

    int mid = (low+high)/2;

    if(arr[mid-1] > arr[mid])
        return arr[mid];

    if(mid < high && arr[mid+1] < arr[mid])
        return arr[mid+1];


    if(arr[mid] > arr[high])
        return getmin(arr, mid+1, high);
    else
        return getmin(arr, low, mid-1);

}

int main(){
    int arr[] = {3, 4, 5, 1, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << getmin(arr, 0, size-1) << endl;
    return 0;

}

