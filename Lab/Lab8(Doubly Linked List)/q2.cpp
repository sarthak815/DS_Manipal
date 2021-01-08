#include<iostream>
#include <stdlib.h>
using namespace std;

class dlist{
    private:
        int val;
        dlist *next;
        dlist *prev;

    public:
        dlist *head, *tail;
        dlist(){
            head=NULL;
            tail=NULL;
        }
        dlist* append(dlist *h, int n){
            dlist *trav=h;
            dlist *temp = new dlist;
            temp->val=n;
            temp->next=NULL;
            if(trav==NULL){
                temp->prev=NULL;
                h = temp;
                return h;
            }
            while(trav->next!=NULL){
                trav=trav->next;
            }
            trav->next=temp;
            temp->prev=trav;
            return h;
            

        }
        void display(dlist* h){
            dlist *temp=h;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
        dlist* concat(dlist *a, dlist *b){
            dlist *temp = a;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=b;
            b->prev=temp;
            return a;
        }
};     

int main()
    {
    dlist *d1=NULL, *d2=NULL, d3;
    cout<<"Enter list 1(-1 to break):"<<endl;
    int c;
    while (true){
        cin>>c;
        if(c==-1){
            break;
        }
            d1 = d3.append(d1,c);
    }
    cout<<"Enter list 2(-1 to break):"<<endl;
    while (true){
        cin>>c;
        if(c==-1){
            break;
        }
            d2 = d3.append(d2,c);
    }
    d3.display(d1);
    d3.display(d2);
    d3.concat(d1,d2);
    d3.display(d1);
    
    
}