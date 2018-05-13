
/*
1) Vertical Sum in a given Binary Tree
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

Examples:

      1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7
--------------------------
2)
Vertical width of Binary tree | Set 2
Given a binary tree, find the vertical width of the binary tree. Width of a binary tree is the number of vertical paths.
*/




#include <iostream>
#include <map>
#include <queue>
using namespace std;



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void vertical_sum(TreeNode *root){
    map<int, int>my_map;
    pair<TreeNode*, int> temp;
    queue<pair<TreeNode*, int> >my_que;
    int cur_level;
    TreeNode *cur_node=NULL;
    my_que.push(make_pair(root,0));
    while(my_que.size() > 0){
        temp = my_que.front();
        cur_level = temp.second;
        cur_node = temp.first;
        my_que.pop();
        my_map[cur_level] = my_map[cur_level] + cur_node->val;
        if(cur_node->left != NULL)
            my_que.push(make_pair(cur_node->left, cur_level-1));

        if(cur_node->right != NULL)
            my_que.push(make_pair(cur_node->right, cur_level+1));

    }

    for(map<int, int>::iterator it=my_map.begin(); it!= my_map.end();it++){
        cout << it->first << "  " << it->second << endl;
    }
    return;

}

int main(){
    TreeNode *root=NULL;
    root = new TreeNode(40);

    root->left = new TreeNode(20);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(30);
    root->left->right->left = new TreeNode(5);

    root->right = new TreeNode(60);
    root->right->left = new TreeNode(50);
    root->right->left->right = new TreeNode(55);
    root->right->right = new TreeNode(70);
    vertical_sum(root);


    return 0;
}

