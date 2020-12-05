#include<iostream>
#include <stdlib.h>
using namespace std;


int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(){

    int n,m,i,j;
    int a[50][50],b[50][50],c[50][50];
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    cout<<"Enter elements of matrix 1:\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter elements of matrix 2:\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>b[i][j];
        }
        
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            c[i][j]=max(a[i][j],b[i][j]);
        }
    }
    cout<<"The new matrix is:\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<c[i][j];
            cout<<"\t";
        }
        cout<<"\n";
    }

}