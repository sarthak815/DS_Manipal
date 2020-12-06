#include<iostream>
#include <stdlib.h>
using namespace std;

class Time{
    private:
        int i,j;
        int hour, min,sec;
        char ch;

    public:
        void get_details(){
            cout<<"Enter in format hh:mm:ss : ";
            cin>>hour>>ch>>min>>ch>>sec;
        }
        void display_details(){
               cout<<hour<<':'<<min<<':'<<sec<<"\n";
            }
        
        void add(Time t1, Time t2){
            int s=t1.sec+t2.sec;
            int m=t1.min+t2.min;
            int h=t1.hour+t2.hour;
            sec=s%60;
            min=(m+s/60)%60;
            hour=(h+m/60)%24;
        }
        void difference(Time t1, Time t2){
            Time temp;
            if(t1.hour>t2.hour){
                temp=t1;
                t1=t2;
                t2=temp;
            }
            sec=t1.sec-t2.sec;
            min=t1.min-t2.min;
            hour=t1.hour-t2.hour;
            if (sec<0){
                min-=1;
                sec+=60;
            }
            if(min<0){
                hour-=1;
                min+=60;
            }
        
        }

};



int main(){
    Time t1,t2;
    t1.get_details();
    t2.get_details();
    Time t3, t4;
    t3.add(t1,t2);
    t4.difference(t1,t2);
    cout<<"Sum ";
    t3.display_details();
    cout<<"Difference  ";
    t4.display_details();
}