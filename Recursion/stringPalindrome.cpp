//String Palindrome using Recursion

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool stringPalindrome(string & charac, int left, int right){
    //base case
    if (left>=right){
        return true;
    }
    if(charac[left]==charac[right]){
        return stringPalindrome(charac, left+1, right-1);

    }
    else{
        return false;
    }
}
int main(){
    string charac = ("masdam");
    cout<<stringPalindrome(charac, 0, charac.size()-1);
    return 0;
}
