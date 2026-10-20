#include<iostream>
using namespace std;
int main (){
    int Start = 2;
    int n=6
    
    ;
    
    for(int i = 0; i<n; i++){
        Start = Start + (Start-1);
    }
        
    cout<<Start*Start<<endl;
    
    
    return 0;
}