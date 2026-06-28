/*Problem Statement
Write a recursive function that returns the value of:
Plain text
xn
where:
• x is the base.
• n is a non-negative integer.
Do not use loops or the built-in pow() function.
Example 1
Input
Plain text
x =
n = 5
Output
Plain text
32 */
#include<iostream>
using namespace std;
int product(int x, int n){
    //base case
    if (n==0){
        return 1;}
    return x* product(x, n-1);
}
int main(){
    cout<<product(2,2);
    return 0;
}
