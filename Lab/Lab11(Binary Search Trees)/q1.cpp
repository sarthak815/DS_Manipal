#include<iostream>
#include <stdlib.h>
#include<stack>
using namespace std;

class tree{
    private:
        int val;
        tree *lc;
        tree *rc;
    public:

        tree(){
            lc=NULL;
            rc=NULL;
        }
        tree(int n){
            val=n;
            lc=NULL;
            rc=NULL;
    
        }
        tree* insert(tree *p, int n){
            if (p==NULL)
            {
                cout<<n<<"\n";
                return new tree(n);
            }
            if(n<p->val)
                p->lc=insert(p->lc,n);
            

            else
                p->rc=insert(p->rc,n);
            
            return p;
        }

        tree* delete1(tree *p, int n){
            cout<<"Deleting\n";
            if(p==NULL){
                return p;
            }

            if(n<p->val){
                p->lc=delete1(p->lc,n);
            }
            else if(n>p->val)
            {
                 p->rc=delete1(p->rc, n);
            }

            else
            {
                tree* temp;
                if(p->lc==NULL){
                    temp=p->rc;
                    delete p;
                    return temp;
                }
                else if(p->rc==NULL){
                    temp=p->lc;
                    delete p;
                    return temp;
                }

                    temp=p;
                    while(temp && temp->lc){
                        temp=temp->lc;
                    }

                    p->val=temp->val;
                    p->rc=delete1(p->rc,temp->val);
                
                  
            }
            return p;
            
            
        }


        tree* search(tree *a, int n){
            if(a==NULL||a->val==n){
                return a;
            }
            if(a->val<n)
                return search(a->rc,n);

            return search(a->lc, n);
        }
        //same for additional 1
        void print1(tree *a){
            if(!a)
                return;
            print1(a->lc);
            cout<<a->val<<" ";
            print1(a->rc);
        }



};


int main(){
    tree *t1=NULL;
    tree t;
    t1=t.insert(t1, 8);
    t1=t.insert(t1, 2);
    t1=t.insert(t1, 3);
    t1=t.insert(t1, 5);
    t1=t.insert(t1, 4);
    t1=t.insert(t1, 10);
    t1=t.insert(t1, 12);
    t.print1(t1);
    cout<<"\n";
    t1 = t.delete1(t1,3);
    t.print1(t1);
    return 0 ;
}