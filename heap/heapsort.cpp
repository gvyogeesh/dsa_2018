/* C++ program to demonstrate Heap Sort */
#include <iostream>
using namespace std;

    int parent(int i){
        return (i-1)/2;

    }

    int left_child(int i){
        return 2*i + 1;
    }

    int right_child(int i)
    {
        return 2*i + 2;
    }
void swap(int &src, int &des){
        int tmp = src;
        src = des;
        des = tmp;
    }

void MinHeapify(int arr[], int i, int size ){

        int lc = left_child(i);
        int rc = right_child(i);
        int small = i;

        if(lc < size && arr[small] > arr[lc]){
             small = lc;
        }
        if(rc < size && arr[small] > arr[rc]){
            small = rc;
        }


        if(small != i && small < size){
           swap(arr[small], arr[i]);
           MinHeapify(arr, small, size);
        }


        return;
    }

void print_ele(int arr[], int size){
        for (int i=0; i<size;i++){
            cout << arr[i] << "   ";
        }
        cout << endl;
    }

void heapsort(int arr[], int size)
{
    for(int i = (size/2 -1); i>=0; i--){
        MinHeapify(arr, i, size);
    }
    return ;
}
int main(){
    int arr[] = {8, 77, 457, 60, 5000, 45000, 890, 654};
    int size = sizeof(arr)/sizeof(arr[0]);
    heapsort(arr, size );
    print_ele(arr, size);
    for(int j=size-1;j>0;j--){
        swap(arr[0], arr[j]);
        MinHeapify(arr,0,j);
    }
    print_ele(arr, size);
    return 0;
}
