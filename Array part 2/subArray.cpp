#include<iostream>
void printSubarrays (int *arr, int n){
    for (int st=0; st<n; st++){
        for(int end= st; end<n;end++){
            // std::cout<<"( "<<st<<" ," <<end<<" )";
            for (int i=st; i<=end; i++){
            std::cout<<arr[i]<<" ";}
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}
int main(){
    int arr[3]={1,2,3};
    int n =3;
    printSubarrays(arr, n);

//o(ncube)time complexity 
//subarray = n*(n+1)/2
    return 0; 
}