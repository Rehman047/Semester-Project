#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Student{
    int reg_no=2025000;
    string name;
    unsigned int phone;
    

};

//Glpbal Vars
    int i=0;
    Student store[100];
    int drecords[100];
    int ddd=0;
    int daj;
    fstream file;

void lineprint(){
    cout<<"\n_______________________________________________________________";

}
int digcheck(int n){
    if (n==0)
    return 0;
    return 1+digcheck(n/10);
}
void deletez(int &ddd){
    if(i==0){
        cout<<"No records added yet!";
        return;
    }
    cout<<"Enter the REG.No ( Only last three digits ) :  ";
    int del;
    cin>>del;
    while(del>i||del==0){
        cout<<"Invalid Registration Number\nEnter Again : ";
        cin>>del;
    }
    
    del+=2025000;
    drecords[ddd]=del;
    ddd++;
    cout<<"Record Deleted! ";
    
}
void add(){
    Student S1;
    cout<<"Enter the name of Student : ";

    cin>>store[i].name;
    cout<<"Enter the Student's contact number : ";
    cin>>store[i].phone;
    while(digcheck(store[i].phone)!=3){
        cout<<"Phone Number should be 3 digits only\nEnter Phone Number Again : ";
        cin>>store[i].phone;

    }
    store[i].reg_no+=i+1;
    i++;
    cout<<"Record added successfully !!! ";
}
void edit(){
    if(i==0){
        cout<<"No record added yet.";
        return;
    } else{
        int regn;
        int edch;
        string inp;
        cout<<"Enter Registration Number : ";
        cin>>regn;
        while(regn>i || regn==0){
            cout<<"Invalid Reg. Number. Enter Again : ";
            cin>>regn;
        }
        cout<<"Enter the name of field to change : ";
        cin>>inp;
        while(inp!="Name"&& inp!="Contact"){
            cout<<"Invalid Field. Enter again : ";
            cin>>inp;
        }

        regn+=2025000;
      for(int j=0;j<=i-1;j++){
        
       edch=1;
    for(int z=0;z<=ddd;z++){
    if(store[j].reg_no==drecords[z]){
     cout<<"Record just Deleted!\n";
    edch=0;
     }
    }
    if(edch){

        if(store[j].reg_no==regn){
            regn-=2025000;
            regn-=1;
            if(inp=="Name"){
    cout<<"Enter the name of Student : ";
    cin>>store[regn].name;
    cout<<"Record edited successfully !!! ";
    }else if(inp=="Contact"){
    cout<<"Enter the Student's contact number : ";
    cin>>store[regn].phone;
    while(digcheck(store[regn].phone)!=3){
        cout<<"Phone Number should be 3 digits only\nEnter Phone Number Again : ";
        cin>>store[regn].phone;}
        cout<<"Record edited successfully !!! ";
        }}
   }
    
    }
    }
}
void print(){
    
    if (i==0){
        cout<<"No record added yet.";
        return;
    }else{
    
    lineprint();
   int delch=1;
    cout<<"\nReg Number |\tName\t |\tContact";
    lineprint();
    cout<<endl;
    for(int j=0;j<=i-1;j++){
        
       delch=1;
    for(int z=0;z<=ddd;z++){
    if(store[j].reg_no==drecords[z]){
     cout<<"Record just Deleted!\n";
     
     delch=0;
     
     }
    
    }
    if(delch)
    cout<<store[j].reg_no<<"    |    "<<store[j].name<<"\t |\t"<<store[j].phone<<endl;
    
    }
    
    }   
    
    }



void search(){
    int reg,regno;
    reg=8;
    if(i==0){
        cout<<"No Record Added Yet";
        return;
    }
    cout<<"Enter Reg Number only last three digits : ";
    cin>>regno;
    if(digcheck(regno)>3){
        while(digcheck(regno)>3 || regno>i ||regno==0){
        cout<<"Invalid Reg Number. Enter Again : ";
        cin>>regno;}
    } 
    regno+=2025000;
        for(int z=0;z<=i-1;z++){
            
            
            for(int dc=0;dc<=ddd;dc++){
                if(regno==drecords[dc]){
                    cout<<"Deleted";
                    return;
                }
            }
                if(regno==store[z].reg_no){
                    
                cout<<"Reg Number |\tName\t |\tContact\n";
                cout<<store[z].reg_no<<"    |    "<<store[z].name<<"\t |\t"<<store[z].phone<<endl;
                reg=7;
                }
            }
         if(reg==8)
        cout<<"No record Found! ";
    
}
void download(){
     
    if (i==0){
        cout<<"No record added yet.";
        return;
    }else{
    file.open("database.txt",ios::out);
   int delch=2;
   file<<"_______________________________________________________________";

    file<<"\nReg Number |\tName\t |\tContact\n";
    file<<"_______________________________________________________________\n";
    for(int j=0;j<=i-1;j++){
        

    for(int z=0;z<=ddd;z++){
    if(store[j].reg_no==drecords[z]){
     //cout<<"Record just Deleted!\n";
     
     delch=1;
     
     }
    
    }
    if(delch!=1)
    file<<store[j].reg_no<<"    |    "<<store[j].name<<"\t |\t"<<store[j].phone<<endl;
    delch++;
    }
    file<<"_______________________________________________________________";

    }   
    cout<<"File Created Successfully! ";
    file.close();
}
void del_rec(){
    if (i==0){
        cout<<"No record added yet.";
        return;
    }else{
    lineprint();
   int delch=1;
    cout<<"\nReg Number |\tName\t |\tContact\n";
    
    for(int j=0;j<=i-1;j++){
        
        delch =1;
    for(int z=0;z<=ddd;z++){
    if(store[j].reg_no==drecords[z]){
     //cout<<"Record just Deleted!\n";
     
     delch=0;
     
     }
    
    }
    if(!delch)
    cout<<store[j].reg_no<<"    |    "<<store[j].name<<"\t |\t"<<store[j].phone<<endl;
    
    }
    
    }   
    
}
void options(){
cout<<"\nEnter A to add record of student\n";
cout<<"Enter P to see all student records\nEnter D to delete record\n";
cout<<"Enter S to search for a specific student's record\nEnter X to see all deleted records\nEnter R to edit record\n";
cout<<"Enter I to install information\nEnter E to exit";
}

int main(){

string in;
do {
lineprint();
cout<<"\nWelcome to the Student Database Management System !!!\nEnter O to view available options for input\n";
cout<<"Enter Input : ";
cin>>in;
while(in!="A" && in !="P" && in!="E" && in!="D" && in!="S"&& in!="I" &&in!="X"&&in!="O"&&in!="R"){
    cout<<"Enter valid character Amongst A,P,E,S,I,D,X,O,R : ";
    cin>>in;
}

if (in=="A")
add();
else if(in=="P")
print();
else if (in=="E")
return 0;
else if(in=="D")
deletez(ddd);
else if(in=="S")
search();
else if(in=="I")
download();
else if(in=="X")
del_rec();
else if(in=="O")
options();
else if(in=="R")
edit();
else
cout<<"Invalid";
} while (in!="E");

}