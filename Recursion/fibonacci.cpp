/*
Write a recursive function that returns the Nth Fibonacci number.

The Fibonacci sequence is:
0, 1, 1, 2, 3, 5, 8, 13, ...
Example
Input
Plain text
n = 6
Output
Plain text
8
*/
#include<iostream>
using namespace std;
int fibonacci(int n){
    //base case hit
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    
    return fibonacci(n-1)+ fibonacci(n-2);
}
int main(){
    cout<<fibonacci(6);
    return 0;
}