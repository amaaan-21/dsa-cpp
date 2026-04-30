//pointer in matrix 30 april 2026 
/*i = row
j = columns*/
#include<iostream>
using namespace std;

void func(int mat[][4], int n, int m){
    //address of pointer
    cout << " 0th row "<< mat <<endl;
    cout << "1st row "<< mat+1 <<endl;
    cout << "2nd row "<< mat+2 <<endl;
    cout << "3rd row "<< mat+3 <<endl;

    //value or elements in row(derefrence)
    cout << " 0th row "<< *mat <<endl;
    cout << "1st row "<< *(mat+1) <<endl;
    cout << "2nd row "<< *(mat+2) <<endl;
    cout << "3rd row "<< *(mat+3 )<<endl;
    //ptr[i][j]=*(*(ptr + i)+ j) same
    cout<<*(*(mat +2)+1)<<endl;

}

int main(){
int arr[][4]={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14, 15, 16}
};
func(arr,4,4);


    return 0;
}