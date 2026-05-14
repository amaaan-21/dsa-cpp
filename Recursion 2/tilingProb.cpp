#include<iostream>
using namespace std;
//fill with tile
int tilingProblem(int n){
    if(n==0 || n==1){
        return 1;
    }
    //vertical
    int ans1=tilingProblem(n-1);//2 x (n-1)
    //horizontal
    int ans2 = tilingProblem(n-2);//2 x (n-2)
    return ans1+ans2;
}
int main(){
    int n=5;
    cout<<tilingProblem(n)<<endl;
    return 0;
}