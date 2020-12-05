#include<iostream>
#include <stdlib.h>
using namespace std;


int linear_search(int *a, int n,int m){
        for(int i=0;i<m;i++){
            if(a[i]==n){
                return i;
            }

        }
        return -1;
   
    }

int main(){

    int n,m;
    int a[]={1,2,3,4,5,6,7,8,9,0,12};
    cout<<"Enter numbers n: ";
    cin>>n;
    cout<<"The position is: "<<linear_search(a,n,11);
}