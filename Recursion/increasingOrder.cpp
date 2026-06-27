#include <iostream>
using namespace std;
void print (int n ){
    
    if(n==0){//base case
        return;
    }print(n-1);//assumption 
    cout<<(n)<<" ";//work
    
};
int main(){
    print(7);
    return 0;
}