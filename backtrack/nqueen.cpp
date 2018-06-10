/*
1) https://leetcode.com/problems/n-queens/description/
2) https://leetcode.com/problems/n-queens-ii/description/

The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. For example, following is a solution for 4 Queen problem.

*/
#include <iostream>
using namespace std;

#define N 5

void print_sol(int sol[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << sol[i][j] << "  " ;
        }
        cout << endl;
    }
    return;
}

bool issafe(int sol[N][N], int row, int col){
    for(int i=0; i< N;i++){
        for(int j=0; j<N;j++){
            if(sol[i][j] == 1) {
                //Same column
                if(col == j)
                    return false;
                //Same row
                if(row == i)
                    return false;
                //Diagonal
                if( (row - col) == (i - j) )
                    return false;
                if((row + col) == (i + j))
                    return false;
            }
        }
    }

    return true;
}
void nqueen(int sol[N][N], int row, int &count){
    if(row == N){
        print_sol(sol);
        count++;
        cout << endl;
        return;
    }
    for(int c=0;c<N;c++){
        if (issafe(sol, row, c) == true){
            sol[row][c] = 1;
            nqueen(sol, row+1, count);
            sol[row][c] = 0;
        }
    }

}
int main(){

    int sol[N][N] = { {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
                        };
    int count = 0;
    nqueen(sol,0, count);
    cout << "Count is " << count << endl;

    return 0;

}
