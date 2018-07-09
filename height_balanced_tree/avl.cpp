/*AVL Tree */
#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    int height;
};

node *newnode(int item){
    node *cur = new node;
    cur->data = item;
    cur->left = NULL;
    cur->right = NULL;
    cur->height = 1;

    return cur;
}

int get_height(node *root){
    if(root == NULL)
        return 0;
    return root->height;
}

node *leftrotate(node *root){
    cout << "Left rotation" << endl;
    node *nr =  root->right;
    root->right = nr->left;
    nr->left = root;

    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    nr->height = max(get_height(nr->left), get_height(nr->right)) + 1;

    return nr;
}

node *rightrotate(node *root){
    cout << "Right rotaion" << endl;
    node *nr =  root->left;
    root->left = nr->right;
    nr->right = root;

    //Adjust height for old and new root;
    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    nr->height = max(get_height(nr->left), get_height(nr->right)) + 1;

    return nr;
}


int getbalance(node *root){
    if(root == NULL)
        return 0;

    return (get_height(root->left) - get_height(root->right));
}

void preorder(node *root){
    if(root == NULL)
        return ;
    cout << root->data << "  ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root == NULL)
        return ;
    inorder(root->left);
    cout << root->data << "  ";
    inorder(root->right);
}

node* get_min_node(node *root){
    node *cur = root;
    if(cur == NULL)
        return NULL;
    while(cur->left != NULL){
        cur = cur->left;
    }
    return cur;
}

node *insert(node *root, int item){
    int bal_factor = 0;
    if(root == NULL){
        return newnode(item);
    }
    if(item > root->data){
        //Insert @ right
        root->right = insert(root->right, item);
    }
    else if(item < root->data){
        //Insert @left
        root->left = insert(root->left, item);
    }
    else{
        //Duplicate;
        return root;
    }
    bal_factor = getbalance(root);
    // cout << "balance factor is " << bal_factor << " for " << root->data << endl;
    //If bal_factor > +1 (Imbalance @ left hand side)
    //If bal_factor < -1 (Imbalance @ right hand side)

    if(bal_factor > 1 && item < root->left->data ){
        //LL combination
        return rightrotate(root);
    }

    else if (bal_factor > 1 && item > root->left->data){
        //LR combination
        root->left = leftrotate(root->left);
        return rightrotate(root);

    }

    else if(bal_factor < -1 && item > root->right->data)
    {

        //RR combination
        return leftrotate(root);

    }
    else if(bal_factor < -1 && item < root->right->data){
        //RL combination
        root->right = rightrotate(root->right);
        return leftrotate(root);

    }
    //Adjust height of old and new root after rotaion.
    root->height = max(get_height(root->left), get_height(root->right)) + 1 ;
    return root;

}

node *delete_node(node *root, int item){
    int bal_factor = 0;
    if(root == NULL)
        return root;
    if(item > root->data){
        //Insert @ right
        root->right = delete_node(root->right, item);
    }
    else if(item < root->data){
        //Insert @left
        root->left = delete_node(root->left, item);
    }
    else {
        node *cur=NULL;

        if(root->left == NULL || root->right == NULL){
            // 1: No child || only left child || only right child
            if(root->left != NULL){
                cur = root->left;
                *root = *cur;
                delete(cur);
                root->left = NULL;

            }
            else if(root->right != NULL){
                cur = root->right;
                *root = *cur;
                delete(cur);
                root->right = NULL;

            }
            else {
                delete(root);
                root=NULL;
            }

        }
        else {
            //It has both left & right subtree
            cur = get_min_node(root->right);
            cout << "Inorder succ is " << cur->data << endl;
            root->data = cur->data;
            root->right = delete_node(root->right, cur->data);

        }

    }
    if(root == NULL)
        return root;

    bal_factor = getbalance(root);
    node *cleft = root->left;
    node *cright = root->right;

    if(bal_factor > 1 &&  get_height(cleft->left) >= get_height(cleft->right) ){
        //LL combination
        return rightrotate(root);
    }
    else if(bal_factor > 1 &&  get_height(cleft->left) < get_height(cleft->right) ){
        root->left = leftrotate(root->left);
        return rightrotate(root);

        //LR combination

    }
    else if(bal_factor < -1 && get_height(cright->left) <= get_height(cright->right))
    {

        //RR combination
        return leftrotate(root);

    }
    else if(bal_factor < -1 && get_height(cright->left) > get_height(cright->right)){
        //RL combination
        root->right = rightrotate(root->right);
        return leftrotate(root);

    }


   return root;

}

int main(){
    node *root=NULL;
    // root = insert(root, 10);
    // root = insert(root, 8);
    // root = insert(root, 5);

    // root = delete_node(root, 8);


    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 5);
    root = insert(root, -1);
    root = insert(root, 11);
    root = insert(root, 2);
    root = insert(root, 6);

    root = delete_node(root, 0  );

    // root = insert(root, 25);
    // root = insert(root, 35);
    // root = insert(root, 50);
    // root = insert(root, 28);

    cout << "Preorder traversal: " << endl;
    preorder(root);

    cout << "Inorder traversal" << endl;
    inorder(root);


    return 0;
}

