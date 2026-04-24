//Amanullah Siddiue : 23 april 2025, 10:47 pm
//maximum subarray sum "Kadan's algorithm "; 
//TIME COMPLEXITY = O(N) 
#include<iostream>
void maxSumSubArr(int *arr, int n){
    int maxSum=INT_MIN;
    for(int i = 0; i<n; i++){ //start = 2 (index);
            int currSum;
            currSum +=arr[i];
            // std::cout<<"currSum : "<<currSum<<"  ";
               maxSum = std::max(maxSum, currSum);
               if(currSum<0){
                currSum=0;
               }
        }
        std::cout<<"\n";
    
    std::cout<<"the max sum of SubArray : "<<maxSum<<"\n";
}

int main(){
    int arr[]={2, -3, 6, -5, 4, 2};
    int n= sizeof(arr)/sizeof(int);
        maxSumSubArr(arr, n);


              return 0;
}