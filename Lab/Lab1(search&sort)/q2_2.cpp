#include<iostream>
#include <stdlib.h>
using namespace std;


void selection_sort(int *a, int n){
    
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n;j++){
            int min=i;
            if(a[min]>a[j]){
                min=j;
            
            }
            swap(a[min],a[i]);
        }
    }

    
    }

int main(){

    int n,m;
    int a[]={9,1,4,3,5,6,7,2,8};
    selection_sort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
}