#include<iostream>
#include <stdlib.h>
using namespace std;

class list{
    private:
        int val;
        list *next;

    public:
        list(){
            list *head=NULL;
            list *tail=NULL;
        }
        void insert(int);
        void print();
        void del();

};


void list::insert(int n){
            list* temp = new list;
            temp->next = NULL;
            temp->val=n;
            if(head!=NULL&&tail!=NULL){
                tail->next=temp;
                tail=temp;
            }
            else{
                tail=head=temp;
            }


        }
void list::print(){
            list *h = head;
            while(h!=NULL){
                cout<<h->val<<" ";
                h = h->next;
            }
            cout<<"\n";
            return;
        }

void list::del(){
            list *temp = new list;
            temp=head;
            if(head==NULL){
                cout<<"List empty";
            }
            if(head!=NULL){
                head=head->next;

            }
            if(head==NULL){
                tail=NULL;
            }
            cout<<"Element deleted: "<<temp->val<<"\n";
            delete(temp);
        }

int main()
    {

    list l1;
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
    case 3: l1.del();
    break;

    default: exit(0);
    }
    }
}