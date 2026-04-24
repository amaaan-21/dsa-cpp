//maximum subarray sum BRUTE FORCE
#include<iostream>
void maxSumSubArr(int *arr, int n){
    int maxSum=INT_MIN;
    for(int start = 0; start<n; start++){
        for(int end=start; end<n; end++){
            int currSum=0;
                for(int i=start; i<=end; i++){
                    currSum +=arr[i];
                    
                }
                std::cout<<currSum<<" , "; 
            //    if (currSum>maxSum){
            //     maxSum=currSum;
            //    }
               //better metthod than if else 
               maxSum = std::max(maxSum, currSum);
        }
        std::cout<<"\n";
    }
    std::cout<<"the max sum of SubArray : "<<maxSum<<"\n";
}

int main(){
    int arr[]={2, -3, 6, -5, 4, 2};
    int n= sizeof(arr)/sizeof(int);
        maxSumSubArr(arr, n);


              return 0;
}