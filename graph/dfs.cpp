#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
    int ver;
    list<int>*adj;
public:
    Graph(int v){
        ver =v ;
        adj = new list<int>[v];
    }
    void add_edge(int src, int des){
        adj[src].push_back(des);
    }
    void print_graph(){
        for(int i=0; i<ver;i++){
            for(list<int>::iterator it= adj[i].begin();it!= adj[i].end();it++){
                cout << i << ": " << *it << endl;
            }
        }
    }
    void dfs(int src, bool visited[]){

        visited[src] = true;
        cout << src << endl;
        for(list<int>::iterator it= adj[src].begin();it!= adj[src].end();it++){
            if(visited[*it] ==  false){
                dfs(*it, visited);
            }
        }

    }

    void dfs_iter(int src, bool visited[]){
        stack<int>my_stk;
        my_stk.push(src);
        while(my_stk.empty() == false){
            int cur = my_stk.top();
            my_stk.pop();
            cout << cur << endl;
            visited[cur] = true;
            for(list<int>::iterator it= adj[cur].begin();it!= adj[cur].end();it++){
                if(visited[*it] ==  false)
                   my_stk.push(*it);
           }

       }

    }
};

int main(){
    int v = 9;
    Graph g(v);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);

    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(2, 5);


    g.add_edge(3, 4);
    g.add_edge(3, 5);

    g.add_edge(6, 7);
    g.add_edge(7, 8);
    g.add_edge(8, 6);

    bool visited[v];
    // bool *visited = new bool[4];
    cout << "DFS" << endl;
    for(int i=0; i<v;i++){
        visited[i] =  false;
    }
    for(int i=0; i<v; i++){
        if(visited[i] == false)
            g.dfs(i,visited);
    }

    for(int i=0; i<v;i++){
        visited[i] =  false;
    }
    cout <<"DFS iter" << endl;
    for(int i=0; i<v; i++){
        if(visited[i] == false)
            g.dfs_iter(i, visited);
    }


    g.print_graph();

    return 0;
}
