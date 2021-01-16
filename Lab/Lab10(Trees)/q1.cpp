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
        void post_trav(tree *cur){
            cout<<"Iterative Postorder Traversal: ";

            if(cur==NULL)
                return;
            stack <tree*> s;
            s.push(NULL);
            do{
                while(cur){
                if(cur->rc!=NULL)
                    s.push(cur->rc);
                s.push(cur);
                cur=cur->lc;
                }
                cur=s.top();
                s.pop();
                if(cur->rc==s.top()){
                    s.pop();
                    s.push(cur);
                    cur=cur->rc;
                }
                else
                {
                    cout<<cur->val<<" ";
                    cur=NULL;
                }
                
            }while (s.top()!=nullptr);
            cout<<"\n";
            
            return;
        }

        void inorder_trav(tree *cur){
            cout<<"Iterative Inorder Traversal: ";
        
            if(cur==NULL)
                return;
            stack <tree*> s;
            s.push(NULL);
            while(cur!=NULL||s.top()!=nullptr){
                while(cur){
                 s.push(cur);
                 cur=cur->lc;
                }
                cur=s.top();
                s.pop();
                cout<<cur->val<<" ";
                cur=cur->rc;
                
                
            }
            cout<<"\n";
            return;
        }

        void preorder_trav(tree *cur){
            cout<<"Iterative Preorder Traversal: ";
        
            if(cur==NULL)
                return;
            stack <tree*> s;
            s.push(NULL);
            s.push(cur);
            while(s.top()!=NULL){
                cur=s.top();
                s.pop();
                cout<<cur->val<<" ";
                if(cur->rc!=NULL)   
                    s.push(cur->rc);
                if(cur->lc!=NULL)
                    s.push(cur->lc);
            }
            cout<<"\n";
            return;
        }
        int find_depth(tree *cur){
            if(cur==NULL){
                return 0;
            }
            else{
                int ldepth= find_depth(cur->lc);
                int rdepth = find_depth(cur->rc);

                if(ldepth>rdepth)
                    return(ldepth+1);
                else
                {
                    return(rdepth+1);
                }
                
            }
        }
        void find_parent(tree *cur, int n){
            if(cur->lc){
                if(cur->lc->val==n){
                    cout<<"Parent is "<<cur->val<<"\n";
                    return;
                }
                else
                {
                    find_parent(cur->lc,n);
                }
                
            }
            if(cur->rc){
                if(cur->rc->val==n){
                    cout<<"Parent is "<<cur->val<<"\n";
                    return;
                }
                else
                {
                    find_parent(cur->rc,n);
                }
                
            }
            return;
        }
        int count_leaf(tree *cur){
            if(cur==NULL){
                return 0;
            }
            else if(cur->lc==NULL&&cur->rc==NULL){
                return 1;
            }
            else{
                return count_leaf(cur->lc)+count_leaf(cur->rc);
                
            }
        }

        bool find_ancestors(tree *cur, int n){
            if(cur==NULL){
                return false;
            }
            if(cur->val==n){
                return true;
            }
            if(find_ancestors(cur->lc,n)||find_ancestors(cur->rc,n)){
                cout<<cur->val<<" ";
                return true;
            }
            else
            {
                return false;
            }
            
        }



};


int main(){
    tree t,*t1=NULL;
    t1 = t.createTree();
    t.post_trav(t1);
    t.inorder_trav(t1);
    t.preorder_trav(t1);
    cout<<"The depth is: "<<t.find_depth(t1)<<"\n";
    cout<<"The number of lead nodes are: "<<t.count_leaf(t1)<<"\n";
    cout<<"Enter element whose parent is to be found: ";
    int n;
    cin>>n;
    t.find_parent(t1,n);
    cout<<"Enter element whose ancestors are to be found: ";
    cin>>n;
    bool b = t.find_ancestors(t1,n);
    return 0 ;
}