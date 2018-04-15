#include <queue>
#include <iostream>
using namespace std;

class Stack{
    queue<int>q1;
    queue<int>q2;
    int counter;

public:
    void push(int item){
         q1.push(item);
         counter++;
    }
    int pop(){
        int ele;
        if(q1.empty() == true)
            return -1;

        while(q1.size() >1){
            q2.push(q1.front());
            q1.pop();
        }
        ele = q1.front();
        cout <<"Element to be popped is "<< ele << endl;
        counter--;
        q1.pop();

        queue<int>tmp;
        tmp = q1;
        q1 = q2;
        q2 = tmp;

        return ele;

    }
    int top();
    bool isempty();
    // bool isfull();

};

int main(){
    Stack s1;
    s1.push(100);
    s1.push(200);
    s1.push(300);
    s1.push(2000);
    s1.push(400);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    s1.push(999);
    cout << s1.pop() << endl;


    return 0;
}
