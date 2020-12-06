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
int str_comp(char *a, char *b){
    int m = str_len(a);
    int n =str_len(b);
    if(m==n){
        for(int i=0;i<m;i++){
            if(a[i]!=b[i]){
                return -1;
            }
        }
        return 0;
    }
    return -1;
    
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
    cout<<"The strings are ";
    if(str_comp(str1,str2)==0){
        cout<<"same";
    }
    else{
        cout<<"not same";
    }
    
    return 0;
}