#include <iostream>
using namespace std;

//fibonacci = f(0)=0; f(1)=1;
//f(n)= f(n-1) + f(n-2);

int fibo(int n){
    //base case
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    
    return fibo(n-1) + fibo(n-2);
}

int main() {
    cout << fibo(5);

    return 0;
}