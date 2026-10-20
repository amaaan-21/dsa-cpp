#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long n , m, diff;


    //while
    cin>>n>>m;
    if(n<0){
        n= -1*n;
    }if(m<0){
        m= -1 * m;
        
    }
    
    if(n>m){
        diff = n-m;
    }else{
        diff = m-n;
        
    }
    
    cout<<diff<<endl;

    
    return 0;
}