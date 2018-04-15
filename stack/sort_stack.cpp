#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack<int>s1){
    stack<int>s2;
    int cur;
    while(s1.empty() == false){
        if(s2.empty() == true || s1.top() >= s2.top()){
            s2.push(s1.top());
            s1.pop();
        }
        else{
            cur = s1.top();
            s1.pop();
            while(cur<s2.top()){
                s1.push(s2.top());
                s2.pop();
                if(s2.empty() ==  true)
                    break;
            }
            s2.push(cur);
        }

    }

    cout << "Printing in descending order" << endl;
    while(s2.empty() == false){
        cout << s2.top() << "   ";
        s2.pop();
    }
    cout << endl;
    return;
}
int main(){
    stack<int>s1;
    s1.push(80);
    s1.push(100);
    s1.push(60);
    s1.push(70);
    s1.push(200);
    s1.push(2);
    s1.push(20);
    s1.push(8);
    s1.push(80);
    sort_stack(s1);
    return 0;

}
