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
int main(){

    char str[100];
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"The length is: "<<str_len(str);
    return 0;
}