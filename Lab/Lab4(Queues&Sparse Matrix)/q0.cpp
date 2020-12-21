//queues - fifo
#include<iostream>
#include <stdlib.h>
using namespace std;

class Queue{
    private:
        int q[10];
        int item;
        int front,rear;
    public:
        Queue(){front =0; rear=-1;}
        void insert(int);
        int del();
        void display();
        int peek();
    
};
void Queue::insert(int item){
    if(front==0&&rear==9){
        cout<<"Queue is full";
    }
    else{
        rear++;
        q[rear]=item;
        
    }


}
int Queue::del(){
    if(front>rear)
        return -1;
    return q[front++];

}


void Queue::display(){
    if(rear==front-1){
        cout<<"Queue is empty";
        return;
    }
    
    for(int i=front;i<=rear;i++){
        cout<<q[i]<<" ";
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
    
}