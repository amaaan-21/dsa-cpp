//queue is fifo (first in first out)
//a coffee shop first first serve checkout from shop

#include<iostream>
#include<queue>
using namespace std;

int main (){
    queue<int> q;
    q.push(8);
    q.push(9);
    q.push(10);

    /*
    print all queue i can't use regular iteration for print 
    all q so i create a copy or original queue and start 
    pritint queue.front(); and pop.queue(); it's Fifo so front pop i print queue front until my 
    !copy_queue.empty();
    */

    //copy queue
    queue<int> copy = q;
    // start while list
    while(!copy.empty()){
        cout<<copy.front()<< ", ";
        copy.pop();
    }
    cout<<endl;
   

    q.pop();
queue<int> copyII=q;
 while(!copyII.empty()){
        cout<<copyII.front()<< ", ";
        copyII.pop();
    }
    cout<<endl;

    return 0;


}

    
