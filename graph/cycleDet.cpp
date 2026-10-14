//i am writing a code to find the cycle detection in graph
#include<iostream>
#include<string>
#include<queue>
#include<list>
#include<vector>
using namespace std;

class Graph{
    int v;
    list<int> *l;
public:
    Graph(int v){
        this-> v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v]. push_back(u);
    }
    void print(){
        for(int i = 0; i < v; i++){
            list<int> neighbors = l[i];
            cout<< i << " : ";
            for(int v : neighbors){
                cout<< v <<" " ;
            }
            cout<<endl;
        }
    }

    bool underectedCycleHelper(int src, int par, vector<bool>& vis){
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                if(underectedCycleHelper(v,src,vis)){
                return true; 
                        }   
                } else if (v!=par){
                    return true;
                }
            }
        return false;
    }

    bool isCycleUndirected (){ 
        vector<bool> vis(v,false);
        return underectedCycleHelper(0, -1, vis);
    }

};

int main (){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    g.print();

    cout<< g.isCycleUndirected()<< endl;

    return 0;
}