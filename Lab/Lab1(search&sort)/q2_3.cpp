#include<iostream>
#include <stdlib.h>
using namespace std;


void insertion_sort(int *a, int n){
    
    for(int i=1;i<n;i++){
        int j=i-1;
        int key = a[i];
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }

    
    }

int main(){

    int n,m;
    int a[]={9,1,4,3,5,6,7,2,8};
    insertion_sort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
}