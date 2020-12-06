#include<iostream>
#include <stdlib.h>
using namespace std;

int str_len(char *a){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
    }
char* str_insert(char *a, char *b, int k){
    int m = str_len(a);
    int n =str_len(b);
    for(int i=1;i<(m-k);i++){
        a[m+n-i]=a[m-i];
    }
    a[m+n]='\0';
    for(int j=0;j<n;j++){
        a[n+j]=b[j];
    }

    return a;
}

int main(){

    char str1[100],str2[100];
    int n;
    cout<<"Enter the string: ";
    cin>>str1;
    cout<<"Enter the substring: ";
    cin>>str2;
    cout<<"Enter position: ";
    cin>>n;
    cout<<"The new string is: "<<str_insert(str1,str2,n);
    
    return 0;
}