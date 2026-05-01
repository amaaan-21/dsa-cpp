#include <iostream>
using namespace std;
void toUpper(char *word, int n){
    
    for(int i =0; i<n; i++){
        char ch = word[i];
        if(ch>='A'&&ch<='Z'){
            continue;
        }else {//if lower convert to upper
            word[i]= ch - 'a'+'A';
        }
    }
    cout<<word<<endl;
}
int main(){
    //convert into upper case
    char word[]={'A','p','P','l','e'};
    char word2[]={"hehdhjfkhsfhsdf\n"};
    int n = sizeof(word)/sizeof(char);
    toUpper(word,n);//1st
    toUpper(word2, strlen(word2)); //if we use strlen then we don't calculate which actually length of char array

    return 0;
}