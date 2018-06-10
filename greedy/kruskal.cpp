#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct edge{
    int src;
    int des;
    int wt;
};
bool compare(edge e1, edge e2){
    return e1.wt < e2.wt;
}

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
void kruskal_util(edge *e, int size){
    vector<pair<int, int> >result;
    sort(e, e+size, compare);
    for(int i=0;i<size;i++){
        node *key1, *key2;
        key1 = findset(my_map[e[i].src]);
        key2 = findset(my_map[e[i].des]);
        if(key1 == key2){
            continue;
        }

        union_set(e[i].src, e[i].des);
        result.push_back(make_pair(e[i].src, e[i].des));

    }

    for(int i=0; i<result.size();i++)
        cout << result[i].first << " : " << result[i].second << endl;

}
int main(){
    for(int i=0;i<6;i++){
        make_set(i);
    }
    // vector<> >edge(6);
    struct edge e[8];
    e[0].src = 0;
    e[0].des = 1;
    e[0].wt = 6;

    e[1].src = 0;
    e[1].des = 4;
    e[1].wt = 4;

    e[2].src = 1;
    e[2].des = 2;
    e[2].wt = 2;

    e[3].src = 1;
    e[3].des = 4;
    e[3].wt = 1;

    e[4].src = 2;
    e[4].des = 3;
    e[4].wt = 7;

    e[5].src = 2;
    e[5].des = 5;
    e[5].wt = 2;

    e[6].src = 4;
    e[6].des = 5;
    e[6].wt = 8;

    e[7].src = 5;
    e[7].des = 3;
    e[7].wt = 1;

    kruskal_util(e, 8);





    return 0;
}
