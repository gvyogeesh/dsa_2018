/*
https://leetcode.com/problems/largest-rectangle-in-histogram/description/

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

For example,
                  i
Given heights = [2,1,5,6,2,3],
return 10.
*/
#include<iostream>
#include<stack>
using namespace std;
    // i     j      i
// {0,2, 2, 5, 6, 1,1,0};
int largest_area(int arr[], int size){

    int right, left;
    int max_area=0, cur_area;
    for (int i=0; i<size;i++){
        right=0;
        left=0;

        for (int j=i+1;j<size;j++){
            if(arr[j]>=arr[i])
                right++;
            else
                break;

        }
        for (int k=i-1;k>=0;k--){
            if(arr[k]>=arr[i]){
                left++;
            }
            else
                break;

        }
        cur_area = arr[i]  * (left + right + 1);
        if(max_area < cur_area)
            max_area = cur_area;
        // cout << "Current area is " << cur_area << endl;
    }
    return max_area;

}
int largest_stk_area(int arr[], int size) {
    int i =0;
    int curr, cur_area, max_area=0;
    stack<int>mystk;
    while(i<size){
        if(mystk.empty() == true || arr[i] >=arr[mystk.top()]){
            mystk.push(i);
            i++;
        }
        else{
            curr = mystk.top();
            mystk.pop();
            if(mystk.empty() == false){
                cur_area = arr[curr] * (i-1-mystk.top());
            }
            else{
                cur_area = arr[curr] * i;
            }
            cout << "Current area is " << cur_area << endl;
            if(max_area < cur_area){
                max_area = cur_area;
            }
        }
    }
    while(mystk.empty() == false){
        curr = mystk.top();
        mystk.pop();
        if(mystk.empty() == false){
            cur_area = arr[curr] * (i-1-mystk.top());
        }
        else{
            cur_area = arr[curr] * i;
        }
        if(max_area < cur_area){
                max_area = cur_area;
            }
        cout << "Current area is " << cur_area << endl;

    }
    return max_area;
}

int main(){
    int arr[] = {10, 10, 10, 10, 10,10};
    // 0(N2 solution)
    // int max_area = largest_area(arr, sizeof(arr)/sizeof(arr[0]));
    // cout << "Largest area in histogram is " << max_area << endl;

    int max_area_1 = largest_stk_area(arr, sizeof(arr)/sizeof(arr[0]));
    cout << "Largest area in histogram using stack is " << max_area_1 << endl;
    return 0;
}
