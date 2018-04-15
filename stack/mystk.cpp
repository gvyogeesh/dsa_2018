#include <iostream>
using namespace std;
#define MAX 100


class Stack{
    int stk_ptr;
    int size;
    int arr[MAX];
public:
    Stack(){
        stk_ptr = -1;
    }
    void push(int data);
    int pop();
    bool isempty();
    bool isfull();
    int top();
    int count();
};


void Stack::push(int data){
   // Check whether stack is full or not
     if(isfull()){
      cout << "Stack  is full " << endl;
      return;
     }

    stk_ptr++;
    arr[stk_ptr] = data;
    return;

}
int Stack::pop() {
   // Check whether stakc is empty or not
   if(stk_ptr == -1){
      cout << "Stack is empty..."<< endl;
      return -1;
   }

   int ele = arr[stk_ptr];
   stk_ptr--;
   return ele;

}
int Stack::count(){
   return stk_ptr+1;
}

int Stack::top(){
   return arr[stk_ptr];
}

bool Stack::isempty(){
   if(stk_ptr == -1)
      return true;
    return false;

}

bool Stack::isfull()
{
   if (stk_ptr == MAX)
      return true;
   return false;
}

int main()
{
   Stack mystk;
   mystk.pop();
   if (mystk.isempty() == true) {
      cout << "Stack is empty" << endl;

   }
   mystk.push(100);
   mystk.push(200);
   mystk.push(300);
   mystk.push(400);
   if (mystk.isempty() == true) {
      cout << "Stack is empty" << endl;

   }
   else {
       cout << "Stack is not empty" << endl;
   }
   if (mystk.isfull() == true){
      cout << "Stack is full" << endl;
   }
   else {
      cout << "Stack is not full ,you can insert elements" << endl;
   }
   mystk.push(1000);
   mystk.push(2000);
   cout <<"top element" << mystk.top() << endl;
   mystk.pop();
   cout <<"top element" << mystk.top() << endl;
   mystk.pop();
   cout << "Number of elements in stack are " << mystk.count() <<endl;

    return 0;
}
