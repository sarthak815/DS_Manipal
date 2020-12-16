#include<iostream>
#include <stdlib.h>
using namespace std;
const int N=5;
const int Size=10;
class nStacks{
    private:
        int s[Size]={0};
        int item;
        int stk;
        int top[N];
        int bottom[N+1];
    public:
        nStacks(){
            for(int i=0,j=-1;i<N;i++,j+=Size/N){
                top[i]=j;
                bottom[i]=j;
            }
            bottom[N]=Size-1;
        }
        void push(int,int);
        int pop(int);
        int peek(int);
        bool isfull(int);
        bool isEmpty(int);
};
bool nStacks::isfull(int stk){
    if(top[stk]+1==bottom[stk+1]){
            return true;
        }
        return false;

}
bool nStacks::isEmpty(int stk){
    if(top[stk]==bottom[stk]){
            return true;
        }
        return false;

}

void nStacks::push(int item,int stk){
    if(!(isfull(stk))){
        s[++top[stk]]=item;
    }
    

}
int nStacks::pop(int stk){
    if(!isEmpty(stk)){
            return s[top[stk]--];
        }
        return -1;
}
int nStacks::peek(int stk){
      if(!isEmpty(stk)){
            return s[top[stk]];
        }
        return -1;

}



int main(){

    nStacks S;
    S.push(1,0);
    S.push(2,1);
    S.push(3,2);
    S.push(4,3);
    S.push(5,4);
    cout<<S.peek(0)<<endl;
    cout<<S.peek(1)<<endl;
    cout<<S.peek(2)<<endl;
    cout<<S.peek(3)<<endl;
    cout<<S.peek(4)<<endl;
}