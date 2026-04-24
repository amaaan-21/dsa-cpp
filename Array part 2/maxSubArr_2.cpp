//maximum subarray sum "OPTIMIZE"; 
//TIME COMPLEXITY = O(N^2) because i remove one loop so less number of code run but same result;
#include<iostream>
void maxSumSubArr(int *arr, int n){
    int maxSum=INT_MIN;
    for(int start = 0; start<n; start++){ //start = 2 (index);
          int currSum=0;
        for(int end=start; end<n; end++){ //end = 2, 3, 4, 5 (index) not actual values;
            currSum+=arr[end];
                
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