//change arr[i]
#include<iostream>
using namespace std;
//print function to print my array
void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<arr[i];
    }
}

//void change array
void changeArr(int arr[], int n, int i){
    //base case hit
    if(i == n){
        printArr(arr, n);
        return;
    }
    //change array before calling recursive call
    arr[i] = i+1;
    changeArr(arr,n,i+1);
    arr[i] -=2 ;//back tracking
    

}

int main(){
    int arr[5]={0};
    int n=5;
    changeArr(arr, n,0);
    cout<<endl;
    printArr(arr,n);

    return 0;
}