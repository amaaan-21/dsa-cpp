/*🚀 Problem 2: Print N → 1

Problem

Write a recursive function to print
5 4 3 2 1 */
#include<iostream>
using namespace std;
void printNtoOne(int n){
    if(n== 0){
        return;}
    cout<<n<<", ";
    printNtoOne(n-1);
}
int main(){
    printNtoOne(9);
    return 0;
}