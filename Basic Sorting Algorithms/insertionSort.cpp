//insertion sort ..28 april 2026...2:52AM

#include<iostream>
void printArr(int *arr, int n){
    for(int i = 0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}
void insertionSort(int *arr, int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while (prev >=0 && arr[prev]>curr){
            std::swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;
        printArr(arr, n);
    }
    
    
    printArr(arr, n);
}

int main(){
    int arr[5]={5,4,1,3,2};
    insertionSort(arr, 5);

    return 0;
}
