/*Write a recursive function that returns the sum of the 
first N natural numbers.

You are not allowed to use loops (for, while, do-while).
Example 1
Input
Plain text
n = 5
Output
Plain text
15
Explanation
Plain text
1 + 2 + 3 + 4 + 5 = 15*/

#include <iostream>
using namespace std;

int sum(int n){
    //base case
    if(n==0){
        return 0;
    }
    //work
    return n +sum(n-1);
}
int main(){
  cout<<  sum(5);
    return 0;
}
