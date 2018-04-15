#include<iostream>
#include<stack>
using namespace std;

void next_greator(int arr[], int size){
    int i=1;
    int cur, top_ele;
    stack<int>mystk;
    mystk.push(arr[0]);
    while(i<size){
        top_ele = mystk.top();

        cur = arr[i];
        while(cur > top_ele){
            cout << top_ele << "-->" << arr[i] << endl;
            mystk.pop();
            if(mystk.empty() == true)
                break;
            top_ele = mystk.top();
        }

        mystk.push(cur);
        i++;

    }
    while(mystk.empty() == false){
        cur = mystk.top();
        cout << cur << "-->" << -1 <<endl;
        mystk.pop();
    }

    return;
}

int main()
{
    int arr[] = {8,1};
    next_greator(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
