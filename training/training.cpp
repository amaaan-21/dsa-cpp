//write a recursive funnction to find
//    x^n

#include<iostream>
using namespace std;
int product(int x, int n){
    //base case
    if(n == 0){
        return 1;
    }

    return x * product(x, n-1);
}
int main (){
    cout<<product(2,8);
    return 0;
}