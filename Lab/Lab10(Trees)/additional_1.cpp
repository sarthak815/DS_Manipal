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
        int equality(tree *a, tree *b){
            if(a==NULL&&b==NULL){
                return 1;
            }
            else if(a==NULL&&b!=NULL){
                return 0;
            }
            else if (a!=NULL&&b==NULL)
            {
                return 0;
            }
            else{
                if(a->val==b->val&&equality(a->lc,b->lc)&&equality(a->rc,b->rc)){
                    return 1;
                }
                else
                {
                    return 0;
                }
                
            }
            
        }


};


int main(){
    tree t,*t1=NULL,*t2=NULL;
    cout<<"Enter tree 1:\n";
    t1 = t.createTree();
    cout<<"The tree is: ";
    t.Inorder(t1);
    cout<<"Enter tree 2:\n";
    t2=t.createTree();
    t.Inorder(t2);
    if(t.equality(t1,t2)){
        cout<<"The trees are equal";

    }
    else{
        cout<<"Trees not equal";
    }

    return 0 ;
}