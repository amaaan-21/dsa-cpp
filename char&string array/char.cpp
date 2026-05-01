#include<iostream>
using namespace std;
//strln use to print length of the array

int main(){
    char work[50] ={'h','e','l','l','o'};
    char w[]={"hello"};
    cout<<w<<endl;
    cout<<strlen(work)<<endl;
    cout<<work<<endl;

    char input[50];
    cin>>input;//ignore whitespaces
    cout<<"your word is : "<<input<<endl;
    cout<<"you length of char is : "<<strlen(input)<<endl;
    char sentenceInput[60];
    cin.getline(sentenceInput, 50, '*');//to print space also--the '*' is delimitter if i type * after that nothing is count
    cout<<"your add for sentence is : "<<sentenceInput<<endl;
    cout<<"your length of sentences is : "<<strlen(sentenceInput)<<endl;

    return 0;
}