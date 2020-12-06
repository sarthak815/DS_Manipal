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

int str_find(char *a, char *b){
    bool flag;
    int al=str_len(a);
    int bl=str_len(b);
    int loc;
    for (int i=0; i<=al-bl;i++){
        for (int j=i;j<i+bl;j++){
            flag=true;
            if(a[j]!=b[j-i]){
                flag=false;
                break;

            }
        }
        if(flag==true){
        
            return i;
        
        }
    }
    return -1;
}

char* str_del(char *a, char *b){
    int m = str_len(a);
    int n =str_len(b);
    int loc=str_find(a, b);
   
    if(loc>=0){
        for(int i=loc;i<loc+n;i++){
            a[i]=a[i+n];
        }
        a[m-n]='\0';
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
    cout<<"The new string is: "<<str_del(str1,str2);
    
    return 0;
}