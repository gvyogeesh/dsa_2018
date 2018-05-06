/*
https://leetcode.com/problems/copy-list-with-random-pointer/description/

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <iostream>
#include <map>
using namespace std;

  struct ListNode {
    int val;
    ListNode *next, *random;
    ListNode(int x) : val(x), next(NULL), random(NULL) {}
 };

void print_list(ListNode *head){
    ListNode *cur=head;
    while(cur!=NULL){
        cout << "val: " << cur->val << " ";
        cout << "Rand: " << cur->random->val << " ";
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

ListNode *copyRandomList(ListNode *head) {
    ListNode *cur=head, *cur1=NULL, *head1=NULL;
    map<ListNode *, ListNode *>my_map;
    head1 = new ListNode(head->val);

    my_map[head] = head1;
    // cout << "key" << head << " :val" << head1 << endl;
    cur1 = head1;
    while(cur->next != NULL){
        cur1->next = new ListNode(cur->next->val);
        my_map[cur->next] = cur1->next;
        // cout << "key" << cur->next << " :val" << cur1->next << endl;
        cur = cur->next;
        cur1 = cur1->next;
    }
    cur = head;
    cur1 = head1;
    while(cur != NULL){
        cur1->random = my_map[cur->random];
        cur = cur->next;
        cur1 = cur1->next;
    }

    return head1;
}

ListNode *copyRandomList_v2(ListNode *head) {
    ListNode *cur=head, *cur1=NULL, *head1=NULL, *next=NULL;
    if(head == NULL)
        return NULL;
    while(cur!=NULL){
        next = cur->next;
        cur->next = new ListNode(cur->val);
        cur1 = cur->next;
        cur1->next = next;
        cur = next;
    }
    cur = head;
    head1 = cur1 = head->next;

    while(cur!=NULL){
        cur1->random = cur->random->next;
        cur = cur->next->next;
        if(cur != NULL)
            cur1= cur->next;
    }

    cur = head;
    cur1 = head1;
    while(cur!=NULL){
        cur->next = cur1->next;
        cur = cur->next;
        if(cur!=NULL)
            cur1->next = cur->next;
        cur1 = cur1->next;
    }
    return head1;
}
int main(){
    ListNode *head = NULL, *head1=NULL;
    head = insert_end(head, 10);
    head = insert_end(head, 20);
    head = insert_end(head, 30);
    head = insert_end(head, 40);
    head = insert_end(head, 50);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head->next->next->next;



    print_list(head);
    head1 = copyRandomList(head);
    print_list(head1);

    cout << "Version 2" << endl;
    print_list(head);
    head1 = copyRandomList_v2(head);
    print_list(head1);



    return 0;
}
