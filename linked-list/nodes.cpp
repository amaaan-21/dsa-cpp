//how to create nodes from scratch without using stl library
#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
puplic:
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public;
    List(){
        head = NULL;
        tail = NULL;
    }
};

int main () {


    return 0;
}