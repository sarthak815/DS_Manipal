#include<iostream>
#include <stdlib.h>
using namespace std;
char open[]={'{','[','('};
char close[]={'}',']',')'};
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

    Stack s;
    string a;
    int i;
    cout<<"Enter String:";
    getline(cin, a);
    for(i=0;a[i]!='\0';i++){
        for(int j=0;j<3;j++){
            if(a[i]==open[j]){
                s.push(a[i]);
            }
            else if(a[i]==close[j]&&s.peek()==open[j]){
                s.pop();
            }
        }
    }
    if(s.peek()==-1){
        cout<<"The paranthesis are balanced";
    }
    else{
        cout<<"The paranthesis are not balanced";
    }
}