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

        
        dlist* sum1(dlist *d1, dlist *d2){
            dlist *t1=NULL; 
            dlist *t2=NULL, *d3, *d4=NULL;
            int carry =0;
            int sum;
            while(d1->next!=NULL){
            
                d1=d1->next;
            }
            t1=d1;
            while(d2->next!=NULL){
               
                d2 = d2->next;
            }
            t2=d2;
            while(t2!=NULL||t1!=NULL){
                if(t1!=NULL && t2!=NULL){
                    int sum = t1->val+t2->val;
                
                    if(carry!=0){
                        sum = sum+carry;
                        carry=0;
                    
                    }
                    if(sum>9){
                        carry = sum/10;
                        sum = sum%10;
                        
                    }
                    t2=t2->prev;
                    t1=t1->prev;

                    d4 = append(d4,sum);
                    
                    sum = 0;

                }
                else if(t1==NULL&&t2!=NULL){
                    int sum =t2->val;
                        if(carry!=0){
                            int sum = carry;
                            carry=0;
                        }
                               
                        t2=t2->prev;    
                        d4 = append(d4,sum);
                    
                }
                else if(t1!=NULL&&t2==NULL) {
                        int sum=t1->val;
                        if(carry!=0){
                            int sum = sum+carry;
                            carry=0;
                        } 
                        t1=t1->prev;                
                        d4 = append(d4,sum);
                    
                }
            }
            if(carry!=0){
                d4 = append(d4,carry);
            }
            return d4;
        }
        void display_reverse(dlist *a){
            dlist *temp=a;
            dlist *t;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            t=temp;
            while(t!=NULL){
                cout<<t->val<<"";
                t=t->prev;
            }
        }
         
    };     

int main()
    {
    dlist *d1=NULL, *d2=NULL, d3, *d4=NULL, *d5=NULL;
    int c;
    char a[100], b[100];
    cout<<"Enter first number: ";

    cin.getline(a,100);
    cout<<"Enter second number: ";
    cin.getline(b, 100);
    for(int i=0;a[i]!=NULL;i++){
        int n = a[i]-'0';
        d1 = d3.append(d1,n);
    }
    for (int i = 0; b[i]!=NULL;i++)
    {
        int n = b[i]-'0';
        d2 = d3.append(d2, n);
    }
   
    d4 = d3.sum1(d1,d2);
    d3.display_reverse(d4);
    return 0;
}