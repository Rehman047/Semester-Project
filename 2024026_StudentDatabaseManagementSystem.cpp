#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//I didn't use any getline statement because multiple words in name disturbed the structure of the table of records. I used cin instead.
struct Student
{
    int reg_no = 2025000;
    string name;
    unsigned int phone;
    string faculty;
    string degree;
};

// Global Vars. total_addedRecords variable is going to track the number of records.
// total_deletedRecords is going to track the number of deleted records
int total_addedRecords = 3; // 3 because 3 records are already added as samples.
Student store[100];
int drecords[100];
int total_deletedRecords = 0;
// int noname; useless variable not used anywhere
// ifstream file; already added separately in download function
// Line to make output look better and presentable
void lineprint()
{
    cout << "\n_________________________________________________________________________________________";
}
// recursive approach to limit the user to enetr phone number only of certain digits
int digit_checker(int n)
{
    if (n == 0)
        return 0;
    return 1 + digit_checker(n / 10);
}
// function to delete record
void deletez(int &total_deletedRecords)
{
    if (total_addedRecords == 0)
    {
        cout << "No records added yet!";
        return;
    }
    cout << "Enter the REG.No ( Only last three digits ) :  ";
    int del;
    cin >> del;
    // check if Reg Number is valid
    while (del > total_addedRecords || del == 0)
    {
        cout << "Invalid Registration Number\nEnter Again : ";
        cin >> del;
    }

    del += 2025000;
    drecords[total_deletedRecords] = del;
    total_deletedRecords++;
    cout << "Record Deleted! ";
}
// function to add record
void add()
{
    // Student S1;
    // Input handling to prevent incorrect output
    cout << "Enter the name of Student : ";

    cin >> store[total_addedRecords].name;
    cout << "Enter the Student's contact number : ";
    cin >> store[total_addedRecords].phone;
    while (digit_checker(store[total_addedRecords].phone) != 3)
    {
        cout << "Phone Number should be 3 digits only\nEnter Phone Number Again : ";
        cin >> store[total_addedRecords].phone;
    }
    cout << "Enter the Student's Faculty e.g. (FCSE,FMCE,FES,FME) : ";
    cin >> store[total_addedRecords].faculty;
    while (store[total_addedRecords].faculty != "FCSE" && store[total_addedRecords].faculty != "FMCE" && store[total_addedRecords].faculty != "FES" && store[total_addedRecords].faculty != "FME")
    {
        cout << "Invalid Faculty. Enter again : ";
        cin >> store[total_addedRecords].faculty;
    }
    if (store[total_addedRecords].faculty == "FCSE")
    {
        cout << "Enter degree. (CS or SE) : ";
        cin >> store[total_addedRecords].degree;
        while (store[total_addedRecords].degree != "CS" && store[total_addedRecords].degree != "SE")
        {
            cout << "Invalid Degree. Enter Again : ";
            cin >> store[total_addedRecords].degree;
        }
    }
    else if (store[total_addedRecords].faculty == "FES")
    {
        cout << "Enter degree. (EE or ES) : ";
        cin >> store[total_addedRecords].degree;
        while (store[total_addedRecords].degree != "EE" && store[total_addedRecords].degree != "ES")
        {
            cout << "Invalid Degree. Enter Again : ";
            cin >> store[total_addedRecords].degree;
        }
    }
    else if (store[total_addedRecords].faculty == "FMCE")
    {
        cout << "Enter degree. (CE or MSE) : ";
        cin >> store[total_addedRecords].degree;
        while (store[total_addedRecords].degree != "CE" && store[total_addedRecords].degree != "MSE")
        {
            cout << "Invalid Degree. Enter Again : ";
            cin >> store[total_addedRecords].degree;
        }
    }
    // Assumed FME faculty only offers ME degree
    else if (store[total_addedRecords].faculty == "FME")
    {
        store[total_addedRecords].degree = "ME";
    }
    store[total_addedRecords].reg_no += total_addedRecords + 1;
    total_addedRecords++;
    cout << "Record added successfully !!! ";
}
// function to edit record
void edit()
{
    if (total_addedRecords == 0)
    {
        cout << "No record added yet.";
        return;
    }
    else
    {
        int regnumber;
        int delete_checker;
        string inp;
        cout << "Enter Registration Number (Only last three digits) : ";
        cin >> regnumber;
        while (regnumber > total_addedRecords || regnumber == 0)
        {
            cout << "Invalid Reg. Number. Enter Again : ";
            cin >> regnumber;
        }

        regnumber += 2025000;
        // new loops to check if record is deleted or not. To prevent entering field before ensuring record is not deleted.
        for (int m = 0; m <= total_addedRecords - 1; m++)
        {
            for (int n = 0; n <= total_deletedRecords; n++)
            {
                if (regnumber == drecords[n])
                {
                    cout << "Record not found!\n";
                    return;
                }
            }
        }
        // if record is not deleted, then allow to edit
        cout << "Enter the name of field to change : ";
        cin >> inp;
        while (inp != "Name" && inp != "Contact" && inp != "Faculty" && inp != "Degree")
        {
            cout << "Invalid Field. Enter again : ";
            cin >> inp;
        }
        for (int j = 0; j <= total_addedRecords - 1; j++)
        {

            //  delete_checker = 1; we have already checked if record is deleted or not. so this variable is not needed anymore
            for (int z = 0; z <= total_deletedRecords; z++)
            {
                if (regnumber == drecords[z])
                {
                    delete_checker = 0;
                }
            }
            // since record is not deleted, we can now edit it
            //   if (delete_checker)
            // {

            if (store[j].reg_no == regnumber)
            {
                regnumber -= 2025000;
                regnumber -= 1;
                if (inp == "Name")
                {
                    cout << "Enter the name of Student : ";
                    cin >> store[regnumber].name;
                    // cout<<"Record edited successfully !!! "; This line was added to prevent a bug. Since the bug is not present anymore, this line is not needed anymore.
                }
                else if (inp == "Contact")
                {
                    cout << "Enter the Student's contact number : ";
                    cin >> store[regnumber].phone;
                    while (digit_checker(store[regnumber].phone) != 3)
                    {
                        cout << "Phone Number should be 3 digits only\nEnter Phone Number Again : ";
                        cin >> store[regnumber].phone;
                    }
                }
                else if (inp == "Faculty")
                {
                    cout << "Enter the Student's Faculty e.g. (FCSE,FMCE,FES,FME) : ";
                    cin >> store[regnumber].faculty;
                    while (store[regnumber].faculty != "FCSE" && store[regnumber].faculty != "FMCE" && store[regnumber].faculty != "FES" && store[regnumber].faculty != "FME")
                    {
                        cout << "Invalid Faculty. Enter again : ";
                        cin >> store[regnumber].faculty;
                    }
                }
                // if user wants to change faculty, he must also change degree because faculty and degree are related
                if (inp == "Degree" || inp == "Faculty")
                {
                    if (store[regnumber].faculty == "FCSE")
                    {
                        cout << "Enter degree. (CS or SE) : ";
                        cin >> store[regnumber].degree;
                        while (store[regnumber].degree != "CS" && store[regnumber].degree != "SE")
                        {
                            cout << "Invalid Degree. Enter Again : ";
                            cin >> store[regnumber].degree;
                        }
                    }
                    else if (store[regnumber].faculty == "FES")
                    {
                        cout << "Enter degree. (EE or ES) : ";
                        cin >> store[regnumber].degree;
                        while (store[regnumber].degree != "EE" && store[regnumber].degree != "ES")
                        {
                            cout << "Invalid Degree. Enter Again : ";
                            cin >> store[regnumber].degree;
                        }
                    }
                    else if (store[regnumber].faculty == "FMCE")
                    {
                        cout << "Enter degree. (CE or MSE) : ";
                        cin >> store[regnumber].degree;
                        while (store[regnumber].degree != "CE" && store[regnumber].degree != "MSE")
                        {
                            cout << "Invalid Degree. Enter Again : ";
                            cin >> store[regnumber].degree;
                        }
                    }
                    else if (store[regnumber].faculty == "FME")
                    {
                        store[regnumber].degree = "ME";
                    }
                }
                cout << "Record edited successfully !!! ";
            }
            //}
        }
    }
}
// function to print all records
void print()
{

    if (total_addedRecords == 0)
    {
        cout << "No record added yet.";
        return;
    }
    else
    {

        lineprint();
        int delete_checker = 1;
        cout << "\nReg Number |\tName\t |\tContact\t  |\tFaculty\t  |\tDegree";
        lineprint();
        cout << endl;
        for (int j = 0; j <= total_addedRecords - 1; j++)
        {

            delete_checker = 1;
            // loop to prevent deleted records
            for (int z = 0; z <= total_deletedRecords; z++)
            {
                if (store[j].reg_no == drecords[z])
                {
                    // cout << "Record just Deleted!\n"; This line was added only for debugging purposes. It is not needed anymore.

                    delete_checker = 0;
                }
            }
            if (delete_checker)
                cout << store[j].reg_no << "    |    " << store[j].name << "\t |\t" << store[j].phone << "\t  |\t " << store[j].faculty << "\t  |\t" << store[j].degree << endl;
        }
    }
}
// function to search for a specific record
void search()
{
    int reg, regnumber;
    reg = 8; // this reg variable is only used as an emergency variable to check if record is found or not. If not found, then it will print "No record found"
    if (total_addedRecords == 0)
    {
        cout << "No Record Added Yet";
        return;
    }
    cout << "Enter Reg Number (only last three digits) : ";
    cin >> regnumber;

    while (digit_checker(regnumber) > 3 || regnumber > total_addedRecords || regnumber == 0)
    {
        cout << "Invalid Reg Number. Enter Again : ";
        cin >> regnumber;
    }

    regnumber += 2025000;
    for (int m = 0; m <= total_addedRecords - 1; m++)
    {
        // loop to prevent deleted records
        for (int z = 0; z <= total_deletedRecords; z++)
        {
            if (regnumber == drecords[z])
            {
                cout << "Record Not Found!";
                return;
            }
        }
    }
    // since record is not deleted, we can now search for it
    for (int z = 0; z <= total_addedRecords - 1; z++)
    {

        if (regnumber == store[z].reg_no)
        {
            cout << "\nSearch Result: ";
            lineprint();
            cout << "\nReg Number |\tName\t |\tContact\t  |\tFaculty\t  |\tDegree\n";
            cout << store[z].reg_no << "    |    " << store[z].name << "\t |\t" << store[z].phone << "\t  |\t " << store[z].faculty << "\t  |\t" << store[z].degree << endl;

            reg = 7;
        }
    }
    if (reg == 8)
        cout << "No record Found! ";
}
// function to download records. Uses file handling's stream to write records to a file.
void download()
{

    ofstream file;
    if (total_addedRecords == 0)
    {
        cout << "No record added yet.";
        return;
    }
    else
    {
        // Write mode because we will overwrite existing data

        file.open("database.txt");
        int delete_check;
        file << "_____________________________________________________________________________";

        file << "\nReg Number |\tName\t |\tContact\t  |\tFaculty\t  |\tDegree\n";
        file << "_____________________________________________________________________________\n";
        for (int j = 0; j <= total_addedRecords - 1; j++)
        {
            delete_check = 1; // is why line 369 is commented out
            for (int z = 0; z <= total_deletedRecords; z++)
            {
                if (store[j].reg_no == drecords[z])
                {
                    // cout<<"Record just Deleted!\n";

                    delete_check = 0;
                }
            }
            if (delete_check)
                file << store[j].reg_no << "    |    " << store[j].name << "\t |\t  " << store[j].phone << "\t  |\t  " << store[j].faculty << "\t  |\t" << store[j].degree << endl;

            //  delete_check++;
        }
        file << "_____________________________________________________________________________";
    }
    cout << "File Created Successfully! ";
    file.close();
}
// function to print all deleted records
void showALL_deletedRecords()
{
    if (total_addedRecords == 0)
    {
        cout << "No record added yet.";
        return;
    }
    else
    {
        cout << "\nDeleted Records: ";
        lineprint();
        int delete_check = 1;
        cout << "\nReg Number |\tName\t |\tContact\t  |\tFaculty\t  |\tDegree\n";

        for (int j = 0; j <= total_addedRecords - 1; j++)
        {

            delete_check = 1;
            // loop to allow deleted records
            for (int z = 0; z <= total_deletedRecords; z++)
            {
                if (store[j].reg_no == drecords[z])
                {
                    // cout<<"Record just Deleted!\n";

                    delete_check = 0;
                }
            }
            // in other functions, we used delete_check to prevent deleted records. Here, we are using it to show deleted records only.
            if (!delete_check) // if delete_check is 0, then show deleted records
                cout << store[j].reg_no << "    |    " << store[j].name << "\t |\t" << store[j].phone << "\t  |\t " << store[j].faculty << "\t  |\t" << store[j].degree << endl;
        }
    }
}
// function to show options to manager
void options()
{
    cout << "\nEnter A to add record of student\n";
    cout << "Enter P to see all student records\nEnter D to delete record\n";
    cout << "Enter S to search for a specific student's record\nEnter X to see all deleted records\nEnter R to edit record\n";
    cout << "Enter I to install information\nEnter E to exit";
}
// function to show options to teacher
void optionst()
{
    cout << "\nEnter P to see all student records\n";
    cout << "Enter S to search for a specific student's record\n";
    cout << "Enter I to install information\nEnter W to enter as manager.\nEnter E to exit";
}

