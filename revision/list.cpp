/*
 * Author: Amanullah Siddique
 * File: list.cpp
 * Created: Wednesday, 2026-10-21 at 14:02
 */

#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l;
    l.push_back(0);
    l.push_front(8);
    l.push_back(76);
    l.push_front(2);
    l.push_front(1);
    l.pop_front();
    l.pop_back();
    for(int i : l){
        cout<<i<<"<";
    }
    return 0;
}