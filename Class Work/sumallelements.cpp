#include <iostream>
using namespace std;
int main(){
    int sum, i,n;
    i = 0;
    n = 0;
    sum = 0;
    while(n!=-1){
        cout<<"Enter number: \n";
        cin>>n;
        switch(n){
        case -1:
            break;
        default:
            sum = sum + n;
        }
    }
    cout<<"\n"<<sum;
    return 0;
}
