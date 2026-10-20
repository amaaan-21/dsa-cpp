// write a dfs code if graph is not connected
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;


class Graph{
    int v;
    list<int> *l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }

    void print(){
        for(int i = 0; i < v; i++){
            list<int> neighbors = l[i];
            cout<< i <<" : ";
            for(int v : neighbors ){
                cout<< v <<" " ;
            }
            cout << endl;
        }
    }

    void dfsHelper(int u, vector<bool> &vis){
        vis[u] = true;
        cout << u << " ";

        list<int> neighbors = l[u];
        for( int v: neighbors) {
            if(!vis[v]) {
                dfsHelper(v, vis);//starting pt = i
               
            }
        }
        cout<<endl;
    }

    void dfs(){
        vector<bool> vis(v, false);
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                dfsHelper(i,vis);
                 cout<<endl;
            }
        }
        cout<< endl;
    }
};

    int main(){
        Graph g(10);
        g.addEdge(1,6);
        g.addEdge(6,4);
        g.addEdge(4,9);
        g.addEdge(4,3);
        g.addEdge(3,8);
        g.addEdge(3,7);
        g.addEdge(2,5);
        g.addEdge(2,0);

        g.dfs();


        return 0;
    }

