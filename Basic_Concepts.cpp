#include <iostream>
using namespace std;
int main(){
    int number, i, prime;
    i = 2;
    prime = 1;
    cout<<"enter number";
    cin>>number;
    while(i<number){
            if(number%i == 0){
                prime = 0;
                break;


            }
            else{
                prime = 1;
                i++;
            }

    }

    if(prime == 0){
        cout<<"Prime";
    }
    else{
        cout<<"Not Prime";
    }
    return 0;
}
