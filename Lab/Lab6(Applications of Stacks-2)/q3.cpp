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



string evalPostfix(string pfix){
    
    
    Stack s;
    for (int i = 0; pfix[i]; ++i)  
    {  
        if(isdigit(pfix[i])||isalpha(pfix[i])){
            s.push(string(1,pfix[i]));
        }
        else{
            string a=s.pop();
            string b=s.pop();
            string exp='('+b+pfix[i]+a+')';
            s.push(exp);

        }
    }  
    return s.peek();
}
int main(){
    char a[50];
    Stack s;
    cout<<"Enter postfix expression: ";
    cin>>a;
    cout<<"The infix is: "<<evalPostfix(a);
    return 0;

}