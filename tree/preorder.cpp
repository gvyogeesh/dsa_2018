/*
Given a binary tree, return the preorder traversal of its nodes' values.
https://leetcode.com/problems/binary-tree-preorder-traversal/description/
*/


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *>my_stk;
        vector<int> result;
        TreeNode* cur=root;
        if(cur == NULL)
            return result;

        while(1){
            while(cur != NULL){
                my_stk.push(cur);
                cout << cur->val << endl;
                result.push_back(cur->val);
                cur = cur->left;
            }
            if(my_stk.empty() == true)
                return result;

            cur = my_stk.top();
            cur = cur->right;
            my_stk.pop();
        }

        return result;
    }
};

/* Version 2 Recursion */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int>output;
void preorderTraversal_util(TreeNode *root){
    if(root == NULL)
        return ;
    // cout << root->val << endl;
    output.push_back(root->val);
    preorderTraversal_util(root->left);
     preorderTraversal_util(root->right);
}

class Solution {
public:
    vector<int> preorderTraversal_recur(TreeNode* root) {
        output.clear();
        if(root == NULL)
            return output;

        preorderTraversal_util(root);
        return output;

    }
};
