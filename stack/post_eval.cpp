#include <iostream>
#include<string.h>
#include <stack>
#include <math.h>
using namespace std;

int eval(char oper, int op1, int op2){
    switch(oper){
        case '*':
                return op1 * op2;
        case '/':
            return op1 / op2;
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '^':
            return pow(op1, op2);

    }
    return 0;
}
int post_eval(char arr[]){
    stack<int>mystk;
    int size = strlen(arr);
    int i =0, result;
    int op1, op2;
    while(i<size){
        if(isdigit(arr[i])){
            mystk.push(arr[i]-'0');
        }
        // "63*2+";
        else {
            op2 = mystk.top();
            mystk.pop();
            op1 = mystk.top();
            mystk.pop();
            result = eval(arr[i],op1, op2);
            mystk.push(result);
        }
      i++;
    }
    result = mystk.top();

    return result;
}
int main(){
    char arr[] = "632*+";

    char multi_arr = "600 3 200 * +"
    int out;
    out = post_eval(arr);
    cout <<"Output is " << out << endl;
    return 0;
}

