/*
https://leetcode.com/problems/intersection-of-two-linked-lists/description/
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.
*/


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

// int a;
// int *ap = &a;

ListNode *intersection(ListNode *head1, ListNode *head2){
    ListNode* cur1=head1, *cur2=head2;
    ListNode* last_addr1=NULL, *last_addr2=NULL;
    int len1=0, len2=0, diff=0;

    while(cur1!=NULL){
        len1++;
        if(cur1->next == NULL)
            last_addr1=cur1;

        cur1=cur1->next;

    }

    while(cur2!=NULL){
        len2++;
        if(cur2->next == NULL)
            last_addr2=cur2;

        cur2=cur2->next;
    }

    if(last_addr1 == last_addr2)
    {
        cout << "Both lists are joining at some point" << endl;
        cur1 = head1;
        cur2 = head2;

    // diff = (len1 > len2)?len1-len2:len2-len1
        if(len1 > len2){
            diff = len1 - len2;

            while(diff > 0){
                cur1 = cur1->next;
                diff--;
            }

        }
        else {
            diff = len2 - len1;

            while(diff > 0){
                cur2= cur2->next;
                diff--;
            }

        }
       while (cur1 != NULL){
         if(cur1 == cur2){
            cout << "Joining point is " << cur1->val << "  " << cur2->val << endl;
            return cur1;
          }
          cur1=cur1->next;
          cur2=cur2->next;
       }

    }
    else {
        cout << "There is no intersection point" << endl;
        return NULL;
    }

    return NULL;
}

int main(){
    ListNode *head = NULL, *cur=NULL;;
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

    ListNode *head1= NULL;
    head1 = insert_end(head1, 100);
    head1 = insert_end(head1, 300);

    cur=head1;
    // while(cur->next != NULL){
    //     cur = cur->next;
    // }
    // cur->next = head->next->next->next->next->next;
    print_list(head);
    print_list(head1);
    // head = reverse(head);
    // print_list(head);
    intersection(head, head1);
    return 0;
}
