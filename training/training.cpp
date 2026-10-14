#include<iostream>
using namespace std;
//print number 1 to n by recursion
//time complexity O(n) even its recursion becuase number of iteration n time
void printOneToN(int n){
    if(n == 0){
        return;
    }

    //recursion
     printOneToN(n-1);
    //work
    cout<<n<<", ";
}
int main(){

    printOneToN(5);

    return 0;
}