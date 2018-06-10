#include <iostream>
#include <set>
#include <list>
#include <vector>
using namespace std;

class compare{
    bool operator()(pair<int, int> src, pair<int, int>des){
        return src.second < des.second;
    }
};


class Graph{
    int ver;
    list<pair<int, int> >*adj;
public:
    Graph(int v){
        ver =v ;
                        //  des   wt
        adj = new list<pair<int, int> >[v];
    }
    void add_edge(int src, int des, int weight){
        adj[src].push_back(make_pair(des, weight));
        adj[des].push_back(make_pair(src, weight));
    }

    void dijkstra(int src);
};
void Graph::dijkstra(int src){
    vector<int>result(ver, INT_MAX);
    result[src] = 0;
    int u, v, weight;
    set<pair<int, int> >my_set;
    my_set.insert(make_pair(src, 0));
    vector<bool>visited(ver, false);
    set<pair<int, int> > :: iterator tmp;

    while(my_set.empty() == false){
        pair<int, int> cur = *(my_set.begin());
        my_set.erase(my_set.begin());
        u = cur.first;


        for(list<pair<int, int> >::iterator it= adj[u].begin();it!= adj[u].end();it++){
            v = it->first;
            weight = it->second;
            // cout << "u : " << u  << " : "<< result[u] << endl;
            // cout << "v : " << v  << " : "<< result[v] << endl;
             if(result[u] != INT_MAX && (result[v] > (result[u] + weight))){

                if(result[v] != INT_MAX){
                    tmp = my_set.find(make_pair(v, result[v]));
                    if(tmp != my_set.end())
                        my_set.erase(tmp);
                }
                result[v] = result[u] + weight;
                my_set.insert(make_pair(v, weight));
                // cout << it->first << ":" << it->second << endl;

            }

        }
    }
    for(int i=0; i< result.size();i++){
        cout << result[i] << "  ";
    }
    cout << endl;
}

int main(){
    Graph g(6);

    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 8);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 8);
    g.add_edge(2, 4, 1);
    g.add_edge(3, 4, 1);
    g.add_edge(3, 5, 1);
    g.add_edge(4, 5, 3);

    g.dijkstra(0);



    return 0;
}
