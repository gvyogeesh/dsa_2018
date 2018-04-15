#include<iostream>
using namespace std;

// #define size 10

class Myqueue{
    int front, rear, cnt, capacity;
    vector<int>arr;
public:
    Myqueue(int size){
        arr = new int[size];
        cnt = 0;
        capacity = size;
        front = 0;
        rear = -1;
    }
    void enqueue(int);
    int dequeue();
    bool isfull();
    bool isempty();
    int peek();
    int count();

};

void Myqueue::enqueue(int item){
    // If queue is full throw an error
    if (isfull()){
        cout <<"Queue is full!!!";
        exit(0);
    }
    rear = (rear+1) % capacity;
    arr[rear] =  item;
    cnt++;
    return;
}

int Myqueue::dequeue(){
    // Handle empty queue scenrio
    if (isempty()){
        cout <<"Queue is empty!!!";
        exit(0);
    }
    int ele = arr[front];
    front = (front+1) % capacity;
    cnt--;
    return ele;

}

int Myqueue::peek(){
    // Handle empty queue scenrio
    if (isempty()){
        cout <<"Queue is empty!!!";
        exit(0);
    }
    return arr[front];
}

bool Myqueue::isfull(){
    if (cnt == capacity)
        return true;
    return false;
}

bool Myqueue::isempty(){
    if (cnt == 0)
        return true;
    return false;
}

int Myqueue::count(){
    return cnt;
}

int main(){
    Myqueue q;
    // cout << "Dequeue()" << q.dequeue() << endl;
    q.enqueue(100);
    q.enqueue(200);
    cout << "Peek()" << q.peek() << endl;
    q.enqueue(300);
    q.enqueue(400);

    cout << "Dequeue()" << q.dequeue() << endl;
    cout << "Dequeue()" << q.dequeue() << endl;
    cout << "Peek()" << q.peek() << endl;
    q.enqueue(3000);

    cout << "Dequeue()" << q.dequeue() << endl;

    cout << "Dequeue()" << q.dequeue() << endl;
    cout << "Dequeue()" << q.dequeue() << endl;
    cout << "Dequeue()" << q.dequeue() << endl;




    return 0;
}
