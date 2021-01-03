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
        void insert(int,list*);
        void print(list*);
        void del();

};

list *head=NULL;
list *tail=NULL;


void list::insert(int n, list *h){
            list* temp = new list;
    
            if(h==NULL){
                temp->next = NULL;
                temp->val=n;
                head=temp;
                return;
            }
            if(h->next!=NULL){
                return insert(n,h->next);
            }
            else{
                temp->next = NULL;
                temp->val=n;
                h->next=temp;
                return;
            }


        }
void list::print(list* h){
           
            if(h!=NULL){
                cout<<h->val<<" ";
                return print(h->next);
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
        l1.insert(n,head);
        break;
    case 2: l1.print(head); break;
    case 3: l1.del();
    break;

    default: exit(0);
    }
    }
}