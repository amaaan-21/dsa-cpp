#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int>* l;
public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addedge(int u, int v){
        //undirected graph: add the edge in both directions.
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs(int source = 0 ){
        queue<int> q;
        vector<bool> vis(V, false);
        
        // start bfs from source vertex
        q.push(source);
        vis[source] = true;

        while( !q.empty()) {
            int u = q.front();
            q.pop();

            cout<< u<< " ";

            //explore the neighbours of the current vertex.
            for ( int v : l[u]) {
                // check the neighbours of the current vertex.
                if(!vis[v]) {
                    // mark it before adding it to avoid duplicates.
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout<< endl;
    }
    ~Graph(){
        //release the dynamically allocated adjacency list.
        delete[] l;
    }
};

int main () {
    Graph g(5);
    
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(2,3);

    g.bfs(0);

    return 0;
}
