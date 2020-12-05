#include<iostream>
#include <stdlib.h>
using namespace std;


int main(){

    int n1,m1,i,j,n2,m2;
    int a[50][50],b[50][50],c[50][50];
    cout<<"Enter number of rows: ";
    cin>>n1;
    cout<<"Enter number of columns: ";
    cin>>m1;
    cout<<"Enter elements of matrix 1:\n";
    for(i=0;i<n1;i++){
        for(j=0;j<m1;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter number of rows: ";
    cin>>n2;
    cout<<"Enter number of columns: ";
    cin>>m2;
    cout<<"Enter elements of matrix 2:\n";
    for(i=0;i<n2;i++){
        for(j=0;j<m2;j++){
            cin>>b[i][j];
        }
        
    }
    
    if(m1==m2&&n1==n2){

            for(i=0;i<n1;i++){
                for(j=0;j<m1;j++){
                    c[i][j]=a[i][j]+b[i][j];
                    
                }
            }
            cout<<"The new matrix is:\n";
            for(i=0;i<m1;i++){
                for(j=0;j<n2;j++){
                    cout<<c[i][j];
                    cout<<"\t";
                }
                cout<<"\n";
            }

    }

}