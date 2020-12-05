#include<iostream>
#include <stdlib.h>
using namespace std;

//only works for sorted array
int binary_search(int *a,int n, int l, int r){
    int left=l;
    int right= r;
    int middle;
    if(right>=left){
        middle=(left+right)/2;
        if(n>a[middle]){
            return binary_search(a, n, middle+1, r);
        }
        if(a[middle]==n){
            return middle;
        }
        else if(n<a[middle]){
            right=middle-1;
            return binary_search(a, n, l, middle-1);
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
    cout<<"The position is: "<<binary_search(a,n,0,8);
}