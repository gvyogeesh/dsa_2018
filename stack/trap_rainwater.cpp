/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include <iostream>
#include <stack>
using namespace std;

int rainwater_harvest(int arr[], int size){
    int max_unit = 0;
    for (int i=0; i<size;i++){
        int left_big = 0, right_big = 0;
        for(int left = i; left>=0;left--){
            if(arr[left] >= left_big)
                left_big = arr[left];
        }
        for(int right = i; right<size;right++){
            if(arr[right] >= right_big){
                // cout << "rb" << right_big << endl;
                right_big = arr[right];
            }
        }
        // cout << " left big  " << left_big << "   right_big  "  << right_big << endl;
        max_unit += min(left_big, right_big) - arr[i];
    }

    return max_unit;
}

int rainwater_2(int arr[], int size){
    stack<int>mystk;
    int i=0;
    int height, distance, max_unit=0,cur;
    while(i<size ){
        if(mystk.empty() || (arr[mystk.top()] >= arr[i])){
            cout << "Push" << "idx  " << i << "  Val " << arr[i] << endl;
            mystk.push(i);
            i++;
        }
        else {
            while(mystk.empty() == false && arr[i] > arr[mystk.top()]){
                cur = mystk.top();
                cout <<"Popping idx is " << cur << endl;
                mystk.pop();
                if(mystk.empty() == true)
                    break;
                height = min(arr[mystk.top()], arr[i]) - arr[cur];
                distance = (i-1)-mystk.top();
                max_unit += height * distance;
                cout << "height " << height << "Distance"<< distance << endl;
            }

        }

    }
    cout << max_unit << endl;
    return max_unit;
}
int main(){
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    // int arr[] = {0,1,0,2,1,0,1,0,1,3};
    int result;
    // int arr[] = {16, 5, 4, 2, 150};
    // cout << "Version 1" << endl;
    result = rainwater_harvest(arr, sizeof(arr)/sizeof(arr[0]));
    cout << result << " units of water can be stored!!!"<< endl;

    cout << "Version 2" << endl;
    result = rainwater_2(arr, sizeof(arr)/sizeof(arr[0]));
    cout << "O(N): " << result << "  units of water can be stored!!!"<< endl;
    return 0;

}
