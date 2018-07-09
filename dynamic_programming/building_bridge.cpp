/*
Consider a 2-D map with a horizontal river passing through its center. There are n cities on the southern bank with x-coordinates a(1) … a(n) and n cities on the northern bank with x-coordinates b(1) … b(n). You want to connect as many north-south pairs of cities as possible with bridges such that no two bridges cross. When connecting cities, you can only connect city a(i) on the northern bank to city b(i) on the southern bank. Maximum number of bridges that can be built to connect north-south pairs with the aforementioned constraints.

The values in the upper bank can be considered as the northern x-coordinates of the cities and the values in the bottom bank can be considered as the corresponding southern x-coordinates of the cities to which the northern x-coordinate city can be connected.

Input : 6 4 2 1
        2 3 6 5

Output: 2

Input : 8 1 4 3 5 2 6 7
        1 2 3 4 5 6 7 8

Output 5

        1 2 5 4 3
        1 2 5 5 5

Input
        0 1 2 1
        1 3 4 4



*/
#include <iostream>
using namespace std;

int compare(pair<int, int>src, pair<int, int>des){
    // first =>north, second =>south
    if(src.second == des.second)
        return src.first < des.first;
    return src.second < des.second;
}


int main(){
    pair<int, int>arr[] = {make_pair(1, 5), make_pair(2, 4)};
    sort(arr, arr+2, compare);
    for(int i=0;i<2;i++){
        cout << arr[i].second << "  ";
    }
    cout << endl;
}
