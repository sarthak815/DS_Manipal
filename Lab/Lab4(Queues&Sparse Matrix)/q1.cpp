//queues - fifo
#include<iostream>
#include <stdlib.h>
#define size 4
using namespace std;

class cQueue{
    private:
        int q[size];
        int item;
        int front,rear;
    public:
        cQueue(){front =-1; rear=-1;}
        void insert(int);
        int del();
        void display();
        int peek();
        bool isEmpty(){
        return (front==-1 && rear==-1);
        }

        bool isFull(){
            return((front==0&&rear==size-1)||(rear==front-1));
        }
};
void cQueue::insert(int item){
    if(!isFull()){
        if(front==-1){
            front=0;
            rear=0;
            q[rear]=item;
        }
        else if(rear==size-1&&front!=0){
        rear=0;
        q[rear]=item;
        }
        else{
            rear++;
            q[rear]=item;
        }
    }
    else{
        cout<<"QUeue is full";
    }

}
int cQueue::del(){
    int k;
    if(!isEmpty()){
        if(front==rear){
            k=q[front];
            front = -1;
            rear = -1;
            return k;
        }
        else if(front==size-1){
            k=q[front];
            front=0;
            return k;

        }
        else{
            return q[front++];
        }

    }
    else{
        cout<<"Queue is empty";
        return -1;
    }

}


void cQueue::display(){
    if(isEmpty()){
        cout<<"The queue is empty";

    }
    else if(front<=rear){
        for(int i=front;i<=rear;i++){
            cout<<q[i]<<" ";
        }

    }
    else{
        
        
        for(int i=front;i<size;i++){
            cout<<q[i]<<" ";

        }
        for(int i=0;i<=rear;i++){
            cout<<q[i]<<" ";
        }
    }
    cout<<"\n";

}

int main(){
    cQueue cq;
    int choice, item;
    do
    {
        cout<<"1.Insert"<<endl;
        cout<<"2.Delete"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Input the element for insertion in queue : ";
            cin>>item;	
            cq.insert(item);
	        break;
	    case 2:
            cq.del();
	        break;
        case 3:
            cq.display();
	        break;
	    case 4:
	        break;
	    default:
	        cout<<"Wrong choice"<<endl;
	    }
    } while(choice != 4);
    return 0;
    
}