/*Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.*/

#include <iostream>
#include <string>
using namespace std;
class Publication
{
protected:
    string title;
    float price;

public:
    Publication()
    {
        cout << "\nConstructor Invoked ";
        cout << "\nIntializing Data \n";
        cout << "Enter the title : ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter the price : ";
        cin >> price;
    }
};

class Book : public Publication
{
private:
    int pg_no;

public:
    Book()
    {
        try
        {
            cout << "Enter the Page Count of the book : ";
            cin >> pg_no;
            if (pg_no < 0)
            {
                throw 404;
            }
        }
        catch (int)
        {
            cout << "Incorrect input Page count should be greater than 0\n";
            pg_no = 0;
        }
    }

    void Display()
    {
        cout << "\nDisplaying data of Book \n";
        cout << "\nTitle : " << title << endl;
        cout << "Price : " << price << endl;
        cout << "Page count : " << pg_no << endl;
    }
};

class Tape : public Publication
{
private:
    int time;

public:
    Tape()
    {
        try
        {
            cout << "Enter the Play time in Minute : ";
            cin >> time;
            if (time < 0)
            {
                throw 404;
            }
        }
        catch (int)
        {
            cout << "Incorrect input Time should be greater than 0\n";
            time = 0;
        }
    }

    void Display()
    {
        cout << "\nDisplaying data of Tape \n";
        cout << "\nTitle : " << title << endl;
        cout << "Price : " << price << endl;
        cout << "Play Time : " << time << endl;
    }
};

int main()
{
    while (true)
    {
        int ch;
        cout << "\n1. for Book\n2. For Tape\n3. Exit ";
        cout << "\nEnter your choice  : ";
        cin >> ch;

        if (ch == 1)
        {
            Book b1;
            b1.Display();
        }
        else if (ch == 2)
        {
            Tape t1;
            t1.Display();
        }
        else
            break;
    }

    return 0;
}