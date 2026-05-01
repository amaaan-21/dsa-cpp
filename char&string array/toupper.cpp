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
void toLower(char *word, int n){
    
    for(int i =0; i<n; i++){
        char ch = word[i];
        if(ch>='a'&&ch<='z'){
            continue;
        }else {//if Upper convert to Lower
            word[i]= ch - 'A'+'a';
        }
    }
    cout<<word<<endl;
}
int main(){
    //convert into upper case
    char word[]={'A','p','P','l','e'};
    char word2[]={"hehdhjfkhsfhsdf\n"};
    char word3[]={'H','I', 'T','H','I','S','I','S', 'M','Y', 'C','A','r','\n'};
    int n = sizeof(word)/sizeof(char);
    toUpper(word,n);//1st
    toUpper(word2, strlen(word2)); //if we use strlen then we don't calculate which actually length of char array
    toLower(word3, strlen(word3));//convert lower to upper
    
    return 0;
}