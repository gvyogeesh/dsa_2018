#include <iostream>
#include <climits>
using namespace std;

class MinHeap{
    int size;
    int capacity;
    int *arr;
public:
    MinHeap(int num){
        arr = new int[num];
        capacity = num;
        size = 0;
    }
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
    void insert(int ele){
        if(size == capacity){
            cout << "Overflow" << endl;
            return;
        }
        size++;
        arr[size-1] = ele;
        int i = size-1;
        int pi = parent(i);

        // cout << arr[pi]  << arr[i] << endl;
        while(i != 0 && arr[pi] > arr[i]){
            swap(arr[i], arr[pi]);
            i = pi;
            pi = parent(i);
        }

        return;
    }

   //Get Minimum value
    int top(){
        return arr[0];
    }
    //Remove minimum value and return the same
    int pop(){
        swap(arr[0], arr[size-1]);
        size--;
        // MinHeapify(0);
        MinHeapify_iter(0);

        return 0;
    }

    int delete_idx(int i){
        int item = i;
        arr[i] = INT_MIN;
        int pi= parent(i);
        while(i != 0 && arr[pi] > arr[i]){
            swap(arr[i], arr[pi]);
            i = pi;
            pi = parent(i);
        }
        pop();
        return arr[item];

    }

    void MinHeapify(int i){

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
           MinHeapify(small);
        }


        return;
    }

    void MinHeapify_iter(int i){

        int lc, rc,small;
        // int small = i;


        while(i < size) {
            lc = left_child(i);
            rc = right_child(i);
            small = i;

            if(lc < size && arr[small] > arr[lc]){
             small = lc;
            }
            if(rc < size && arr[small] > arr[rc]){
                small = rc;
             }
             swap(arr[small], arr[i]);
             i++;
        }

        return;
    }
    void print_ele(){
        for (int i=0; i<size;i++){
            cout << arr[i] << "   ";
        }
        cout << endl;
    }
};

int main(){
    MinHeap mh1(10);

    mh1.insert(200);
    mh1.insert(300);
    mh1.insert(80);
    mh1.insert(150);
    mh1.insert(70);
    mh1.insert(40);
    mh1.insert(8);
    mh1.insert(6);
    mh1.insert(5);
    mh1.delete_idx(2);
     mh1.delete_idx(3);
    // cout << mh1.top() << endl;
    // mh1.pop();
    // cout << mh1.top()<< endl;;
    // mh1.pop();

    // cout << mh1.top()<< endl;;
    // mh1.pop();

    // cout << mh1.top()<< endl;;
    // mh1.pop();

    // cout << mh1.top()<< endl;;
    // mh1.pop();

    // cout << mh1.top() << endl;
    mh1.print_ele();

    return 0;
}
