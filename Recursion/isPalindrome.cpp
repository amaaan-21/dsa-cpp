/*
Problem : Check if an Array is a Palindrome

What is a palindrome?

An array is a palindrome if it reads the same forward and backward.

Example 1:{1, 2, 3, 2, 1}
true
Example 2: {1, 2, 3, 4}
false
*/
#include<iostream>
#include<vector>
using namespace std;
bool isPalindrome(vector<int>& arr, int left, int right){
    
    
    // base case 
    if(left>=right){
        return true;}
    //work
    if(arr[left]==arr[right]){
        return isPlindrome(arr, left+1, right-1);}
     else {
        return false;}
return true;
}

int main(){
    vector<int> tpp={1,2,3,2,1};
    cout<<isPalindrome(tpp, 0,tpp.size()-1);

    return 0;
}