/*
90. Subsets II
Medium
Topics
premium lock icon
Companies
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include<iostream>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int>& current, vector<vector<int>>& ans, int i){
        
        //base case
        if(i == nums.size()){
            /*stored*/ans.push_back(current);
            
            return;
        }
        //add elements in current at current index == current value
        current.push_back(nums[i]);
        //call function but aat next index not same
        helper(nums, current, ans, i+1);
        //remove
        current.pop_back();
        //befor moving to next index we check for same current value is not same to next all value thats why we did sorting; at first in subsetwithDup;
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        helper(nums, current, ans, i+1);
    }
    void printF(vector<vector<int>>& ans){
        for(int i =0; i<ans.size(); i++){
            for (int j=0; j<ans[i].size(); j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }





    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>current;
        vector<vector<int>>ans;
        helper(nums, current, ans, 0);
        printF(ans);
        return ans;
    }
};

int main(){
    Solution obj1;
    
    vector<int>a={1,2,2};
    vector<vector<int>>ans;
    obj1.subsetsWithDup(a);
    
        return 0;
    }