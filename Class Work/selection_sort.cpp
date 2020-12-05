#include<iostream>
#include<exception>
using namespace std;

int main(){
    int a[100],i,j,n;
    cout<<"How many numbers: ";
    cin>>n;
    cout<<"Enter the numbers: "<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];

    }
    for(i=0;i<n;i++){
            j=0;
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<a[i];
    }
}

