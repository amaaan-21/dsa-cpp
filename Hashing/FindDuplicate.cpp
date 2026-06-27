/*LeetCode #217 – Contains Duplicate

Problem
Given an integer array nums, 
return true if any number appears more than once,
otherwise return false.*/
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

bool findDup(vector <int>&num){
    unordered_set <int> st;
    for (int x: num){
        if (st.count(x)){
            
            return true;
        }
        st.insert(x);
    }
    return false;
}

int main(){
  vector<int> num={4,7,2,7};
   bool ans = findDup(num);
   if (ans){
    cout<<"duplicate found\n";
  }else {
    cout<<"no duplicate \n";
  }



    return 0;
}