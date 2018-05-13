/*
https://leetcode.com/problems/recover-binary-search-tree/description/

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        
        stack<TreeNode*>my_stk;
        TreeNode *cur=root, *src=NULL, *des=NULL, *prev=NULL;
        if(root == NULL)
            return ;
        while(1){
            while(cur!=NULL){
                my_stk.push(cur);
                cur=cur->left;
            }
            if(my_stk.empty() == true)
                break;
            cur = my_stk.top();
            my_stk.pop();
            //Add the logic here
            if(prev != NULL){
                if(cur->val < prev->val){
                    if(src == NULL){
                        src = prev;
                    }
                    des=cur;
                }
            }
            prev=cur;
            cur=cur->right;
        }
         
        // cout << "Src Value is " << src->val << " Des Value is  "<< des->val << endl;
        int temp = src->val;
        src->val = des->val;
        des->val = temp;
        
    }
        
};
