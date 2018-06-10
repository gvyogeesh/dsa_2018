/*
Find the number of islands
Given a boolean 2D matrix, find the number of islands. A group of connected 1s forms an island. For example, the below matrix contains 5 islands

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}
Output : 5
*/

#include <iostream>
using namespace std;
#define N 4

bool issafe(int inp[N][N], int row, int col, int visited[N][N]){
    if(row >= N || row < 0) //Boundary condition for row
        return false;

     if(col >= N || col < 0) //Boundary condition for col
        return false;

     if(inp[row][col] == 0)
        return false;

     if(visited[row][col] == 1)
        return false;

    return true;
}

void dfs(int inp[N][N], int row, int col, int visited[N][N]){
    visited[row][col] = 1;
    int rd[] = {-1, -1, -1,  0, 1, 1, 1, 0};
    int cd[] = {-1, 0,   1, -1, -1, 0, 1, 1};
    for(int i=0; i<8;i++){
        if(issafe(inp, row+rd[i], col+cd[i],visited) ==  true){
            dfs(inp, row+rd[i], col+cd[i], visited);
        }
    }



    return;

}

int main(){
     int inp[N][N] = { {0, 1, 0, 0},
                       {1, 0, 1, 0},
                       {1, 0, 1, 1},
                       {1, 0, 0, 0}
                    };

    int visited[N][N] = { {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0}
                    };
    int count =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j] == 0 && inp[i][j] == 1){
                dfs(inp,i, j,visited);
                count++;
            }
        }
    }
    cout << "Number of islands are " << count << endl;
    return 0;
}
