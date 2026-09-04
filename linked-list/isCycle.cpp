// Find whether linked list has a cycle or not
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // Getter
    Node* getHead() {
        return head;
    }

    // Create cycle
    void createCycle() {
        if (tail != NULL) {
            tail->next = head;
        }
    }
};


// Floyd's Cycle Detection Algorithm
bool isCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;          // +1
        fast = fast->next->next;    // +2

        if (slow == fast) {
            cout << "cycle exists\n";
            return true;
        }
    }

    cout << "cycle doesn't exist\n";
    return false;
}


int main() {

    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // 1 -> 2 -> 3 -> 4 -> 1
    ll.createCycle();

    isCycle(ll.getHead());

    return 0;
}




