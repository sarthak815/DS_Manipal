#include <iostream>
using namespace std;
int main(){
    int j, i,n,k;
    n = 0;
    j = 1;
    k = 0;
    i = 1;
    cout<<"Enter number: ";
    cin>>n;
    while(i<n){
        while(k<j){
        cout<<i<<" ";
        i++;
        k++;
        }
        cout<<"\n";
        k = 0;
        j++;
    }
    return 0;
}
