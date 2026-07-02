//subset sum

/*Take
↓
sum = sum + arr[index]
↓
Recursive Call
↓
Current.pop_back()
↓
sum = sum - arr[index]
↓
Skip Recursive Call
*/

#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(vector<int>& arr, vector<int>& Current, int index, int sum, int target){
    //base case 1 we found answer
    if(sum == target){
        for(int i = 0; i < Current.size(); i++)

{

    cout << Current[i] << " ";

}

cout << endl;

return true;
    }
    //base case 2 we explore all possible but still don't found asn
    if(index == arr.size()){
        return false;
    }
    Current.push_back(arr[index]);
        /*better see summ this method but in function no change*/
    sum = sum + arr[index];
   
   bool take = subsetSum(arr, Current, index+1, sum, target);
//remove
    Current.pop_back();
    sum = sum - arr[index]; 
//again recurcive call
     bool skip = subsetSum(arr, Current, index+1, sum, target);
//we are done;
 return take || skip;
    }

    int main(){
        vector<int>arr={1,2,3};
        vector<int>Current={};
        int t = 5;
        cout<< subsetSum(arr, Current, 0, 0, t);


        return 0;
        }
