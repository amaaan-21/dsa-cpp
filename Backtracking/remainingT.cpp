/*
===========================================
Problem: Combination Sum (Backtracking)
===========================================

Given a vector of DISTINCT positive integers 'arr'
and an integer 'target',

Return ALL UNIQUE combinations where the chosen
numbers sum to 'target'.

Rules:
1. The same number can be chosen MULTIPLE times.
2. All numbers are positive.
3. Return every possible combination.

-------------------------------------------
Example 1

Input:
arr = {2,3,6,7}
target = 7

Output:
[
    [2,2,3],
    [7]
]

Explanation:
2 + 2 + 3 = 7
7 = 7

-------------------------------------------
Example 2

Input:
arr = {2,3,5}
target = 8

Output:
[
    [2,2,2,2],
    [2,3,3],
    [3,5]
]

===========================================
Your Tasks
===========================================

1. Create the recursive helper function.

2. Think about:
   - Base Case(s)
   - Recursive Call(s)
   - Backtracking

3. Do NOT use loops initially until we discuss them.

===========================================
Function
===========================================

void printCombination(
    vector<int>& arr,
    vector<int>& current,
    int index,
    vector<vector<int>>& ans,
    int remTarget
)
{

}
*/
#include <iostream>
#include<vector>
using namespace std;
void printAns(vector<vector<int>> & ans){
    for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }

void printCombination(vector<int>& arr, vector<int>& current,int index, 
vector<vector<int>>& ans, int remainingT){
   
    //base case 1 its mean we found asnswer
    if(remainingT == 0){
        ans.push_back(current);

        return;}
    //base case 2 no possible asn exit from here
    if(remainingT < 0){
        return;}
     //base case 3;
    if(index == arr.size()){
        return;
    }
    //add number in curretnt
    current.push_back(arr[index]);

    //firt recursive call at the same index to check remaining target pnly
    printCombination(arr, current, index, ans, remainingT-arr[index]);
    //we ar done we need to go back
    current.pop_back();
    //now again call recursive for next index
    printCombination(arr, current, index+1, ans, remainingT);
}
int main(){
    vector<int>arr={2,3,4,7};
    vector<int>curr={};
    vector<vector<int>>ans={};
    int i = 0;
    int remainingT;
    printCombination(arr, curr,i,ans,7);
    printAns(ans);
    return 0;
}