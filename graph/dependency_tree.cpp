/* Topological Sorting */

#include <iostream>
#include <stack>
#include <vector>
#include <list>

using namespace std;

vector<int>parent(6, -1);
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


    void dfs(int src, stack<int>&output, vector<bool>&visited, vector<bool>&aux){
        visited[src] = true;
        aux[src] = true;
        int i=0;
        for(list<int>::iterator it=adj[src].begin(); it!=adj[src].end();it++){

            parent[*it]=src;
            if(visited[*it] == true && (aux[*it] == true)){
                cout << "Circular dependency is detected" << endl;
                cout << *it << " : " << parent[*it] << endl;
                i=*it;

                while(parent[i] != *it){
                    cout << i << " <-- " << parent[i] << " " ;
                    i= parent[i];
                }
                cout <<i << "<--" << parent[i] << " " ;
                cout << endl;
                // for( i=0; i<parent.size();i++){
                //     cout << i << ":" << parent[i] <<endl;
                // }
                aux[src] = false;
                return;
            }
            if(visited[*it] == false){
                dfs(*it, output, visited, aux);
            }
        }
        output.push(src);
        aux[src] = false;
        return;
    }

    void resolve_dependecy(){
        vector<bool>visited(ver, false);
        vector<bool>aux(ver, false);
        stack<int>result;
        for(int i=0; i< ver;i++){
            if(visited[i] == false){
                dfs(i, result, visited, aux);
                // for(int i=0; i<visited.size();i++)
                //     cout << visited[i] <<  "  ";
                // cout << endl;

                // for(int i=0; i<aux.size();i++)
                //     cout << aux[i] <<  "  ";

                // cout << endl;
            }
        }
        while(result.empty() != true){
            cout << result.top() << "  ";
            result.pop();
        }
        cout << endl;
    }

};

int main()
{
    Graph g(6);
    g.add_edge(0, 2);
    g.add_edge(4, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(5, 0);
    g.add_edge(5, 1);

    g.resolve_dependecy();

}
