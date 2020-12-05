#include<iostream>
#include <stdlib.h>
using namespace std;

//only works for sorted array
int binary_search(int *a, int n,int m){
    int left=0;
    int right = m-1;
    int middle;
    while(right>=left){
        middle=(left+right)/2;
        if(n>a[middle]){
            left=middle+1;
        }
        if(a[middle]==n){
            return middle;
        }
        else if(n<a[middle]){
            right=middle-1;
        }
        else if(left==right){
            return left;
        }
        
    }
    return -1;
    

   
    }

int main(){

    int n,m;
    int a[]={1,2,3,4,5,6,7,8,9};
    cout<<"Enter numbers n: ";
    cin>>n;
    cout<<"The position is: "<<binary_search(a,n,9);
}