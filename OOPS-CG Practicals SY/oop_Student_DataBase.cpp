/*Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other.
Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor,destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name, blood_grp, address, drive_lic, classs, DOB;
    int roll;
    long long int contact;
    char div;
    static int count;

public:
    // Constructors
    Student()
    {
        name = "XYZ ";
        roll = 16;
        classs = "SE";
        div = 'A';
        DOB = "24/10/2003";
        blood_grp = "AB+";
        address = "Satara";
        contact = 1020304050;
    }
    friend void display(Student d);

    ~Student() // destructor
    {
        cout << this->name << "(Object) is destroyed!\n";
    }

    void getData()
    {
        count++;
        cout << "\nThe object number " << count << endl;
        cout << "Enter your name : ";
        cin >> name;
        cout << "Enter your roll number : ";
        cin >> roll;
        cout << "Enter your Class : ";
        cin >> classs;
        cout << "Enter your Division : ";
        cin >> div;
        cout << "Enter your DOB : ";
        cin >> DOB;
        cout << "Enter your Blood group : ";
        cin >> blood_grp;
        cout << "Enter your City : ";
        cin >> address;
        cout << "Enter your contact number : ";
        cin >> contact;
    }
};
int Student ::count; // Static variable

void display(Student s)
{
    cout << "\nName :" << s.name << endl;
    cout << "roll(integers) :" << s.roll << endl;
    cout << "Class:" << s.classs << endl;
    cout << "Div (single char):" << s.div << endl;
    cout << "DOB :" << s.DOB << endl;
    cout << "Blood_grp :" << s.blood_grp << endl;
    cout << "City " << s.address << endl;
    cout << "Contact (integers):" << s.contact << endl;
}

int main()
{

    Student obj;
    cout << "Default Values of Constructed\n";
    display(obj);

    // Dynamic memory allocation
    int n;
    cout << "\nEnter the Number of students (n<=5) : ";
    cin >> n;
    Student *s = new Student[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the data ";
        (s + i)->getData();
    }

    for (int i = 0; i < n; i++)
    {
        display(s[i]);
    }

    delete[] s;
    cout << "\nDynamic Memory is deleted \n";

    return 0;
}