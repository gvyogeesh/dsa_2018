/*
https://leetcode.com/problems/merge-k-sorted-lists/description/
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <queue>
struct compare{
  bool operator() (ListNode *x, ListNode* y){
      return x->val > y->val;

  }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode *>, compare> min_heap;
        if (lists.size() == 0)
            return NULL;
        for(int i=0;i<lists.size();i++){

            // cout << lists[i]->val << endl;
            if(lists[i] != NULL)
             min_heap.push(lists[i]);
        }
        ListNode *cur=NULL, *prev=NULL, *head=NULL, *temp=NULL;
        if(min_heap.size() > 0){
            prev= head = min_heap.top();
            min_heap.pop();
            if(head->next != NULL)
                min_heap.push(head->next);
        }
        while(min_heap.size() > 0){
            cur = min_heap.top();
            // cout << cur->val << endl;
            min_heap.pop();
            prev->next = cur;
            prev = cur;
            if(prev->next != NULL)
                min_heap.push(prev->next);
        }

        return head;
    }
};
