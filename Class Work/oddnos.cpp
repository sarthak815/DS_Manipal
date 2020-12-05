#include <iostream>
using namespace std;
int main(){
    int number, i, j, k, m, n;
    i = 0;
    cout<<"Enter first number";
    cin>>m;
    cout<<"\nEnter second number";
    cin>>n;
    for(i=m;i<n;i++){
        if(i%2==0){
            continue;
        }
        else{
            cout<<i<<endl;
        }
    }

    return 0;
}
