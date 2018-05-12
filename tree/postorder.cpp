/*
Given a binary tree, return the postorder traversal of its nodes' values.
https://leetcode.com/problems/binary-tree-postorder-traversal/description/
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *>my_stk;
        vector<int>result;
        TreeNode *cur=root, *prev=NULL;
        while(1){
            while(cur!=NULL){
                my_stk.push(cur);
                cur = cur->left;
            }
            if(my_stk.empty() == true)
                return result;
            cur = my_stk.top();
            if(cur->right == prev || cur->right == NULL){
                prev = cur;
                my_stk.pop();
                result.push_back(prev->val);
                // cout << prev->val << endl;
                cur = NULL;
            }
            else
                cur = cur->right;
        }


    }
};

/* Version2 Recursive */
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
void postorderTraversal_util(TreeNode *root){
    if(root == NULL)
        return ;
    // cout << root->val << endl;

    postorderTraversal_util(root->left);
    postorderTraversal_util(root->right);
    output.push_back(root->val);
}
class Solution {
public:
    vector<int> postorderTraversal_recur(TreeNode* root) {
        output.clear();
        if(root == NULL)
            return output;
        postorderTraversal_util(root);
        return output;
        
    }
};
