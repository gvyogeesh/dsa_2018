#include <iostream>
#include <list>
#include <queue>
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
    void bfs(int src, bool visited[]){
        queue<int>my_que;
        my_que.push(src);
        int cur;
        visited[src] = true;
        while(my_que.empty() == false){
            cur = my_que.front();
            my_que.pop();
            cout << cur << endl;
            for(list<int>::iterator it= adj[cur].begin();it!= adj[cur].end();it++){
                if(visited[*it] == false){
                    visited[*it] = true;
                    my_que.push(*it);
                }
            }


        }
        return;
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
            g.bfs(i, visited);
    }

    g.print_graph();

    return 0;
}
