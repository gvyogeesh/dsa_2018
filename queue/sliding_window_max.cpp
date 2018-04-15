/*
https://leetcode.com/problems/sliding-window-maximum/description/

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].


Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

O(M*N)
O(M)
*/

#include <iostream>
using namespace std;
#include <deque>
//           i
// 5 4  79  7 6 5

// 2
void sliding_window(int arr[], int size, int window){
    deque<int> myque;
    for(int i=0;i<window;i++){
        if(myque.empty() == true || arr[i] < arr[myque.back()]){
            myque.push_back(i);
        }
        else{
            while(arr[i]>=arr[myque.back()]){
                myque.pop_back();
                if(myque.empty() == true)
                    break;
            }
            myque.push_back(i);
        }
    }

    for(int k=window;k<size;k++){
        cout << arr[myque.front()] << " " ;
        if(k-myque.front() == window)
            myque.pop_front();
        if(myque.empty() == true || arr[k] < arr[myque.back()]){
            myque.push_back(k);
        }
        else{
            while(arr[k]>=arr[myque.back()]){
                myque.pop_back();
                if(myque.empty() == true)
                    break;
            }
            myque.push_back(k);
        }

    }
    cout << arr[myque.front()];

    return;
}
int main(){
    int arr[] = {100, 3, -1, 200, 5, 3, 60, 7};

    int window = 3;
    sliding_window(arr, sizeof(arr)/sizeof(arr[0]), window);
    return 0;
}



