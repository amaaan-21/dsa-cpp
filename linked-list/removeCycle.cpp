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
      // push _ back ( ) ;
 void push_back(int val){
    Node* newNode= new Node(val);
    if(head== NULL) {
        head = tail = newNode;
    } else {
        tail -> next = newNode;
        tail = newNode;
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

        Node* splitAtMid(Node* head) {
            Node* slow = head;
            Node* fast = head;
            Node* prev = NULL;

            while(fast != NULL && fast -> next != NULL){
                prev = slow;
                slow = slow -> next;
                fast = fast -> next -> next;
            }
            if(prev != NULL ){
                prev -> next = NULL; //split at middle
            }
            
            return slow; //slow= new right head;
        }

        Node* merge(Node* left, Node* right){
            List ans;
            Node* i = left;
            Node* j = right;

            while(i != NULL && j != NULL){
                if(i -> data <= j->data){
                    ans.push_back(i->data);
                    i = i -> next;
                } else {
                    ans.push_back( j -> data);
                }
            }

            while( i != NULL){
                ans.push_back( i -> data);
                i = i -> next;
            }

            while( j != NULL){
                ans.push_back( j -> data);
                j = j -> next;
            }

            return ans.head;
        }


        Node* mergeSort(Node* head){
            if(head == NULL || head -> next == NULL){
                return head;
            }
            Node* rightHead = splitAtMid(head);

            Node* left = mergeSort(head); //left head
            Node * right = mergeSort(rightHead);//righthead

           return merge(left, right); //head of sorted LL
        }
    
        Node* reverse(Node* head){
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;

            while( curr!= NULL){
                next = curr -> next;
                curr -> next = prev;

                prev = curr;
                curr = next;
            }
            return prev; //prev is head of rev
            
        }

        Node* zigZag(Node* head){
            Node* rightHead = splitAtMid(head);
            Node* rightHeadRev = reverse(rightHead);
            //alternate merging
            Node* left= head;
            Node* right= rightHeadRev;

            while(left != NULL && right != NULL){
                Node* nextLeft = left->next;
                Node* nextRight = right->next;

                left->next = right;
                right -> next = nextLeft;

                tail = right;

                left = nextLeft;
                right = nextRight;
            }
            if (right != NULL){
                tail -> next = right;
            }
            return head;
        }


    };

    
    int main (){
        List ll;
        ll.push_front(4);
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1);
        ll.push_front(9);
        // ll.tail->next = ll.head;
        // ll.removeCycle(ll.head);
        
        ll.printList(ll.head);
        ll.head = ll.zigZag(ll.head);
        ll.printList(ll.head);

        return 0;
    }