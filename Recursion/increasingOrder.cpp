/*Write a recursive function that 
//prints numbers from 1 to N*/

#include <iostream>
using namespace std;
void print1ToN(int n){
    //base case
    if(n==0){
        return;
    
}
    //recursion
    print1ToN(n-1);
    //work
    cout<<n<<", ";
}
int main() {
    print1ToN(9);
    return 0;
}