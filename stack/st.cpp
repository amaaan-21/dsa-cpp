//create a stack using vector
#include <iostream>
#include <vector>
using namespace std;

class Stack{
    vector<int> vec;
public:
    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout << "stack is empty. \n";
            return;
        }
        vec.pop_back();
    }

    int top() {
        int lstIdx = vec.size() - 1;
        return vec[lstIdx];
    }
    
    bool isEmpty() {
        return vec.size() == 0;
    }
};

int main(){
    Stack s;
    s.push(9);
    s.push(2);
    cout<<s.top();
    while (!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
