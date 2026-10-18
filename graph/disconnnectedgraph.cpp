// write a dfs code if graph is not connected
#include<iostream>
#include<vector>
#include<list>
#include<queue>

class Graph{
    int v;
    list<int> *l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }

    void addEdge(){
        l[u].push_back(v);
        l[v].push_back(u);

    }

    void print(){
        for(int i = 0; i < v; i++){
            list<int> neighbors = l[i];
            cout<< i <<" : ";
            fot(int v ){
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
                dfsHelper(i, vis);//starting pt = i
            }
        }
        cout<<endl;
    }

    void dfs(){
        vector<bool> vis(v, false);
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                dfsHelper(i,vis);
            }
        }
        cout<< endl;
    }
    
