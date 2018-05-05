#include <iostream>
using namespace std;

  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


ListNode *insert(ListNode *head, int ele){
    ListNode *tmp=new ListNode(ele);
    tmp->next = head;
    return tmp;

}

ListNode *insert_end(ListNode *head, int ele){
    ListNode *tmp=new ListNode(ele);
    ListNode *cur=head;
    if(head == NULL)
        return tmp;
    while(cur->next !=NULL){
        cur= cur->next;
    }
    cur->next=tmp;

    return head;

}

ListNode *insert_pos(ListNode *head, int ele, int pos){
    ListNode *tmp=new ListNode(ele);
    ListNode *cur=head, *prev=NULL;

    if(head == NULL && pos == 0){
        return tmp;
    }
    if(pos == 0){
        tmp->next = head;
        return tmp;
    }

    while(cur!=NULL && pos > 0){
        pos--;
        prev = cur;
        cur = cur->next;
    }
    cout << pos << endl;
    if(pos>1){
        cout << "Position is much bigger than lenght of the list.";
        return head;
    }
    prev->next = tmp;
    tmp->next = cur;
    return head;
}

ListNode *delete_pos(ListNode *head, int pos){
    ListNode* cur=head, *prev=NULL;
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    if(pos == 0){
        cur = head->next;
        delete(head);
        return cur;
    }
    while(cur!=NULL && pos > 0){
        pos--;
        prev = cur;
        cur = cur->next;
    }
    if(pos>1 || cur== NULL){
        cout << "Position is much bigger than lenght of the list.";
        return head;
    }
    prev->next = cur->next;
    delete(cur);
    cur=NULL;

    return head;
}

ListNode *delete_front(ListNode *head){
    ListNode* cur=head;
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    cur = head->next;
    delete(head);
    head=NULL;

    return cur;
}
void print_list(ListNode *head){
    ListNode *cur=head;
    while(cur!=NULL){
        cout << cur->val << " ";
        cur=cur->next;
    }
    cout << endl;
}



ListNode *delete_end(ListNode *head){
    ListNode* cur=head, *prev=NULL;
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    while(cur->next != NULL){
        prev=cur;
        cur= cur->next;
    }
    prev->next = NULL;
    delete(cur);
    return head;
}

void swap(int &src, int &des){
    int tmp = src;
    src = des;
    des = tmp;
}

ListNode* delete_cur(ListNode *head){
    ListNode* cur=head, *prev=NULL;
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }

    cout << head->val << endl;
    cur = head->next;
    swap(head->val, cur->val);
    head->next = cur->next;
    delete(cur);
    return head;
}


int main(){
    ListNode *head = NULL;
    head = insert_end(head, 10);
    head = insert_end(head, 20);
    head = insert_end(head, 30);
    head = insert_end(head, 40);
    head = insert_end(head, 50);
    head = insert(head, 500);

    head = insert_pos(head, 777, 0);
     // head = insert_pos(head, 76786, 9);

    print_list(head);
    head = delete_front(head);
    print_list(head);
    // print_list(head->next->next);
    // head = delete_end(head);
    // head = delete_end(head);

    // print_list(head);
    // head = delete_pos(head, 2);
    // print_list(head);
    // head = delete_pos(head, 2);
    // print_list(head);
    // head = delete_pos(head, 0);
    // print_list(head);

    head = delete_cur(head->next->next);
    print_list(head);

    return 0;
}
