#include<iostream>
#include <stdlib.h>
using namespace std;

class list{
    private:
        int val;
        list *next;
        list *prev;

    public:
        list(){

        }
        //v)
        void append_after(int,int);
        //vi)
        void append_before(int,int);
        //i)
        void insert(int);
        //vii)
        void print();
        //ii)
        void del();
        void del_num(int);
        //viii)
        void reverse();
        //iv)
        void del_pos(int);
        //iii)
        void insert_pos(int,int);
        

};
list *head=NULL;
list *tail=NULL;

void list::append_after(int elem, int n){
            list* temp = new list;
            temp->val=n;
            bool found = false;
            list *h = head;
            while(h!=NULL){
                if((h->val)==elem){
                    temp->next=h->next;
                    h->next->prev=temp;
                    temp->prev=h;
                    h->next=temp;
                    found=true;
                    break;
                }
    
                h = h->next;
            }
            if(!found){
                cout<<"Element not found \n";
            }
}

void list::append_before(int elem, int n){
            list* temp = new list;
            temp->val=n;
            bool found = false;
            list *h = head;
            while(h!=NULL){
                if((h->next->val)==elem){
                    temp->next=h->next;
                    h->next=temp;
                    temp->prev=h;
                    h->next->prev=temp;
                    found=true;
                    break;
                }
    
                h = h->next;
            }
            if(!found){
                cout<<"Element not found \n";
            }
}

void list::del_num(int n){
            list *temp = head;
            bool found = false;

            if(temp->val==n){
                head = temp->next;
                head->prev=NULL;
                found=true;
                return;
            }


            while(temp!=NULL){
                if(temp->val==n){
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                }
                temp=temp->next;
            }

        if(!found){
            cout<<"Element not in list";
        }
            
}

void list::reverse(){
            list *k= head;
            list *j=NULL;
            while(k!=NULL){
                j=k->next;
                k->next=k->prev;
                k->prev=j;
                k=k->prev;
            }
            k=tail;
            tail=head;
            head=k;
            return;
}

void list::del_pos(int pos){
            list *h=head;
            int count =0;
            if(pos==0){
                h=h->next;
                h->prev=NULL;
                return;
            }
            while(h!=NULL){
                if(count==pos){
                    h->next->prev=h->prev;
                    h->prev->next=h->next;
                    return;
                }
                count++;
                h=h->next;
            }
            if(h==NULL){
                cout<<"Position is out of range\n";
            }           
            
}

void list::insert_pos(int elem, int n){
            list* temp = new list;
            temp->val=n;
            list *h = head;
            int count=0;
            if(h==NULL){
                cout<<"The list is empty\n";
                return;
            }
            while(h!=NULL){
                if(count==elem){
                    break;
                }
                count++;
                h=h->next;
            }
            
            temp->prev=h->prev;
            h->prev->next=temp;
            temp->next=h;
}


void list::insert(int n){
            list* temp = new list;
            temp->next = NULL;
            temp->prev = NULL;
            temp->val=n;
            if(head!=NULL&&tail!=NULL){
                temp->prev=tail;
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
            
        }

void list::del(){
            list *temp = new list;
            temp=tail;
            if(temp==NULL){
                cout<<"List empty";
            }
            else{
                temp->prev->next=NULL;
            }
            
        }

int main()
    {

    list l1;
    int n,l;
    while(1)
    {
    cout<<"1. Insert\n2. Print\n3.Delete\n5.Insert Element before another\n6.Insert Element after another\n7.Delete an element from the list\n8.Reverse\n9.Insert element at particular position\n10.Exit\n";
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
    case 3: l1.del();break;
    case 5:
        cout<<"Enter number to be inserted and before: ";
        cin>>n>>l;
        l1.append_before(l,n);
        break;
    case 6:
        cout<<"Enter number to be inserted and after: ";
        cin>>n>>l;
        l1.append_after(l,n);
        break;
    case 7:
        cout<<"Enter number to be deleted: ";
        cin>>n;
        l1.del_num(n);
        break;
    case 8:l1.reverse();break;
    case 9:
        int n,pos;
        cout<<"Enter position and number: ";
        cin>>pos>>n;
        l1.insert_pos(pos,n);   
        break;
    default: exit(0);
    }
    }
}