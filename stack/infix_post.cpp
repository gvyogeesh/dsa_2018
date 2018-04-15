#include <iostream>
#include <stack>
using namespace std;

int prec(char inp){
    if (inp == '^')
        return 3;
    if(inp == '*' || inp == '/')
        return 2;
    if(inp == '+' || inp == '-')
        return 1;

    else
        return 0;
}
void convert_infix_to_postfix(char arr[]){
    stack<char>mystk;
    char output[100];
    char ele;
    char tmp;
    int size = strlen(arr);
    int j=0;
    for(int i=0; i< size; i++){
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            output[j] = arr[i];
            j++;

        }
        else if( arr[i] == '('){
            mystk.push(arr[i]);
        }
        else{
            // *, /, +, -, ^, )
            if(arr[i] == ')'){

                tmp = mystk.top();
                while(tmp != '('){
                    output[j] = tmp;
                    j++;
                    mystk.pop();
                    tmp = mystk.top();
                }
                if(tmp == '(')
                    mystk.pop();
            }
            else if(mystk.empty() == true ){
                mystk.push(arr[i]);
            }
            else{
                while(prec(arr[i]) <= prec((mystk.top()))) {
                    if(mystk.empty() == false){
                        ele = mystk.top();
                        output[j] = ele;
                        j++;
                        mystk.pop();
                    }
                    break;
                }
                mystk.push(arr[i]);
            }
        }

    }
    while(mystk.empty() == false){
        tmp = mystk.top();
        output[j] = tmp;
        j++;
        mystk.pop();
    }
    output[j]='\0';
    cout << output << endl;
}
int main(){
    char arr[] = "a*(b+d)";
    convert_infix_to_postfix(arr);
    return 0;
}


// Assignment:
// Convert infix to convert_infix to prefix
// Evaluate postfix expression

