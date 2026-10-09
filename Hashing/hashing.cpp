#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node (string key, int val){
        this-> key = key;
        this-> val = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;
    Node** table;

    int HashFunction( string key){
        int idx = 0;

        for(int i = 0; i < key.size(); i++){
            idx = (idx + key[i] * key[i])%totSize;
            }
            return idx%totSize;
        }

    void rehash(){
        Node** oldTable = table;
        int oldSize = totSize;

        totSize = 2 * totSize;
        table = new Node*[totSize];
        currSize = 0;
        for(int i = 0; i<totSize; i++){
            table[i] = NULL;
        }

        //copy old values

        for(int i = 0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp -> next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];}
        }
        delete[] oldTable;
    
    }


public:
    HashTable(int size) {
        totSize = size;
        currSize = 0;

        table = new Node* [totSize];

        for(int i = 0; i<totSize; i++){
            table[i] = NULL;
        }

    }

    void insert(string key, int val){
        int idx = HashFunction(key);

        Node* newNode = new Node(key, val);
        Node* head = table[idx];

        newNode->next = head;

        currSize++;

        
        double lambda = currSize / (double) totSize;
        if(lambda > 1 ){
            rehash();
        }
    }

    bool exists (string key){
        int idx = HashFunction(key);

        
        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp -> key == key) {
                return true;
            }
            temp = temp -> next;

        }
        return false;
    };

    
    
    int search(string key) {
         int idx = HashFunction(key);

        Node* temp = table[idx];
        
        while(temp != NULL) {
            if(temp -> key == key) {
                return temp -> val;
            }
            temp = temp -> next;

        }
        return -1;
    
    }




    void remove(string key){
        int idx = HashFunction(key);
        Node* temp = table[i];
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp -> key == key){//erase
                if(prev == temp){//head
                table[idx] = temp -> next;
            } else {
                prev -> next = temp -> next;
            }
            temp->next = NULL;
            delete temp;
            currSize--;
            break;
            }
            prev = temp;
            temp = temp -> next;
        }
    }


    void print(){
        for(int i=0; i<totSize; i++){
            cout<< "idx" << i << "->";
            Node* temp = table[i];
            while(temp!=NULL){
                cout<<"("<<temp->key <<", "<<temp->val << " ->";
                temp = temp -> next;
            }
            cout<<endl;
        }
    }
};

  int main(){
    HashTable ht(5);

    ht.insert("India", 150);
    ht.insert("China", 80);
    ht.insert("US", 130);
    ht.insert("Kalu", 400);


    if(ht.exists("India")){
        cout<<"India population : "<< ht.search("India") << endl;
    }
    return 0;
}

