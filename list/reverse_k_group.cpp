#include <iostream>
using namespace std;

  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

void print_list(ListNode *head){
    ListNode *cur=head;
    while(cur!=NULL){
        cout << cur->val << " ";
        cur=cur->next;
    }
    cout << endl;
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

ListNode *reverse(ListNode *head){
    ListNode *cur=head, *prev=NULL, *next=NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

ListNode *reverse_kgroups(ListNode *head, int k){
    ListNode *cur=NULL, *prev=NULL, *knext=NULL, *khead=NULL;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    cur=prev=dummy;
    int i=0;
    while(cur->next!=NULL ){
        i++;
        cur=cur->next;
        if(i == k){
            // if(cur == NULL)
                // return dummy->next;
            knext = cur->next;
            khead = prev->next;
            cur->next = NULL;
            prev->next = reverse(khead);
            // print_list(prev->next);

            // cout << "khead " << khead->val << endl;
            // cout << "knext " << knext->val << endl;
            // cout << "cur " << cur->val << endl;
            // cout << "prev " << prev->val << endl;

            khead->next = knext;
            //Reset cur, prev,
            cur = prev = khead;
            i=0;

        }
        // cout << "Dummy print" << endl;

    }
    return dummy->next;

}





int main(){
    ListNode *head = NULL;
    head = insert_end(head, 10);
    head = insert_end(head, 20);
    head = insert_end(head, 30);
    head = insert_end(head, 40);
    head = insert_end(head, 50);
    head = insert_end(head, 500);
    head = insert_end(head, 67);
    head = insert_end(head, 88);
    head = insert_end(head, 345);
    head = insert_end(head, 800);
    head = insert_end(head, 900);

    print_list(head);
    // head = reverse(head);
    // print_list(head);

    head = reverse_kgroups(head, 3);
    print_list(head);
    return 0;
}
