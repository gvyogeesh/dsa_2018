/* Connect n ropes with minimum cost
There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.

Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.

*/
#include <iostream>
#include <queue>

using namespace std;

int mincost(int arr[], int size){
    int ele1, ele2, sum=0;
    priority_queue<int, vector<int>,greater<int> > min_heap;
    for(int i=0;i<size;i++){
        min_heap.push(arr[i]);
    }
    // cout << min_heap.top() << endl;
    while(min_heap.size() > 1){
        ele1 = min_heap.top();
        min_heap.pop();

        ele2 = min_heap.top();
        min_heap.pop();

        sum = sum + ele1 + ele2;
        // cout << sum << endl;
        min_heap.push(ele1+ele2);

    }
    // cout << "Result is " << sum << endl;
    return sum;


}

/*
log(n),  long(n), O(1)
push(), pop, top , size*/

int main(){
    int arr[] = {100, 50, 30, 20, 200};
    int mcost;
    int size = sizeof(arr)/sizeof(arr[0]);

    mcost = mincost(arr, sizeof(arr)/sizeof(arr[0]));
    cout << "Min Cost to connect ropes are " << mcost << endl;
}
