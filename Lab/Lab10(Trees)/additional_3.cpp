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
        tree* createTree(){
            tree *p;
            int x;
            cout<<"Enter data(-1 to stop): ";
            cin>>x;

            if(x==-1)
                return NULL;
            p = new tree;
            p->val=x;

            cout<<"Enter left child of "<<x<<": ";
            p->lc=createTree();

            cout<<"Enter right child of: "<<x<<": ";
            p->rc=createTree();

            return p;
        }
        void Inorder(tree *node){
            if (node==NULL){
                return;
            }
            Inorder(node->lc);
            cout<<node->val<<" ";
            Inorder(node->rc);
        }
        tree* clone(tree *a){
            if(a==NULL){
                return NULL;
            }
            tree* c = new tree;
            c->val=a->val;
            c->lc=clone(a->lc);
            c->rc=clone(a->rc);
            return c;

            
        }


};


int main(){
    tree t,*t1=NULL,*t2=NULL;
    cout<<"Enter tree 1:\n";
    t1 = t.createTree();
    cout<<"The tree is: ";
    t.Inorder(t1);
    t2=t.clone(t1);
    cout<<"\nThe clone is: ";
    t.Inorder(t2);

    return 0 ;
}