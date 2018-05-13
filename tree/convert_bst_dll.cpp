#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * convert_bst_dll(TreeNode *root){
    TreeNode *head=NULL, *cur=root, *prev=NULL;
    stack<TreeNode *>my_stk;
    if(root == NULL)
        return NULL;

    while(1){
        while(cur!=NULL){
            my_stk.push(cur);
            cur= cur->left;
        }
        if(my_stk.empty() == true)
            return head;
        cur = my_stk.top();
        my_stk.pop();
        if(prev == NULL){
            head = prev= cur;
        }
        else{
            prev->right = cur;
            cur->left = prev;
            prev = cur;
        }

        cur = cur->right;
    }

    return head;

}
int main(){
    TreeNode *root=NULL, *head=NULL;
    root = new TreeNode(100);

    root->left = new TreeNode(50);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(55);
    root->left->right->left = new TreeNode(52);

    root->right = new TreeNode(120);
    root->right->left = new TreeNode(110);
    root->right->left->right = new TreeNode(115);
    root->right->right = new TreeNode(130);
    head = convert_bst_dll(root);
    root =head;
     cout << "Print left  to right " << endl;
    while(root != NULL){
        cout << root->val << "  ";
        if(root->right == NULL)
            head = root;
        root = root->right;
    }
    cout << "Print right to left " << endl;
    root = head;
    while(root != NULL){
        cout << root->val << "  ";
        if(root->left == NULL)
            head = root;
        root = root->left;
    }



    return 0;
}
