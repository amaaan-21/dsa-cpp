/*
list is similar to queue like half queue
differ between queue and list is in queue we can only add and remomve from front but list both side
*/
#include<iostream> 
#include<list>
using namespace std;

int main(){
    list<int> l;
    l.push_back(9);
    l.push_back(8);
    l.push_front(1);
    l.push_front(0);

    for(int i : l){
        cout<<i <<",";
    }

    return 0;
}