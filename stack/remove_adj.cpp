#include <iostream>
using namespace std;

void remove_adj_dup(char arr[]){
    int i=0;
    int stk_ptr = -1;
    int size = strlen(arr);
    while(i < size){
        if(stk_ptr == -1 || arr[stk_ptr] != arr[i]){
            stk_ptr++;
            arr[stk_ptr] = arr[i];
            i++;
        }
        while(arr[i] == arr[stk_ptr]){
            i++;
            if (stk_ptr >= 0)
                stk_ptr--;

        }

    }
    arr[stk_ptr+1] = '\0';
    cout << stk_ptr << endl;
    cout << arr << endl;
    return ;
}

int main(){
    char a[] ="careebc" ; // carbc
    remove_adj_dup(a);
    // cout << a << endl;
    return 0;
}
