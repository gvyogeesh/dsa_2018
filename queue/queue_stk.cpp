#include<iostream>
#include <stack>
using namespace std;

// #define size 10

class Myqueue{
    stack<int>s1;
    stack<int>s2;

public:
    void enqueue(int);
    int dequeue();
    bool isfull();
    bool isempty();
    int peek();
    int count();

};

void Myqueue::enqueue(int item){
    s1.push(item);

}

int Myqueue::dequeue(){
    int item, ele;
    if(s2.empty() == true){
        while(s1.empty() == false){
            ele = s1.top();
            s1.pop();
            s2.push(ele);
        }
    }

    item = s2.top();
    s2.pop();
    return item;

}
int main(){
    Myqueue q;
    // cout << "Dequeue()" << q.dequeue() << endl;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(400);

    cout << "Dequeue() " << q.dequeue() << endl;
    cout << "Dequeue() " << q.dequeue() << endl;
    cout << "Dequeue() " << q.dequeue() << endl;
    cout << "Dequeue() " << q.dequeue() << endl;
    q.enqueue(4000);
    q.enqueue(4890);
    cout << "Dequeue() " << q.dequeue() << endl;
    cout << "Dequeue() " << q.dequeue() << endl;
    cout << "Dequeue() " << q.dequeue() << endl;


    return 0;
}
