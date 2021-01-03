#include<iostream>
#include <stdlib.h>
using namespace std;

class list{
    private:
        int val;
        list *next;

    public:
        list(){

        }
        void append_after(int,int);
        void append_before(int,int);
        void insert(int);
        void print();
        void del();
        void del_num(int);
        void reverse();
        void sort();
        void del_alt();
        void insert_sort(int);

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
                found=true;
                return;
            }


            while(temp->next!=NULL){
                if(temp->next->val==n){
                    if(temp->next->next==NULL){
                        temp->next=NULL;
                        found = true;
                    }
                    temp->next=temp->next->next;
                    found=true;
                    break;
                }
                temp=temp->next;
            }

        if(!found){
            cout<<"Element not in list";
        }
            
}

void list::reverse(){
            list *h = head;
            list *prev = NULL;
            list *next = NULL;
            while(h!=NULL){
                next=h->next;
                h->next=prev;
                prev=h;
                h=next;
            }
            head=prev;
}
void list::sort(){
            list *h = head;
            list *n= new list;
            list *k = NULL;
            int temp;
            while(h!=NULL){
                k=h;
                n=h->next;
                while(n!=NULL){
                    if(n->val<k->val)
                        k=n;
                    n = n->next;

                }
                if(k!=h){
                    temp=k->val;
                    k->val=h->val;
                    h->val=temp;
                }
                h=h->next;
            }
}

void list::del_alt(){
            list *h=head;
            list *h1=h->next;
            while(h!=NULL&&h1!=NULL)  {
                h->next=h1->next;
                h = h->next;
                if(h!=NULL){
                    h1=h->next;
                }
            }
            
            
}

void list::insert_sort(int n){
            list *h = head;
            list *p= new list;
            p->val=n;
            list *k = NULL;
            int temp;

            if(head==NULL){
                insert(n);
                return;
            }

            if(h->val>n){
                p->next=head;
                head=p;
                return;
            }


            while(h->next!=NULL){
                if(h->next->val>n){
                    p->next=h->next;
                    h->next=p;
                    return;
                }
                
                h=h->next;
            }
            if(h->next==NULL){
                h->next=p;
                p->next=NULL;
            }
            
}





void list::insert(int n){
            list *temp=new list; 
            temp->next =NULL;
            temp->val=n;
            if(head!=NULL && tail!=NULL)
            { 
            tail->next=temp;
            tail=temp;
            }
            else
            { 
            tail=head=temp;
            }
            return ;


        }
void list::print(){
            list *h = head;
            cout<<"The elements are: ";
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
    int n,l;
    while(1)
    {
    cout<<"1. Insert\n2. Print\n3.Delete\n5.Insert Element before another\n6.Insert Element after another\n7.Delete an element from the list\n8.Reverse\n9. Sort\n10. Delete alternate node\n11.Insert element in sorted list\n12.Exit\n";
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
        l1.append_before(l,n);
        break;
    case 7:
        cout<<"Enter number to be deleted: ";
        cin>>n;
        l1.del_num(n);
        break;
    case 8:l1.reverse();break;
    case 9:l1.sort();break;
    case 10:l1.del_alt();break;
    case 11: 
        cout<<"Enter number to be inserted: ";
        cin>>n;
        l1.insert_sort(n);
        break;
    default: exit(0);
    }
    }
}