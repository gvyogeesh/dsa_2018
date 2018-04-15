/*
Minimum time required to rot all oranges
Given a matrix of dimension m*n where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:

0: Empty cell

1: Cells have fresh oranges

2: Cells have rotten oranges

 So we have to determine what is the minimum time required so that all the oranges become rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes up, down, left and right. If it is impossible to rot every orange then simply return -1.

Examples:

Input:  arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
Output:
All oranges can become rotten in 2 time frames.

*/
#include <iostream>
#include <queue>
using namespace std;
#define ROW 3
#define COL 5

struct cell{
    int row;
    int col;
};
bool isvalid(int row, int col){
    if(row < 0 || row >=ROW)
        return false;
    if(col < 0 || col>=COL)
        return false;
    return true;

}
int find_num_days(int arr[][5], int r, int c){
    queue<cell>q1;
    bool incr_count = false;
    int days = 0;
    cell c1;
    cell tmp;
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j] == 2){
                c1.row = i;
                c1.col = j;
                q1.push(c1);
            }
        }
    }
    cout << "Size of queue is " << q1.size() << endl;

    while(q1.empty() == false) {
    int q_size =q1.size();

    while(q_size > 0){
        c1 = q1.front();
        q1.pop();
        q_size--;

        //Traverse up
        if(isvalid(c1.row-1, c1.col)){
            if(arr[c1.row-1][c1.col] == 1){
                if(incr_count == false){
                    days++;
                    incr_count = true;
                }
                tmp.row = c1.row-1;
                tmp.col = c1.col;
                q1.push(tmp);
                arr[c1.row-1][c1.col] = 2;

            }
        }
        //Traverse down
        if(isvalid(c1.row+1, c1.col)){
            if(arr[c1.row+1][c1.col] == 1){
                if(incr_count == false){
                    days++;
                    incr_count = true;
                }
                tmp.row = c1.row+1;
                tmp.col = c1.col;
                q1.push(tmp);

                arr[c1.row+1][c1.col] = 2;
            }
        }
        //Traverse right
        if(isvalid(c1.row, c1.col+1)){
            if(arr[c1.row][c1.col+1] == 1){
                if(incr_count == false){
                    days++;
                    incr_count = true;
                }
                tmp.row = c1.row;
                tmp.col = c1.col+1;
                q1.push(tmp);

                arr[c1.row][c1.col+1] = 2;
            }
        }
        //Traverse left
        if(isvalid(c1.row, c1.col-1)){
            if(arr[c1.row][c1.col-1] == 1){
                if(incr_count == false){
                    days++;
                    incr_count = true;
                }
                tmp.row = c1.row;
                tmp.col = c1.col-1;
                q1.push(tmp);
                arr[c1.row][c1.col-1] = 2;
            }
        }
    }
    incr_count = false;
   }
    /* Dummy code to print matrix */
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j] == 1)
                return -1;
            }
            // cout << endl;
        }
    cout << "Number of days are " << days << endl;



    return days;

}



int main(){

    int arr[3][5] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 1, 1},
                     {1, 0, 0, 1, 1}};
int result = 0;
result = find_num_days(arr,3, 5);
cout << "Days = " << result << endl;
return 0;
}

