#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
void Input(T arr[], int s)
{
    cout << "Enter the elements of the array \n";
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
}

template <class T>
void Display(T arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template <class T>
void Selection_Sort(T a[], int size)
{
    cout << "***Selection Sort***\n";
    for (int i = 0; i < size; i++)
    {
        int minn = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[minn] > a[j])
                minn = j;
        }
        T temp = a[minn];
        a[minn] = a[i];
        a[i] = temp;
    }
}

int main()
{
    int size;
    int choice;

    do
    {
        cout << "\n 1. Integer : ";
        cout << "\n 2. Float : ";
        // cout << "\n 3. Exit : " << endl;
        cout << "\nEnter Choice : ";
        cin >> choice;

        // switch (choice)
        // {
        // case 1:
        //     cout << "Enter the size of array : ";
        //     cin >> size;
        //     int a[size];
        //     Input<int>(a, size);
        //     cout << "Before Sorting : ";
        //     Display<int>(a, size);
        //     Selection_Sort<int>(a, size);
        //     cout << "After Sorting : ";
        //     Display<int>(a, size);
        //     break;
        // case 2:
        //     cout << "Enter the size of array : ";
        //     cin >> size;
        //     float b[size];
        //     Input<float>(b, size);
        //     cout << "Before Sorting : ";
        //     Display<float>(b, size);
        //     Selection_Sort<float>(b, size);
        //     cout << "After Sorting : ";
        //     Display<float>(b, size);
        //     break;
        // default:
        //     break;
        // }

        if (choice == 1)
        {
            cout << "Enter the size of array : ";
            cin >> size;
            int a[size];
            Input<int>(a, size);
            cout << "Before Sorting : ";
            Display<int>(a, size);
            Selection_Sort<int>(a, size);
            cout << "After Sorting : ";
            Display<int>(a, size);
        }
        else if (choice == 2)
        {
            cout << "Enter the size of array : ";
            cin >> size;
            float b[size];
            Input<float>(b, size);
            cout << "Before Sorting : ";
            Display<float>(b, size);
            Selection_Sort<float>(b, size);
            cout << "After Sorting : ";
            Display<float>(b, size);
        }
    } while (choice <= 2 && choice > 0);

    return 0;
}