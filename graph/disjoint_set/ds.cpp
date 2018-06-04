#include <iostream>
#include <map>
#include <vector>
using namespace std;


struct node{
    int ver;
    int rank;
    struct node *parent;
};
map<int, node*>my_map;

void make_set(int data){
    node *cur = new node();
    cur->ver = data;
    cur->rank = 0;
    cur->parent = cur;
    my_map[data] = cur;
}

node* findset(node *cur){
    if(cur->parent == cur)
        return cur;

    cur->parent = findset(cur->parent);
    // cout <<"test" <<cur->parent->ver << endl;
    return cur->parent;
}

int find_wrap(int ver){
    node *cur = my_map[ver];
    cur = findset(cur);
    cout << "Parent is " << cur->ver <<endl;
    return cur->ver;
}
void union_set(int src, int des){
    node *key1, *key2;
    key1 = findset(my_map[src]);
    key2 = findset(my_map[des]);
    if(key1 == key2){
        cout << "Cycle found!" << endl;
        return;
    }
    // cout << "key1 " << key1->ver << " Rank " << key1->rank << endl;
    // cout << "key2 " << key2->ver << " Rank " << key2->rank << endl;
    if(key1->rank >= key2->rank){
        key1->rank = (key1->rank == key2->rank)?(key1->rank + 1):(key1->rank);
        key2->parent = key1;

    }
    else{
        key1->parent = key2;
    }

    cout << key1->rank << endl;
    return ;
}
int main(){
    for(int i=0;i<6;i++){
        make_set(i);
    }
    vector<pair<int, int> >edge(6);
    edge[0].first = 0;
    edge[0].second = 1;

    edge[1].first = 0;
    edge[1].second = 4;

    edge[2].first = 0;
    edge[2].second = 3;

    edge[3].first = 1;
    edge[3].second = 2;

    edge[4].first = 2;
    edge[4].second = 3;

    edge[5].first = 3;
    edge[5].second = 4;

    for(int i=0;i<edge.size();i++){
        union_set(edge[i].first, edge[i].second);


    }

    // make_set(0);
    // make_set(1);
    // make_set(2);
    // make_set(4);
    // make_set(5);

    // make_set(6);
    // make_set(7);
    // make_set(8);
    // make_set(9);
    // make_set(10);
    // make_set(11);
    // make_set(12);
    // make_set(13);

    // union_set(6, 7);
    // union_set(8, 9);
    // union_set(10, 11);
    // union_set(12, 13);

    // union_set(7, 9);
    // union_set(10, 12);
    // union_set(6, 10);

    // union_set(0, 1);
    // union_set(2, 4);
    // find_wrap(1);
    // find_wrap(4);
    // union_set(1, 4);
    // find_wrap(2);
    // union_set(4, 5);
    // find_wrap(5);

    // union_set(0, 6);
    // find_wrap(13);


    return 0;
}
