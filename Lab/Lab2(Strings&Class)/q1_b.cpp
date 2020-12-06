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
char* str_concat(char *a, char *b, int m, int n){
    for(int j=0;j<n;j++){
        a[m]=b[j];
        m++;
    }
    a[m]='\0';
    return a;
    
}

int main(){

    char str1[100],str2[100];
    int m,n;
    cout<<"Enter the string1: ";
    cin>>str1;
    cout<<"Enter the string2: ";
    cin>>str2;
    m=str_len(str1);
    n=str_len(str2);
    cout<<"The concatenated strings are: "<<str_concat(str1,str2,m,n);
    
    return 0;
}