#include <queue>
#include <iostream>
using namespace std;

class Stack{
    queue<int>q1;

public:
    void push(int item){
         q1.push(item);
    }
    int pop(){
        int ele;
        int size;
        if(q1.empty() == true)
            return -1;

        size = q1.size();
        while(size >1){
            ele = q1.front();
            q1.pop();
            q1.push(ele);
            size--;
        }
        ele = q1.front();
        // cout <<"element to be deleted is " << q1.front() << endl;
        q1.pop();


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

    s1.push(23);
    s1.push(87);
    cout << s1.pop()<<endl;


    return 0;
}
