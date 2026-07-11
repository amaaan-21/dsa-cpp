//subset by backtraking
#include<iostream>
#include<vector>
using namespace std;
void printSubSet(vector<vector<int>>& ans){
    
    for(int i = 0; i < ans.size(); i++){
        cout<<"{ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
}

void subSet(const vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans, int i){
    //base case 
    if(i == arr.size() ){
        ans.push_back(curr);
        return;
    }
    //add in fruit in bag
    curr.push_back(arr[i]);
    //move to next aisle
    subSet(arr, curr, ans, i + 1);
    //remove fruit
    curr.pop_back();
    subSet(arr, curr, ans, i +1);
    //note every thing happened in new bag not in same bag
}

int main() {
    vector<int>a = {1,2,3};
    vector<int>c={};
    vector<vector<int>>ans;
    int i = 0;
    subSet(a, c, ans, i);
    printSubSet(ans);

    return 0;
}
