#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

struct studentInfo
{
    string name = "Huzaifa";        //Assigning Default Values
    int rollNo = 0;
    int age = 18;
};

void showMenu();
void addStudentInList(list<studentInfo>& argList);
void printStudents   (list<studentInfo>& argList);

int main()
{
    list <studentInfo>  studentsList;   //List of struct student info to store students record

    bool exitFlag = 0;
    do
    {
        showMenu();

        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            addStudentInList(studentsList);
            break;
        case 2:
            printStudents(studentsList);
            break;
        case 3:
            exitFlag = 1;
            break;
        }
        if (!cin)                           //Bad input stream checking
        {
            cin.clear();
            cin.ignore(50, '\n');
        }

    } while(!exitFlag);

    return 0;
}

void showMenu()
{
    cout << "1. Add Student" << endl
             << "2. Show All Students" << endl
             << "3. Exit" << endl << endl
             << "Enter Option :";
}
void addStudentInList(list<studentInfo>& argList)   //Function to add Student
{
    studentInfo student;
    cout << endl << "Enter Name : ";
    cin >> student.name;

        cin.clear();
        cin.ignore(50, '\n');

    cout << endl << "Enter Roll No : ";
    cin >> student.rollNo;

        cin.clear();
        cin.ignore(50, '\n');

    cout << endl << "Enter Age : ";
    cin >> student.age;

        cin.clear();
        cin.ignore(50, '\n');

    argList.push_front(student);
    cout << endl << "Student has been added successfully ! " << endl;
}


bool compare(const studentInfo& first, const studentInfo& second)     //Function to be passed to sorting function
{
    return first.rollNo < second.rollNo;
}

void printStudents(list<studentInfo>& argList)      //Function to print all students in ascending roll no order
{
    cout << endl << "Sorted Data of students :" << endl << endl;

    argList.sort(compare);                          //Built-in list function for sorting

    for (list<studentInfo> :: iterator studentIt = argList.begin() ; studentIt != argList.end(); studentIt++)
    {
        cout << "Name : " << setw(20) << (*studentIt).name
             << setw(15) << "| Roll No : " << setw(20) << (*studentIt).rollNo
             << setw(15) << "| Age : " << setw(3) << (*studentIt).age << endl;
    }
    cout << endl;
}
