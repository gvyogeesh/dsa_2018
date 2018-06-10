/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination. The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination.
*/

#include <iostream>
using namespace std;
#define N 4

bool issafe(int inp[N][N], int row, int col){
    if(row >= N ) //Boundary condition for row
        return false;

     if(col >= N ) //Boundary condition for col
        return false;

     if(inp[row][col] == 0)
        return false;

    return true;
}

bool find_path(int inp[N][N], int row, int col, int sol[N][N]){

    // if(row == N-1 && col == N-1)
    //     return true;
    if(issafe(inp, row, col) == true){
        sol[row][col] = 1;
        if(row == N-1 && col == N-1)
            return true;
        //Explore right part
        if(find_path(inp, row, col+1, sol) == true)
            return true;

         //Explore down side
        if(find_path(inp, row+1, col, sol) == true)
            return true;

        sol[row][col] = 0;

    }
    return false;
}

void print_sol(int sol[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << sol[i][j] << "  " ;
        }
        cout << endl;
    }
    return;
}

int main(){
    int inp[N][N] = { {1, 1, 1, 1},
                      {0, 0, 1, 0},
                      {0, 0, 1, 1},
                      {0, 0, 1, 1}
                    };

    int sol[N][N] = { {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0}
                    };
    if(find_path(inp,0,0,sol) == true){

        cout << "Solution exists!!!" << endl;
        print_sol(sol);
    }
    else
        cout << "solutio does not exists!!" << endl;

    return 0;

}


