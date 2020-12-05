#include<iostream>
#include <stdlib.h>
using namespace std;
int minIndex(int *a, int i, int j) 
{ 
    if (i == j) 
        return i; 
  
    // Find minimum of remaining elements 
    int k = minIndex(a, i + 1, j); 
  
    // Return minimum of current and remaining. 
    return (a[i] < a[k])? i : k; 
} 

void selection_sort(int *a, int n, int i=0){
    
    if(i==n)
        return;

    int k = minIndex(a,i,n-1);

    if(k!=i){
        swap(a[k], a[i]);
    }

    selection_sort(a, n, i+1);
    }

int main(){

    int n,m;
    int a[]={9,1,4,3,5,6,7,2,8};
    selection_sort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
}