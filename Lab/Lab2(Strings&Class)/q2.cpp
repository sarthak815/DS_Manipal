#include<iostream>
#include <stdlib.h>
using namespace std;

class Student{
    private:
        int i,j,k=0;
        char name[100];
        int roll;
        char grade;

    public:
        void get_details(Student s[], int n){
            for(i=0;i<n;i++){
                fflush(stdin);
                cout<<"Enter name of the student: ";
                gets(s[i].name);
                cout<<"Enter Roll No.: ";
                cin>>(s[i].roll);
                cout<<"Enter Grade: ";
                cin>>(s[i].grade);
            }
        }
        void display_details(Student s[], int n){
            for(i=0;i<n;i++){
                cout<<"Student "<<i+1<<":\n";
                cout<<"Name: "<<s[i].name<<"\n";
                cout<<"Roll_No: "<<s[i].roll<<"\n";
                cout<<"Grade: "<<s[i].grade<<"\n";
            }
        }
        void sort_details(Student s[], int n){
            Student temp;
            for(i=0;i<n;i++){
                int min = i;
                for(j=i+1;j<n;j++){
                    if(s[min].roll>s[j].roll){
                        min=j;
                    }
                }
                temp = s[i];
                s[i]=s[min];
                s[min]=temp;
            }
        }

};



int main(){
    int n;
    cout<<"Enter Number of students: ";
    cin>>n;
    fflush(stdin);
    Student s[n],a;
    a.get_details(s,n);
    a.display_details(s,n);
    a.sort_details(s,n);
    a.display_details(s,n);
    return 0;
}