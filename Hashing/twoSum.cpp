/*LeetCode #1 – Two Sum.
Problem
Given an array of integers nums and
an integer target, return the indices
of the two numbers whose sum equals target.
Example
nums = [2,7,11,15]
target = 9

Output:

[0,1]*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>&num, int target){
    unordered_map<int, int> mp;
    for(int i=0; i<num.size(); i++){
        int need=(target-num[i]);
        //check first
        if(mp.count(need)){
            return {mp[need],i};
        }
        //store currNum and its index
        mp[num[i]]= i;

    }
    return {};
}

int main(){
    vector<int> num ={2,4,2,6};
    int target = 8;
    vector<int> ans = twoSum(num, target);
    cout<<ans[0]<<" "<< ans[1]<<endl;
    return 0;
}