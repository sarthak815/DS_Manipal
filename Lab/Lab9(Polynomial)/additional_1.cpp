#include<iostream>
#include <stdlib.h>
using namespace std;
class poly{
    public:
        int coef;
        int exp;
        poly *next;
        poly *prev;
    public:
        void display(poly *a){
            poly *temp = new poly;
            temp=a;
            if(a==NULL){
                cout<<"Polynomial does not exist\n";
                return;
            }
            do{
                if(temp->coef<0){
                    cout<<"-"<<temp->coef<<"x^"<<temp->exp;
                }
                else
                {
                    cout<<"+"<<temp->coef<<"x^"<<temp->exp;
                }
                temp=temp->next;
                
            }while (temp!=a);
            
            
            return;


        }
        poly* attach(int coef1, int exp1, poly *h){
            poly *temp=new poly;
            poly *cur;
            temp->coef = coef1;
            temp->exp=exp1;
            if(h==NULL){
                h=temp;
                temp->next=h;
                temp->prev=h;
                return h;
            }
            cur = h;
            cur->prev->next=temp;
            temp->prev=cur->prev;
            temp->next=cur;
            cur->prev=temp;
            return h;
        }
        poly *read_poly(poly *h){
            int coef, exp,i=0;
            cout<<"Enter -999 to end polynomial\n";
            while(1){
                cout<<"Enter the term "<<i++<<"\n";
                cout<<"Coef=";
                cin>>coef;
                if(coef==-999)break;
                cout<<"Power of x = ";
                cin>>exp;
                h = attach(coef,exp,h);
            }
            return h;
        }
        poly *add_p(poly *h1, poly *h2){
            poly *c=NULL;
            int coef,com;
            poly *a=h1;
            poly *b=h2;
            do{
                if(a->exp==b->exp){
                    com=0;
                }
                else if(a->exp>b->exp){
                    com=1;
                }
                else{
                    com=-1;
                }
                switch (com)

                {
                case 0:
                    coef = a->coef+b->coef;
                    if(coef!=0){
                        c=attach(coef,a->exp,c);
                    }
                    a=a->next;
                    b=b->next;
                    break;
                case 1:
                    c=attach(a->coef, a->exp, c);
                    a=a->next;
                    break;
                
                default:
                    c=attach(b->coef,b->exp,c);
                    b=b->next;
                    break;
                }
                

                
                
            }while(a!=h1||b!=h2);
            
          
            return c;
        }

        poly* multi(poly *a, poly *b){
            poly* c =NULL;
            poly *cur1, *cur2;
            cur1=a;
            do{
                cur2=b;
                do{
                    c=attach(cur1->coef*cur2->coef, cur1->exp+cur2->exp,c);
                    cur2=cur2->next;
                }while (cur2!=b);
                cur1=cur1->next;
            }while (cur1!=a);
        return c; 
        }
};

int main(){
    poly *poly1=NULL, *poly2=NULL, *poly3=NULL, p;
    cout<<"Enter the first polynomial:\n";
    poly1=p.read_poly(poly1);
    p.display(poly1);
    cout<<"\n";
    cout<<"Enter the second polynomial:\n";
    poly2=p.read_poly(poly2);
    p.display(poly2);
    cout<<"\n";
    poly3=p.multi(poly1, poly2);
    cout<<"Product:\n";
    p.display(poly3);

}


