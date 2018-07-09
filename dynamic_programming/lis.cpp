/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.

Input  : arr[] = {3, 10, 2, 1, 20}
Output : Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input  : arr[] = {3, 2}
Output : Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input : arr[] = {50, 3, 10, 7, 40, 80}
Output : Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}

*/
#include <iostream>
using namespace std;

void lis_util(int arr[], int i, int size, int &result, int &count){
    if(i == size)
        return;
    for(int j = i+1; j<size; j++){
        if(arr[j] > arr[i]){
            count++;
            lis_util(arr, j, size, result, count);
            count--;
        }
    }
    if(count + 1 > result)
        result = count+1;

}
void lis_rec(int arr[], int size){
    if (size == 0)
        return ;

    int result = 1, count = 0;

    for(int i=0; i < size; i++){
        lis_util(arr, i, size, result, count);
    }
    cout << "LIS is "<< result << endl;

}

int lis_dp(int arr[], int size){
    int result[size];
    int path[size];
    int max_val = 1;
    int max_idx = 0;

    if(size == 0)
        return 0;

    for(int i=0;i< size;i++){
        result[i] = 1;
        path[i] = i;
    }

    for(int i=1; i<size;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                if((result[j]+1) > result[i]){
                    result[i] = result[j]+1;
                    path[i] = j;
                    if(result[i] > max_val){
                        max_val = result[i];
                        max_idx = i;
                    }
                }
            }
        }
    }
    int j= max_val;
    while(j > 0){
        cout << arr[max_idx] << "  " ;
        max_idx = path[max_idx];
        j--;
    }
    cout << endl;
    return max_val;


}

int main(){
    int arr[] = {1, 2, 30,1, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    lis_rec(arr, size);
    cout << "LIS  " << lis_dp(arr, size)<< endl;
    return 0;


}
