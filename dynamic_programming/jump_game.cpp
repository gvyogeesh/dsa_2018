/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [{2,3,1,1,4}]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.

https://leetcode.com/problems/jump-game-ii/description/
https://leetcode.com/problems/jump-game/description/
*/
#include <iostream>
using namespace std;
int min_val = INT_MAX;

int minjump(int arr[], int i, int size, int &count){
    int result;
    if(i == size-1){
        // cout << "count is " << count << endl;
        return count;
    }
    for(int j=i+1; j<size;j++){
        if(arr[i] + i >= j){
            count++;
            result = minjump(arr, j, size, count);
            if(result < min_val)
                min_val = result;
            count--;
        }
       }
     return min_val;

}

int min_jump_dp(int arr[], int size){
    int T[size] ;
    for(int i=0; i<size;i++){
        T[i] = INT_MAX;
    }
    T[0] = 0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(i+arr[i] >= j){
                if(T[j] > T[i]+1)
                    T[j] = T[i] + 1;
            }
        }
    }
    return T[size-1];
}
int main()
{
    int arr[] = {3,2,0,1,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    cout << "MIn jumps are "<< minjump(arr, 0, size, count ) << endl;
    cout << "MIn jumps using DP "<< min_jump_dp(arr, size) << endl;
}
