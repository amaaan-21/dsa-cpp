/*Write a recursive function that returns the factorial of a given positive integer N.

The factorial of a number is defined as:
Example 1
Input
Plain text
n = 5
Output
Plain text
120
Explanation
Plain text
5 × 4 × 3 × 2 × 1 = 120*/
#include<iostream>
using namespace std;
int factorial(int n){
    //base case
    if(n==0){
        return 1;
    }

    //work 
    return n * factorial(n-1);
}
int main(){
    cout<<factorial(4);
    return 0;
}