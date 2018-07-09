#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int key = arr[low];
    int i = low + 1;
    int j = high;
    while(1){
        while(key >= arr[i])
            i++;

        while(key < arr[j])
            j--;

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else {
            int temp = key;
            arr[low] = arr[j];
            arr[j] = temp;
            return j;

        }
    }
}

void quicksort(int arr[], int low, int high){

    if(low < high){
        int j = partition(arr, low, high);
        quicksort(arr, low, j-1);
        quicksort(arr, j+1, high);
    }
}

int main(){
    int arr[] = {10, 5, 1, -10};
    // cout << sizeof(arr);
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, size-1);
    for(int i=0; i<size;i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
    return 0;
}
