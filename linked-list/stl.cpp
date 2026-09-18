#include<iostream> 
#include<list>
#include<iterator>
using namespace std;

void printList(list<int>ll){
    list<int> ::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout<<(*itr)<<" ->" ;
    }
    cout<<endl;
}



int main(){
    list<int>ll;
    ll.push_back(9);
    ll.push_front(10);
    printList(ll);
    cout<<endl;
    cout<<ll.size();

    return 0;
}