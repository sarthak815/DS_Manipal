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

void Stack::display(){
    if(top==-1){
        //cout<<"Stack Empty";
        
    }
    else{
        for(int i=top;i>=0;i--)
            cout<<s[i]<<" ";
        cout<<"\n";

    }

}

class Queue{
    private:
        int item;
        Stack s1,s2;
    public:
        void insert(int);
        int del();
        void display();
        int peek();
    
};
void Queue::insert(int item){
    if(s1.peek()==-1){
        s1.push(item);
    }
    else{
        while(s1.peek()!=-1){
            s2.push(s1.pop());
        }
        s1.push(item);
        while(s2.peek()!=-1){
            s1.push(s2.pop());
        }
    }


}
int Queue::del(){
   
    return s1.pop();

}


void Queue::display(){
    s1.display();
}


int main(){
    Queue q;
    q.insert(100);
    q.insert(200);
    q.insert(300);
    q.display();
    q.del();
    q.display();

}