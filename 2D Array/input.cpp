#include<iostream>
int main(){
    int arr[3][4];
    int n=3, m=4;
    
    for(int i=0; i<n; i++){
        for (int j=0; j<m;j++){
            std::cin>>arr[i][j];

        }
    }
     for(int i=0; i<n; i++){
        for (int j=0; j<m;j++){
            std::cout<<arr[i][j]<<"  ";
 
        }
        std::cout<<"\n";
    }



    return 0;
}