int main()
{
    // three records already added as samples. For teacher because teacher can't add records.
    store[0].name = "Zarrar";
    store[0].degree = "AI";
    store[0].faculty = "FCSE";
    store[0].phone = 345;
    store[0].reg_no += 0 + 1;

    store[1].name = "Hassan";
    store[1].degree = "AI";
    store[1].faculty = "FCSE";
    store[1].phone = 220;
    store[1].reg_no += 1 + 1;

    store[2].name = "Hamza";
    store[2].degree = "CE";
    store[2].faculty = "FMCE";
    store[2].phone = 781;
    store[2].reg_no += 2 + 1;

    cout << "\nWelcome to the Student Database Management System !!!\n";
    cout << "Conrfirm your identity\nEnter 1 to enter as manager and 2 to enter as a teacher: ";
    int input;
    cin >> input;
    while (input != 1 && input != 2)
    {
        cout << "Invalid input. Enter again: ";
        cin >> input;
    }
    int inp;
    int password = 786;
    if (input == 1)
    {
        // Goto Label to allow teacher to enter as manager.
    manager:
        cout << "Enter password to enter: ";
        cin >> inp;
        while (inp != password)
        {
            cout << "Incorrect password. Try Again. : ";
            cin >> inp;
        }
        if (inp == password)
        {

            string in; // string because in case of char variable, if user inputs multiple characters, it will cause an unexpected output.
            do
            {
                lineprint();
                cout << "\nEntering as Manager";
                cout << "\nEnter O to view available options for input\n";
                cout << "Enter Input : ";
                cin >> in;
                while (in != "A" && in != "P" && in != "E" && in != "D" && in != "S" && in != "I" && in != "X" && in != "O" && in != "R")
                {
                    cout << "Enter valid character Amongst A,P,E,S,I,D,X,O,R : ";
                    cin >> in;
                }
                // did not use switch case because it does not work with strings. Used if else instead.
                if (in == "A")
                    add();
                else if (in == "P")
                    print();
                else if (in == "E")
                {
                    cout << "Thanks for using the system!\nExiting...";
                    return 0;
                }
                else if (in == "D")
                    deletez(total_deletedRecords);
                else if (in == "S")
                    search();
                else if (in == "I")
                    download();
                else if (in == "X")
                    showALL_deletedRecords();
                else if (in == "O")
                    options();
                else if (in == "R")
                    edit();
                else
                    cout << "Invalid";
            } while (in != "E");
        }
    }
    else if (input == 2)
    {
        string inpu; // string because in case of char variable, if user inputs multiple characters, it will cause an unexpected output.
        do
        {
            lineprint();
            cout << "\nEntering as Teacher";
            cout << "\nEnter O to view available options for input\n";
            cout << "Enter Input : ";

            cin >> inpu;
            while (inpu != "O" && inpu != "P" && inpu != "S" && inpu != "I" && inpu != "E" && inpu != "W")
            {
                cout << "Invalid input. Enter again: ";
                cin >> inpu;
            }
            // did not use switch case because it does not work with strings. Used if else instead.
            if (inpu == "O")
            {
                optionst();
            }
            else if (inpu == "P")
            {
                print();
            }
            else if (inpu == "I")
            {
                download();
            }
            else if (inpu == "S")
            {
                search();
            }
            else if (inpu == "E")
            {
                cout << "Thanks for using the system!\nExiting...";
                return 0;
            }
            else if (inpu == "W")
            {
                // goto label to allow teacher to enter as manager. Since teacher can't add or delete records.. Manager's input should be 1
                input = 1;
                goto manager;
            }
            else
                cout << "Invalid";
        } while (inpu != "E");
    }
}