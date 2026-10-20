//find the disconeected graph through bfs
#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    void printGraph(){
        for(int i = 0; i < v; i++){
            list<int> neighbors = l[i];
            cout<<i << ": ";
            for(int v : neighbors){
                cout<< v << ", ";
            }
            cout<<endl;
        }
    }

    void bfsHelper(int st, vector<bool> &vis){
        queue<int>q;
        
        q.push(st);
        vis[st]= true;
         
        while(!q.empty()){
            int u = q.front();//current vertex
            q.pop();
            cout<< u << " ";

            list<int> neighbors = l[u];
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v]= true;
                    q.push(v);
                }
            }
            cout<<", ";
        }
    }

    void bfs(){
        vector<bool> vis(v, false);
        for(int i = 0; i < v; i++){
            if(!vis[i]) {
                bfsHelper(i, vis);
                
            }
        }
        
    }
        
    };

    int main (){
        Graph g(10);
        g.addEdge(1,6);
        g.addEdge(6,4);
        g.addEdge(4,9);
        g.addEdge(4,3);
        g.addEdge(3,8);
        g.addEdge(3,7);

        g.addEdge(2,0);
        g.addEdge(2,5);

        g.printGraph();

        cout<<"now bfs run : " <<endl;
        g.bfs();

        return 0;
    }
