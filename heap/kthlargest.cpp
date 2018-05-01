/* Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that ll array elements are distinct.
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 9, 10, 12};
    vector<int> myvector(arr, arr+sizeof(arr)/sizeof(arr[0]));
    // cout << findKthLargest(myvector, 3)<< endl;;
    return 0;
}
