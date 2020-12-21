//queues - fifo
#include<iostream>
#include <stdlib.h>
using namespace std;
#define max 10
class Sparse_matrix{
    public: 
        int col;
        int row;
        int num;
        void set(int r, int c, int v){
        row=r;col=c;num=v;
        }
        void transpose(Sparse_matrix a[],Sparse_matrix b[]){
            int num_col,num_row,count,k=1;
            num_col=a[0].col;
            num_row=a[0].row;
            count=a[0].num;
            b[0].set(num_col,num_row,count);
            for(int i=0;i<=a[0].col;i++){
                for(int j=1;j<=count;j++){
                    if(a[j].col==i){
                        b[k].set(a[j].col,a[j].row,a[j].num);
                        k++;
                    }

                }
            }
            b[k].set('\0','\0','\0');
        
        }
} ;
int main(){
    int n,m,item,k=1;
    
    cout<<"enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
    cin>>n;
    cout<<"Enter the elements:\n";
    int arr[m][n];
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                count++;
        }
    }

    Sparse_matrix spm[count+1], tpose[count+1], temp;
    spm[0].set(m,n,count);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(arr[i][j]!=0){
                spm[k].row=i;
                spm[k].col=j;
                spm[k].num=arr[i][j];
                k++;
            }
        }
    }
    spm[k].set('\0','\0','\0');
    cout<<"The sparse matrix is:\n";
    cout<<"Rows  "<<"Column  "<<"Value\n";
    for(int i=0;i<count+1;i++){
        cout<<spm[i].row<<"  "<<spm[i].col<<"  "<<spm[i].num<<"\n";
    }
    cout<<"The transpose is:\n";
    temp.transpose(spm,tpose);
    for(int i=0;i<count+1;i++){
        cout<<tpose[i].row<<"  "<<tpose[i].col<<"  "<<tpose[i].num<<"\n";
    }
}