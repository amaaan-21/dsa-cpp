//reverse array by coping array

#include <iostream>
void printArr(int *arr, int n){
    for(int i =0; i<n; i++){
        std::cout<<arr[i]<<", ";
    }
    std::cout<<"\n";
}

   
int main(){
    int arr[]={2, 4, 6, 8, 10, 12, 14, 16 };
    int n = sizeof(arr)/ sizeof(int);
    int copyArr[n];
    for(int i=0; i<n; i++){
        int j=n-i-1;
        copyArr[i] = arr[j];

    }
        for(int i=0; i<n; i++){
            arr[i]= copyArr[i];
        }
printArr(arr, n);


return 0;
}