#include<iostream>
#include <stdlib.h>
using namespace std;
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

    int n,m,i,j,k=0;
    int a[50][50],b[50][50],c[50][50],e[1000];
    cout<<"Enter number of rows: ";
    cin>>n;
    cout<<"Enter number of columns: ";
    cin>>m;
    cout<<"Enter elements of matrix :\n";
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];

        }
    }
    if(n==m){
        int sum=0;

        int sum1 = 0, sum2=0;
        //finding the sum of first diagonal
        for (int i = 0; i < n; i++) 
            sum1 = sum1 + a[i][i];
        //finding the sum of seciond diagonal
        for (int i = 0; i < n; i++) 
            sum2 = sum2 + a[i][n - 1 - i]; 
        
        //Checking, whether the sum of two diagonal is same or not
        if(sum1 != sum2) { 
            cout<<"Not a Magic Square";
        
        }
        else{
            for(i=0;i<n;i++){
                sum=sum+a[i][0];
            }
        
            for(i=0;i<n;i++){
                int sum_row=0;
                int sum_column=0;
                
                for(int j=0;j<n;j++){
                    sum_row=sum_row+a[i][j];
                    sum_column=sum_column+a[j][i];
                }
                if(sum_row!=sum_column){
                    cout<<sum_row<<" "<<sum_column<<"\n";
                    cout<<"Not a Magic Square";
                    
                }
            }
            cout<<"Its a magic square";
        }
    
    }
    else{
        cout<<"Not a Magic Square";
    }

}