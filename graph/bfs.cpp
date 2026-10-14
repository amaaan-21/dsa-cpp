#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<string>

using namespace std;

class Graph{
    int v;
    list<int> *l;
public:
    Graph(int v){
        this -> v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printVertex_Edge(){
        for(int i = 0; i < v; i++){
            list<int> neighbors = l[i];
            cout<<i<<" : ";
            for( int v : neighbors){
                cout<< v << " ";
            }
            cout<< endl;
        }
    } 

    void bfs(){
        queue<int> q;
        vector<bool> vis(v, false);
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int u = q.front();//current vertex
            q.pop();
            cout << u << " ";
            
            list<int> neighbors = l[u];
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout<< endl;
    }









};

int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.printVertex_Edge();
    g.bfs();

    return 0;
}
