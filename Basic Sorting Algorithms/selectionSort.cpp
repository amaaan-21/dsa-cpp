//28 april 2026 2:10AM
//Selection sort pick lowest number
//O(n^2)
#include<iostream>
void printArr(int *arr, int n){
    for(int i = 0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}
void selectionSort(int *arr, int n){
    int minIndex =0;
    //outer loop
    for(int i = 0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }
    printArr(arr, n);
}

int main(){
    int arr[5]={5,4,1,3,2};
    selectionSort(arr, 5);

    return 0;
}
