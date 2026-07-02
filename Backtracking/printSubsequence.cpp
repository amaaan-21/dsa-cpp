//print the subsequence
//backtraking only no loop

#include<iostream>
#include<vector>
using namespace std;
// i am usind void instead of an return type because i want to print subsequance
void printSubsequence( vector<int>& arr, vector<int>& CurrentSubsequence, int index){
    //base case hit when all element finshed then nothing to do
    if(index == arr.size()){
        //print subsequence
        for(int i=0; i<CurrentSubsequence.size(); i++){
            cout<<CurrentSubsequence[i]<<" ";
        }
        cout<<endl;   
    }
    return;
    ////add element from origin arr to CurrentSubsequence like add fruits from (shelf=arr never change) to basket
    CurrentSubsequence.push_back(arr[index]);
    //now one work at one time so we move to next work so called recursive
    //note why index+1 becuase rest remain same becuase its finshed we have to move next
    printSubsequence(arr, CurrentSubsequence, index+1);
    //now this time we decide to not take fruits from shelf to our basket
    CurrentSubsequence.pop_back();
    //-----------------------------------------------------------------------
    //why i am using pop_back to skip fruit
    //not any other method 
    // because lets, assume currently my CurrentSubsequence is {1,2,3} 
    // and I want to remove 3 from my basket so it last element and pop_back is LIFO
    //last in first out so its remove without incresing runtime to set up new loop to remove 
    //-----------------------------------------------------------------------
    //now I said in first one work at one time
    //and CurrentSubsequence = {1,2} and this time i don't want to put 2 in my basket
    //so i called recusive but move to next elemet like we called recursive earlier same

    //recursive call again 
    printSubsequence(arr, CurrentSubsequence, index+1);

    // now we are done
}

int main(){
    vector<int>originalArr = {1,2,3};
    vector<int>Current = {};//empty
    //now i am going to call my function
    printSubsequence(originalArr,Current,0);
    


        return 0;
    }


   // Note: It took me 4 hours to truly understand backtracking, but it was worth every minute.
