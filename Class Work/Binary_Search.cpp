#include<iostream>
#include<exception>
using namespace std;

int main(){
    int a[100],i,j,n, left, right, middle, n1;
    cout<<"How many numbers: ";
    cin>>n;
    cout<<"Enter the numbers: "<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];

    }
    cout<<"Number to be found: ";
    cin>>n1;
    right = n-1;
    left = 0;
    middle = (left+right)/2;
    while(n1!=a[middle]){
        if(n1<a[middle] && n1>a[left]){
            right = middle;
            middle =(left+right)/2;
        }
        else if(n1>a[middle] && n1<a[right-1]){
            left = middle;
            middle =(left+right)/2;
        }
        else{
            middle = -1;
            break;
        }
    }
    cout<<"\nThe index is ";
    cout<<middle;
}

