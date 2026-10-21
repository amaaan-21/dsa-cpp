/*
 * Author: Amanullah Siddique
 * File: queue.cpp
 * Created: Wednesday, 2026-10-21 at 13:51
 */

 #include<iostream>
 #include<queue>
 using namespace std;
int main(){
    queue<int> q;
    q.push(5);
    q.push(2);
    q.push(4);

    //print q 
    //we can't use loop directly in queye
    queue<int> copy =   q;
    while(!copy.empty()){
        cout<<copy.front()<<", ";
        copy.pop();
    }
    return 0;
}

