#include<iostream>
#include <stdlib.h>
using namespace std;

class Stack{
    private:
        int s[10];
        int item;
        int top;
    public:
        Stack(){top = -1;}
        void push(int);
        int pop();
        void display();
        int peek();
};
void Stack::push(int item){
    if(top==9){
        cout<<"Stack Overflow";
        return;
    }
    else{
        s[++top]=item;
    }

}
int Stack::pop(){
    if(top==-1){
        cout<<"Empty Stack";
        return -1;
    }
    else{
        return s[top--];
    }

}
int Stack::peek(){
    if(top==-1){
        cout<<"Empty Stack";
        return -1;
    }
    else{
        return s[top];
    }

}

void Stack::display(){
    if(top==-1){
        cout<<"Stack Empty";
        
    }
    else{
        for(int i=0;i<=top;i++)
            cout<<s[i]<<" ";

    }

}

int main(){

    Stack stk1;
    string a;
    cout<<"Enter String:";
    getline(cin, a);
    for(int i=0;i<a.length();i++)
        stk1.push(a[i]);
    
    int i;
    for( i=0 ; (i<a.length())&&(stk1.pop()==a[i]) ;++i);

    if(i == a.length())
        cout<<"String is a palindrome.";
    else
        cout<<"String is not a palindrome.";
    
    return 0;
}