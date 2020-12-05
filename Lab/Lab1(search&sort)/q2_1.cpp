#include<iostream>
#include <stdlib.h>
using namespace std;


void bubble_sort(int *a, int n){
    
    for(int i=0;i<n;i++){
        for(int j=0; j<n-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }

    
    }

int main(){

    int n,m;
    int a[]={2,1,4,3,5,6,7,9,8};
    bubble_sort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
}