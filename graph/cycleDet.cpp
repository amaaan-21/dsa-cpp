//i am writing a code to find the cycle detection in graph
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int vert){
        V = vert;
        l = new list<int>[V];
    }
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int i = 0; i<V; i++){
            list<int> neighbours =l[i];
            cout<< i << " : ";
            for(int v : neighbours){
                cout<< v << " ";
            }
            cout<<endl;
        }
    }

    void dfsHelper(int u, vector<bool> &vis, int par){
        vis[u] = true;
        cout<<u <<" ";
        list<int> neighbours = l[u];
        for(int v: neighbours){
            if(!vis[v]){
                dfsHelper(v, vis,3);
            }else if(v == par){
                cout<<"it has cycle"<<endl;
                return ;
            }
             if(v!=par){
         cout<< "it has no cycle";}
            
            
        }
       
         
    }
   
    void dfsFindCycle(){
        vector<bool>vis(V, false);
        dfsHelper(5, vis,3);
        cout<<endl;
    }
    
};


int main(){
    Graph g(6);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(2,6);
    g.addEdge(1,3);
    g.print();
    g.dfsFindCycle();

    return 0;
}