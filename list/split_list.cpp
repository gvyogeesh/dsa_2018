/*
https://leetcode.com/problems/split-linked-list-in-parts/description/

Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*>result(k, NULL);
        // for (int i=0;i<result.size();i++){
        //     cout<< result[i]<< endl;
        // }
        ListNode*cur=root,*t1=NULL, *prev=NULL;
        int len=0, size=0,  rem=0,  i=0;
        while(cur!=NULL){
            len++;
            cur=cur->next;
        }
        cout << "lenght is " << len << endl;
        size = len / k ;
        if(size == 0)
            size = 1;
        else
            rem = len % k;

        cout << "lenght is " << len << " Rem is " << rem << "Size" << size << endl;
        cur = root;
        int temp;
        while(cur!=NULL){
            result[i] = cur;
            prev=cur;
            temp=0;
            while(temp<size-1 && cur!=NULL){
                temp++;
                cur= cur->next;
                prev = cur;
            }
            if(rem > 0){
                rem--;
                cur = cur->next;
                prev = cur;
                cur = cur->next;
                prev->next = NULL;
            }
            else{
                cur = cur->next;
                if(prev)
                 prev->next = NULL;

            }
            // t1=result[i];;
            // while(t1!=NULL){
            //     cout << t1->val << " ";
            //     t1= t1->next;
            // }
            // cout << endl;
          i++;
        }
        return result;
    }
};
