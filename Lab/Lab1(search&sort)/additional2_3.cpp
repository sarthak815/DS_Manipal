#include<iostream>
#include <stdlib.h>
using namespace std;

//only works for sorted array
int multiply(int a, int b){
    if(a==0||b==0)
        return 0;
    else if(b>1)
        return a+multiply(a,b-1);
    else if(b<0){
        return -a+multiply(a,b+1);
    }
    else
    {
        return a;
    }
    
    }

int main(){

    int m,n;
    cout<<"Enter numbers to be multiplied: ";
    cin>>m>>n;
    cout<<"The product is: "<<multiply(m,n);
}