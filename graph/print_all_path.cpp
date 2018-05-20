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
    void dfs(int src, int des, bool visited[], int path_info[], int &idx, int &count){

        path_info[idx] = src;
        idx++;
        visited[src] = true;

        if(src == des){
            count++;
            cout << "Count is " << count << endl;
            for(int i=0; i<idx;i++){
                cout << path_info[i] << "  ";
            }
            cout << endl;
        }


        // cout << src << endl;
        for(list<int>::iterator it= adj[src].begin();it!= adj[src].end();it++){
            if(visited[*it] ==  false){
                dfs(*it, des, visited, path_info, idx, count);
            }
        }
        visited[src] = false;
        idx--;

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

    g.add_edge(5, 4);
    g.add_edge(6, 7);
    g.add_edge(7, 8);
    g.add_edge(8, 6);

    bool visited[v];
    // bool *visited = new bool[4];
    cout << "DFS" << endl;
    for(int i=0; i<v;i++){
        visited[i] =  false;
    }
    int path_info[v];
    int idx = 0;
    int cnt = 0;

    g.dfs(0,4,visited,path_info, idx, cnt);



    g.print_graph();

    return 0;
}
