//reverse array without extra space by using swapping method

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
    //intialize start and end
    int start = 0;
    int end = n - 1;
    while(start < end){
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
    //increase start
        start++;
    //decrease end
        end--;
    }
printArr(arr, n);


return 0;
}