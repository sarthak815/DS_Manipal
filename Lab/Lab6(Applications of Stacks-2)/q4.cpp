#include<iostream>
#include <stdlib.h>
#include<cstring>
using namespace std;

class Stack{
    private:
        string s[10];
        string item;
        int top;
    public:
        Stack(){top = -1;}
        void push(string);
        string pop();
        string peek();
};
void Stack::push(string item){
    if(top==9){
        //cout<<"Stack Overflow";
        return;
    }
    else{
        s[++top]=item;
    }

}
string Stack::pop(){
    if(top==-1){
        //cout<<"Empty Stack";
        return "-1";
    }
    else{
        return s[top--];
    }

}
string Stack::peek(){
    if(top==-1){
        //cout<<"Empty Stack";
        return "-1";
    }
    else{
        return s[top];
    }

}

/*void Stack::display(){
    if(top==-1){
        cout<<"Stack Empty";
        
    }
    else{
        for(int i=0;i<=top;i++)
            cout<<s[i]<<" ";

    }

}*/



char* reverse1(char* str){
    for(int i=0;i<strlen(str)/2;i++)
    {
        char temp=str[i];
        str[i]=str[strlen(str)-i-1];
        str[strlen(str)-i-1]=temp;
    }
    return str;
}

int main(){
    char a[50];
    Stack s;
    cout<<"Enter prefix expression: ";
    cin>>a;
    cout<<"The postfix is: "<<reverse1(a);
    return 0;

}