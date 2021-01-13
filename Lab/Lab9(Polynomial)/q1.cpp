#include<iostream>
#include <stdlib.h>
using namespace std;

class clist{
    private:
        int val;
        clist *next;
        clist *prev;

    public:
        list(){
        
        }
        void insert(int);
        void print();
        void del(int n);

};
clist *head=NULL;
clist *tail=NULL;


void clist::insert(int n){
        clist *temp = new clist;
        temp->val=n;
        if(head==NULL){
            head=temp;
            temp->prev=head;
            temp->next=head;
            tail=head;
            
        }
        else
        {
            temp->next=head;
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
        
    return;

    }
void clist::print(){
           clist *temp=head;
           if(temp==NULL){
               cout<<"List is empty\n";
               return;
           }
           while(temp->next!=head){
               cout<<temp->val<<" ";
               temp=temp->next;
           }
           cout<<temp->val<<"\n";
           return; 
        }

void clist::del(int n){
            clist *temp = new clist;
            temp=head;
            bool b =false;
            if(temp->next==temp){
                if(temp->val==n){
                    head=tail=NULL;
                }
            }
            else if(temp==NULL){
                cout<<"The list is empty\n";
                return;
            }
            else{
                while(temp->next!=head){
                    if(temp->val==n){
                        temp->next->prev=temp->prev;
                        temp->prev->next=temp->next;
                        b=true;
                    }
                    temp=temp->next;
                }
                if(b==false){
                    cout<<"Element not found\n";
                    
                }
                return;
            }

        }

int main()
    {
    clist l1;
    int n;
    while(1)
    {
    cout<<"1. Insert 2. Print 3.Delete 4.Exit\n";
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1: 
        cout<<"Enter number to be inserted: ";
        cin>>n;
        l1.insert(n);
        break;
    case 2: l1.print(); break;
    case 3: 
        cout<<"Enter element to be deleted: ";
        int k;
        cin>>k;
        l1.del(k);
        break;

    default: exit(0);
    }
    }
    
}