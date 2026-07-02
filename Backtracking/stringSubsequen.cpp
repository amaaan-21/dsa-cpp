//print subsequence in string
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//basecase-->print-->take(push_back)-->recursivecall-->remove(pop_back)-->recursive-->parent
void stringSubsequence(string &st,string &CurrentSubsequence, int index){
    //base case --> print
    //whe base case hit when index == string size beacuse after that no elements left
    if(index == st.size()){
    for(int i = 0; i < CurrentSubsequence.size(); i++){
        //print Current only why because st (string remain same no change_)
        cout<<CurrentSubsequence[i];
        
    }
    
   cout<<endl;
        return;
} 
    
    //take in Current from st
    CurrentSubsequence.push_back(st[index]);
    //recursive 
    stringSubsequence(st, CurrentSubsequence, index+1);
    //remove
    CurrentSubsequence.pop_back();
    //again back tracking
    stringSubsequence(st, CurrentSubsequence, index+1);
    //this time I decide not to take
}
int main(){
    string st="abc";
    string Curr="";//emppty
    //call
    stringSubsequence(st, Curr, 0);
    cout<<"end program";

    return 0;
}
