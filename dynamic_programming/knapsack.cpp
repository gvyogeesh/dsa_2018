/*
0-1 Knapsack Problem:
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

    val = {6, 8, 18};
    wt = {1, 2, 3};
    W = 5;

    output: 26

    val = {60, 100, 120};
    wt = {10, 20, 30};
    int  W = 50;
    output: 220

    val = {1, 4, 5, 7};
    wt = {1, 3, 4, 5};
    int  W = 7;
    output: 9
*/
#include <iostream>
using namespace std;

int knapsack(int capacity, int val[], int wt[], int size){
    if(capacity == 0 || size-1 < 0)
        return 0;
    if(wt[size-1] > capacity)
        return knapsack(capacity, val, wt, size-1);
        //Max(Include current, Exclude current)
    return max((val[size-1] + knapsack(capacity - wt[size-1], val, wt, size-1)),(knapsack(capacity, val, wt, size-1)));
}
int knapsack_dp(int capacity, int val[], int wt[], int size){
    int T[size+1][capacity+1];
    for(int i=0;i<size+1;i++){
        for(int j=0;j<capacity+1;j++){
            if(i == 0  || j == 0){
                T[i][j] = 0;
            }
            else {
                if(wt[i-1] > j){
                    T[i][j] = T[i-1][j];
                }
                else {
                                            /*[Remaining coins][Remaining capacity] */
                    T[i][j] = max((val[i-1]+T[i-1][j-wt[i-1]]), T[i-1][j]);
                }
            }
        }
    }
    return T[size][capacity];
}
int main(){
   int  val[] = {1, 4, 5, 7};
   int  wt[] = {10, 20, 30, 50};
   int W = 100;
   cout << "Recursive Solution " <<knapsack(W, val, wt, sizeof(val)/sizeof(val[0])) << endl;
   cout << "DP Solution " <<knapsack_dp(W, val, wt, sizeof(val)/sizeof(val[0])) << endl;

}
