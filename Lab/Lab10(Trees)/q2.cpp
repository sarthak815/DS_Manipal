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


};


int main(){
    tree t,*t1=NULL;
    t1 = t.createTree();
    cout<<"The tree is: ";
    t.Inorder(t1);
    return 0 ;
}