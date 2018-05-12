/*
Given a binary tree, return the inorder traversal of its nodes' values.
https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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
#include <stack>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        stack<TreeNode*>my_stk;
        TreeNode *cur=root;
        if(root == NULL)
            return result;
        while(1){
            while(cur!=NULL){
                my_stk.push(cur);
                cur=cur->left;
            }
            if(my_stk.empty() == true)
                return result;
            cur = my_stk.top();
            my_stk.pop();
            result.push_back(cur->val);
            cur=cur->right;
        }


    }
};

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
void inorderTraversal_util(TreeNode *root){
    if(root == NULL)
        return ;
    // cout << root->val << endl;

    inorderTraversal_util(root->left);
    output.push_back(root->val);
    inorderTraversal_util(root->right);
}
class Solution {
public:
    vector<int> inorderTraversal_recursive(TreeNode* root) {
        output.clear();
        if(root == NULL)
            return output;
        inorderTraversal_util(root);
        return output;

    }
};
