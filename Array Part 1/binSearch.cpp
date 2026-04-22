//binary search only work sorted array like dictionary
#include<iostream>

int binSearch(int *arr, int n, int key){
    int st =0, end =n-1;
    //binary search 
    while(st<=end){
        int mid = (st + end)/2;
        if(arr[mid]==key){
            return mid;//key found
        }
        //second half
            else if(arr[mid]<key){
                st = mid + 1;
        }
        //1st half
            else {
                end = mid -1;
            }
           
    }

 return -1;
}



int main (){
    int arr[] ={2, 4, 6, 8, 10, 12, 14, 16 };
    int n = sizeof(arr)/ sizeof(int);

    std::cout<<binSearch(arr, n, 12)<<"\n"; 
    return 0;
}