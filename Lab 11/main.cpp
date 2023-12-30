#include <iostream>
#include <list>
using namespace std;

struct studentInfo
{
    string name = "Huzaifa";        //Assigning Default Values
    int rollNo = 0;
    int age = 18;
};

void addStudentInList(list<studentInfo>& argList);
void printStudents   (list<studentInfo>& argList);

int main()
{
    list <studentInfo>  studentsList;   //List of struct student info to store students record

    bool exitFlag = 0;
    do
    {
        char input;
        cout << "Do you want to add a student? (Y/N) : ";
        cin >> input;

        switch (input)
        {
        case 'Y':
        case 'y':
            addStudentInList(studentsList);
            break;
        case 'N':
        case 'n':
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


