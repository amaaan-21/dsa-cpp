//depth first search in graph (recursion visit next neighbour back track to is any non visited neighbors);
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include<string>
using namespace std;

class Graph{
    int v; //vertex
    list<int>* l;
public:
    Graph(int v){
        this->v=v;
        l = new list<int>[v];
    }

void addEdge(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
}

void print(){
    for(int i = 0; i < v; i++){
        list<int> neighbors = l[i];
        cout<< i <<":";
        for(int v : neighbors){
            cout<< v << " ";
        }
        cout << endl;
    }
}

void dfsHelper(int u, vector<bool> &vis){ //O(V+E)
    vis[u] = true;
    cout << u << " ";

    list<int> neighbors = l[u];
    for(int v : neighbors) {
        if(!vis[v]) {
        }
    }
}
void dfs(){
    vector<bool> vis(n, false);
    dfsHelper(0, vis);
    cout << endl;
}



};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    // g.print();
    g.dfs();

    return 0;

}