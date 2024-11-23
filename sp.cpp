#include<iostream>
using namespace std;
struct Student{
    int reg_no=2025000;
    string name;



};
    int i=0;
    Student store[100];
void add(){
    Student S1;
    cout<<"Enter the name of student : ";

    cin>>store[i].name;
    
    store[i].reg_no+=i+1;
    i++;
    cout<<"Record added successfully";
}
void print(){
    
    if (i==0){
        cout<<"No record added yet.";
        return;
    }
    cout<<"Reg Number | \tName\n";
    
    for(int j=0;j<=i-1;j++){
    cout<<store[j].reg_no<<"    | \t"<<store[j].name<<endl;
    
    
    }
}
int main(){


char in;
do {
cout<<"\nWelcome to the Student Database Management System\nEnter A to add record of student\n";
cout<<"Enter P to see all student records\nEnter E to exit\n: ";
cin>>in;
while(in!='A' && in !='P' && in!='E'){
    cout<<"Enter valid character : ";
    cin>>in;
}

if (in=='A')
add();
else if(in=='P')
print();
else if (in=='E')
return 0;
else
cout<<"Invalid";
} while (in!='E');

}