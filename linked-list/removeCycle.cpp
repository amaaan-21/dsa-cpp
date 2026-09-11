//remove cyvle from linked list 
//1 check link list has cycle or not
//2 in no return, if yes then slow = head but fast remain same now this time i increasing by +1  both slow and fast and recor prev fast 
//when the both fast and slow meat at the same time again
//then prev ->next = NULL; break cycle now

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data= data;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
        } else{
            newNode->next = head;
            head = newNode;
        }
    }

        void pop_front(int val){
            if(head == NULL) {
                return;
            }
            Node* temp = head;
            head = head -> next;

            temp -> next = NULL;
            delete temp;
        }

        void printList(Node* head){
        Node* temp = head;
        while(temp !=NULL){
            cout<< temp -> data << " -> " ;
            temp = temp -> next;
            }
        cout<<"NULL\n";
        }


        //remove cycle from Node;
        void removeCycle(Node* head){
            //detect a cycle first
            Node* slow = head;
            Node* fast = head;
            bool isCycle = false;
            while(fast != NULL && fast -> next != NULL){
                slow = slow -> next;
                fast = fast -> next -> next;
                if(slow == fast){
                    cout<< "cycle exist\n";
                    isCycle = true;
                    break;
                }
               
            }
                if(!isCycle){
                                    cout<<"cycle doesn't exists\n";
                                    return;
                                }
                //next step aftet detecting cycle in link list
                slow = head;
                //special case when tail directly connected to head
                if(slow == fast){
                    while(fast -> next != slow){
                        fast = fast -> next;
                    }
                        fast -> next = NULL;  
                } else {
                    Node* prev = fast;
                    while(slow !=fast){
                        slow = slow -> next;
                    prev = fast;
                    fast = fast -> next;
                }
                //now remove cycle
                prev -> next = NULL;
            }
                    

        }


    };

    
    int main (){
        List ll;
        ll.push_front(4);
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1);
        ll.push_front(9);
        ll.tail->next = ll.head;
        ll.removeCycle(ll.head);
        ll.printList(ll.head);

        return 0;
    }