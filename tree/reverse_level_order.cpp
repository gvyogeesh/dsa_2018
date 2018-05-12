/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
#include <queue>
#include <stack>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> output;
        vector<int>cur_level;
        TreeNode *cur=root;
        TreeNode *marker = new TreeNode(-1);

        queue<TreeNode *>my_que;
        stack<TreeNode *>my_stk;
        my_que.push(cur);
        my_stk.push(marker);

        int size=0;
        if(root == NULL)
            return output;

        while(my_que.size() > 0){
            size = my_que.size();
            while(size > 0){
                size--;
                cur = my_que.front();
                my_stk.push(cur);
                my_que.pop();

                if(cur->right != NULL)
                    my_que.push(cur->right);
                if(cur->left != NULL)
                    my_que.push(cur->left);

            }
            my_stk.push(marker);

        }
        my_stk.pop();
        while(my_stk.empty() == false){
            cur = my_stk.top();
            while(cur != marker) {
                // cout << cur->val << "  ";
                cur_level.push_back(cur->val);
                my_stk.pop();
                cur = my_stk.top();
            }
            output.push_back(cur_level);
            cur_level.clear();
            my_stk.pop();
        }
        // cout << endl;

       return output;
    }
};
