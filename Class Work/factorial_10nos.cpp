#include <iostream>
using namespace std;
int main(){
    int number, i, j, k;
    i = 0;

    while(i<10){
            j = 1;
            k = 1;
            cout<<"Enter number ";
            cin>>number;
            while(j<number+1){
                k = j*k;
                j++;
            }
            cout<<k<<endl;

    }


    return 0;
}

