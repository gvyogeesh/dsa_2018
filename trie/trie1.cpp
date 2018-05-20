/* Demonstration of trie */
#include <iostream>
#define SIZE 256
using namespace std;


struct trie{
    bool is_end;
    string word;
    trie *children[256];
};

trie *getnode(){
    trie *cur = new trie();
    cur->is_end = false;
    for(int i=0; i<SIZE; i++){
        cur->children[i] = NULL;
    }
    return cur;
}
void insert(trie *root, string key){
    int idx;
    trie *cur =root;
   for(int i=0;i<key.length(); i++){
    // cout << key[0] << endl;
    // idx = key[i] - 'a';
    if(cur->children[key[i]] == NULL){
        cur->children[key[i]] = getnode();
    }
    cur = cur->children[key[i]];

   }
   cur->is_end = true;
   cur->word = key;
}
//     *
// hello
bool search(trie *root, string key){
    trie *cur = root;
    int idx;
    for(int i=0; i< key.length();i++){
        // idx = key[i] - 'a';
        if(cur->children[key[i]] == NULL)
            return false;
        cur = cur->children[key[i]];
    }
    if(cur->is_end == true)
        return true;
    return false;
}
bool is_delete(trie *root){
    for (int i=0;i<SIZE;i++){
        if(root->children[i] != NULL)
            return false;
    }
    return true;

}
bool delete_util(trie *root, string key, int st, int end){
    if(root != NULL){
        if(st == end){
            root->is_end = false;
            if(is_delete(root))
                return true;
            return false;
        }
        if(delete_util(root->children[key[st]], key, st+1, end) == true)
        {
            // break the link;
            //check current node is deletable or not, if deletable return true
            // else return false;

            // cout << "deallocating memory" << key[st] << endl;
            delete(root->children[key[st]]);
            root->children[key[st]] =  NULL;

            if(is_delete(root) && root->is_end == false)
                return true;
            return false;

        }
        else
            return false;

    }
    return false;
}
void delete_key(trie *root, string key){
    delete_util(root, key, 0, key.length());
}
void print_trie(trie *root){
    if(root!=NULL){
        if(root->is_end == true)
            cout << root->word << endl;
        for(int i=0;i<SIZE;i++){
            if(root->children[i] != NULL)
                print_trie(root->children[i]);
        }

    }
    return;
}
void auto_complete(trie *root, string key){
    trie *cur=root;
    for(int i=0;i<key.length();i++){
        if(cur == NULL)
            return;

        cur = cur->children[key[i]];
    }
    print_trie(cur);
}
int main(){
    trie *root= getnode();

    insert(root, "hello");
    insert(root, "hello world");
    insert(root, "hello ind");
    insert(root, "hello blr");

    insert(root, "hell");
    insert(root, "geek");
    insert(root, "geeks*geek");
    insert(root, "geeksforgeeks");
    insert(root, "geeks122");
    insert(root, "geeks122");
    insert(root, "geeks123");
    insert(root, "geeks124");
    insert(root, "geeks125");

    // delete_key(root, "hello world");
    cout << search(root, "hello world") << endl;
    cout << search(root, "hello") << endl;
    auto_complete(root, "hello ");
    // cout << search(root, "hello world") << endl;
    // cout << search(root, "geek*geek") << endl;


    return 0;
}
