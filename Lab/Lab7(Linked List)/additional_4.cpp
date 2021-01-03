#include<iostream>
#include <stdlib.h>
using namespace std;
class list{
public:
    int val;
    list* next;
};
class Stack{
    private:
        int s[10];
        int item;
        list *top;
    public:
        Stack(){top = NULL;}
        void push(int);
        int pop();
        void display();
        int peek();
};
void Stack::push(int item){
    list *temp=new list;
    temp->val=item;
    temp->next=top;
    top=temp;

}
int Stack::pop(){
    if(top==NULL){
        cout<<"Empty Stack";
        return -1;
    }
    else{
        list *temp=top;
        int n;
        n=top->val;
        top = top->next;
        return n;
    }

}
int Stack::peek(){
    if(top==NULL){
        cout<<"Empty Stack";
        return -1;
    }
    else{
        return top->val;
    }

}

void Stack::display(){
    list *temp;
    if(top==NULL){
        cout<<"Stack Empty";
        
    }
    else{
        temp = top;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<"\n";

    }

}
class Queue{
    private:
        list *front;
        list *rear;
        int item;
    public:
        Queue(){front=rear=NULL;}
        void insert(int);
        int del();
        void display();
        int peek();
    
};
void Queue::insert(int item){
    list *temp=new list;
    temp->val=item;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;



}
int Queue::del(){
    if(front==NULL){
        cout<<"Queue is empty";
    }
    list *temp=front;
    int n = temp->val;
    front = temp->next;
    if(front==NULL)
        rear=NULL;
    return n;

}


void Queue::display(){
    if(rear==NULL && front==NULL){
        cout<<"Queue is empty";
        return;
    }
    list *temp=front;

    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
int main(){
    int i,j,k;
    Queue q;
    q.insert(2);
    q.insert(4);
    q.insert(7);
    q.del();
    q.display();
    cout<<"\n";
    Stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.display();
    
}