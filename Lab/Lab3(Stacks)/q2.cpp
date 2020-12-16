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
        for(int i=top;i>=0;i--)
             if(s[i]<10)
                cout<<s[i];
            else
            {
                char c=s[i]+55;
                cout<<c;
            }

    }

}

int main(){

    Stack s;
    int m,n,i,j;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Enter base to be converted to: ";
    cin>>m;
    while(n!=0){
        s.push(n%m);
        n=n/m;
    }
    s.display();
    return 0;
}