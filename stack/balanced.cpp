#include <iostream>
#include <stack>
/* push, pop, top, isempty */
using namespace std;

bool isbalanced(char arr[]){
    stack<char> mystk;
    char ele;
    int size = strlen(arr);
    for(int i=0; i<size; i++){
        if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{'){
            mystk.push(arr[i]);
        }

        if(arr[i] == ')'){
            if(mystk.empty() == false) {
                ele = mystk.top();
                if(ele != '(')
                    return false;
                mystk.pop();
            }
            else
                return false;
        }

        else if(arr[i] == ']'){
            if (mystk.empty() == false){
                ele = mystk.top();
                mystk.pop();
                if(ele != '[')
                    return false;
            }
            else
                return false;


        }

        else if(arr[i] == '}'){
            if (mystk.empty() == false){
                ele = mystk.top();
                if(ele != '{')
                    return false;
                mystk.pop();
            }
            else
                return false;
        }



    }
    if(mystk.empty() == true)
        return true;
    else
        return false;

}
int main(){
    char arr[] = "{[]}";
    bool output;
    output = isbalanced(arr);
    if(output){
        cout <<"Balanced" << endl;
    }
    else
        cout << "Its not balanced";

    return 0;
}
