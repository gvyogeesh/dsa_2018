#include <iostream>
using namespace std;

int maxsubarray(int arr[], int start, int end){
    int max_val = 0;
    if(start ==  end)
        return arr[start];
    if(start < end){
        int mid = (start + end) / 2;
        int max_left_sum = INT_MIN;
        int sum = 0;

        for(int i=mid;i>=start;i--){
            sum = sum + arr[i];
            if(sum > max_left_sum)
                max_left_sum = sum;
        }
        int max_right_sum = INT_MIN;
        sum=0;
        for(int i=mid+1;i<=end;i++){
            sum = sum + arr[i];
            if(sum > max_right_sum)
                max_right_sum = sum;
        }
        // cout << "Left Max sum " << max_left_sum << endl;
        // cout << "Right Max sum " << max_right_sum << endl;
        //Max ( (Leftmax+ RigtMax ) , Ans(Leftpart), Ans(Rightpart)))
        max_val = max(maxsubarray(arr, start, mid),
                       maxsubarray(arr, mid+1, end));

        return max(max_val, (max_right_sum+max_left_sum));


    }
    return 0;
}

// Kadane's algorithm  to optimize it ot O(N)
int main(){
    int arr[] = {-100, -200, -300, 900, -10,  91};
    // cout << sizeof(arr);
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << maxsubarray(arr, 0, size-1) << endl;;

    return 0;
}
