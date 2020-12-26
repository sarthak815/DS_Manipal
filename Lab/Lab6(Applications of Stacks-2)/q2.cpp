#include<iostream>
#include <stdlib.h>
#include<cstring>
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

int Operator(char ch, int a, int b){
    switch(ch){
        case '*': return(a*b);break;
        case '+': return(a+b);break;
        case '-': return(a-b);break;
        case '/': return(a/b);break;
        case '$': return(a^b);break;
        case '^': return(a^b);break;
        default:
        return 0;
    }
}

int evalPostfix(char* pfix){
    Stack s;
    for (int i = 0; pfix[i]; ++i)  
    {  
    
        if (isdigit(pfix[i]))  
            s.push(pfix[i]-'0');
  
        else
        {  
            int val2 = s.pop();  
            int val1 = s.pop();  
            
            switch (pfix[i])  
            {  
            case '+': s.push(val2+val1); break;  
            case '-': s.push(val2-val1); break;  
            case '*': s.push(val2*val1); break;  
            case '/': s.push(val2/val1); break;  
            }  
        }  
    }  
    return s.peek();
}
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
    cin.get(a,50);

    cout<<"The result is: "<<evalPostfix(reverse1(a));
    return 0;

}