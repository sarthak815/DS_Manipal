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
        
        dlist* union1(dlist *a, dlist *b){
            dlist *result = NULL;
            dlist *t1=a, *t2=b;

            while (t1!=NULL)
            {
                result = append(result,t1->val);
                t1=t1->next;
            }
            while (t2!=NULL)
            {
                if(!ispresent(result,t2->val)){
                    result = append(result,t2->val);
                }
                t2=t2->next;
            }

            return result;

        }
        dlist* intersection(dlist *a, dlist *b){
            dlist *temp = NULL;
            dlist *a1 = a;
          
            while(a1!=NULL){
                if(ispresent(b,a1->val)&&!ispresent(temp,a1->val)){
                    temp = append(temp,a1->val);
                }
                a1=a1->next;
            }
            return temp;

        }
        bool ispresent(dlist *a, int b){
            dlist *temp=a;
            while(temp!=NULL){
                if(temp->val==b){
                    return 1;
                }
                temp=temp->next;
            }
            return 0;
        }
};     

int main()
    {
    dlist *d1=NULL, *d2=NULL, d3, *d4=NULL, *d5=NULL;
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
    d5 = d3.union1(d1, d2);
    d3.display(d5);
    d4 = d3.intersection(d1, d2);
    d3.display(d4);
    
}