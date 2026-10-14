//problem : check the array is palindram or not 
//what is palindrome??
//palindrome is (rar) and start from back this time we still get (rar)
// is "(cat)" is palnidrome?? "(tac)" no right 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(vector<int> &a, int left , int right){
    //base case 
    if(left>=right){
        return true;
    }

    if(a[left] == a[right]){
        return isPalindrome (a, left + 1, right - 1);
    } else{
        return false;
    }
    return true;
}
int main(){
    vector<int>a={1,2,3,2,1};
cout<<isPalindrome(a,0,a.size()-1)<<endl;

    return 0;
}



