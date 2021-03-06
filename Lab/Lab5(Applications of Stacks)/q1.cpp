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
        //cout<<"Stack Overflow";
        return;
    }
    else{
        s[++top]=item;
    }

}
int Stack::pop(){
    if(top==-1){
        //cout<<"Empty Stack";
        return -1;
    }
    else{
        return s[top--];
    }

}
int Stack::peek(){
    if(top==-1){
        //cout<<"Empty Stack";
        return -1;
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
int getPriority(char c){
    switch (c){
        case '-':
        case '+':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '$':
        case '^':
            return 3;
            break;
        
        default:
            return 0;
    }
}
char* infixtoPostfix(char* infix){
    Stack s;
    char* pfix;
    char c,d;
    pfix = new char[100];
    int k=0;
    for(int i=0;infix[i]!='\0';i++){
        int n;
        c = infix[i];
        if(c=='('){
            s.push(c);
        }
        
        else if(c==')'){
            while(s.peek()!='('){
                d=s.pop();
                pfix[k]=d;
                k++;
            }
            s.pop();
        }
        else{
            n=getPriority(c);
            if(n==0){
                pfix[k]=c;
                k++;
            }
            else if(s.peek()==-1){
                s.push(c);
            }
            else if(n>getPriority(s.peek())&&s.peek()!=-1){
                s.push(c);
            }
            else{
                while(n<=getPriority(s.peek())){
                    pfix[k]=s.pop();
                    k++;
                    
                }
                s.push(c);
            }
        }
        
    }
    while(s.peek()!=-1){
        pfix[k]=s.pop();
        k++;
    }
    return pfix;
}
int main(){
    char a[50];
    Stack s;
    cout<<"Enter infix expression: ";
    cin.get(a,50);
    cout<<"The postfix is: "<<infixtoPostfix(a);
    return 0;

}