/*
https://leetcode.com/problems/binary-tree-pruning/description/
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
#include <map>
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        stack<TreeNode *>my_stk;
        map<TreeNode *, TreeNode *>my_map;
        TreeNode *cur=root, *prev=NULL, *parent=NULL;
        if(root == NULL)
            return NULL;
        while(1){
            while(cur!=NULL){
                my_stk.push(cur);
                prev = cur;
                cur = cur->left;
                if(cur != NULL){
                    my_map[cur]=prev;
                }
            }
            if(my_stk.empty() == true)
                return root;
            cur = my_stk.top();
            if(cur->right == prev || cur->right == NULL){
                prev = cur;
                my_stk.pop();
                parent = my_map[cur];
                if(cur->left == NULL && cur->right == NULL && cur->val == 0){
                    if(cur == parent->left){
                        parent->left = NULL;
                    }
                    else{
                        parent->right = NULL;
                    }
                    delete(cur);
                }
                // if(prev != NULL)
                // cout << prev->val << endl;
                cur = NULL;
            }
            else{
                prev = cur;
                cur = cur->right;
                if(cur!=NULL){
                    my_map[cur]=prev;
                }
            }
        }
       return root;
    }
};
/* Version2 Recursive method */
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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && root->left == NULL && root->right == NULL){
            delete(root);
            return NULL;
        }
        else
            return root;
        
    }
};
