//28 april 2026 1:40 AM
//Amaan
//buble sort algo 
#include <iostream>
//for print output
void printArr(int *arr, int n){
    for(int i = 0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

void bubbleSort(int *arr, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i-1; j++)
        if(arr[j]>arr[j+1]){
            std::swap(arr[j],arr[j+1]);
        }
        
    }
     printArr(arr, n);

}

int main(){
    int arr[5]={5,4,2,3,1};
    bubbleSort(arr, 5);

    return 0;
}