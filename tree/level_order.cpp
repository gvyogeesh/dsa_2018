/*
https://leetcode.com/problems/binary-tree-level-order-traversal/description/
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
queue<TreeNode*> my_que;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int>cur_level_result;
        int size=0;
        TreeNode* cur = root;
        if(root == NULL)
            return result;
        my_que.push(cur);
        while(my_que.size() > 0) {
            size = my_que.size();
            while(size > 0){
                cur = my_que.front();
                cout << cur->val << endl;
                cur_level_result.push_back(cur->val);
                my_que.pop();
                if(cur->left != NULL)
                    my_que.push(cur->left);
                if(cur->right != NULL)
                    my_que.push(cur->right);
                size--;

            }
            result.push_back(cur_level_result);
            cur_level_result.clear();

        }
        return result;

    }
};
