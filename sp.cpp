#include<iostream>
using namespace std;
struct Student{
    int reg_no=2025000;
    string name;



};

//Glpbal Vars
    int i=0;
    Student store[100];
    int drecords[100];
    int ddd=0;
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
    }else{
   
    cout<<"Reg Number | \tName\n";
    
    for(int j=0;j<=i-1;j++){
        

     if(j<=ddd){
    if(store[j].reg_no==drecords[j]){
     cout<<"Record just Deleted!\n";
     continue;}}
     
    cout<<store[j].reg_no<<"    | \t"<<store[j].name<<endl;
    
    
    }
    }   }

void deletez(int &ddd){
    cout<<"Enter the REG.No ( Only last three digits ) :  ";
    int del;
    cin>>del;
    if(del>i){
        cout<<"Invalid REG . No";
    }
    del+=2025000;
    drecords[ddd]=del;
    ddd++;
    cout<<"Record Deleted! ";

}

int main(){


char in;
do {
cout<<"\nWelcome to the Student Database Management System\nEnter A to add record of student\n";
cout<<"Enter P to see all student records\nEnter D to delete record\nEnter E to exit\n: ";
cin>>in;
while(in!='A' && in !='P' && in!='E' && in!='D'){
    cout<<"Enter valid character : ";
    cin>>in;
}

if (in=='A')
add();
else if(in=='P')
print();
else if (in=='E')
return 0;
else if(in=='D')
deletez(ddd);
else
cout<<"Invalid";
} while (in!='E');

}