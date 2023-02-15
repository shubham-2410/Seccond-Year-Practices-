/*Implement a class Complex which represents the Complex Number data type. Implement the
following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers.
*/

#include <iostream>
using namespace std;
class Complex
{
private:
    int real, img;

public:
    Complex() : real(0), img(0) {}

    Complex operator+(const Complex &obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    }

    Complex operator*(const Complex &obj)
    {
        Complex temp;
        temp.real = real * (obj.real) - (img) * (obj.img);
        temp.img = real * (obj.img) + img * (obj.real);
        return temp;
    }
    friend ostream &operator<<(ostream &out, const Complex &obj);
    friend istream &operator>>(istream &in, Complex &obj)
    {
        cout << "\nEnter a complex number \n";
        cout << "Real part ";
        in >> obj.real;
        cout << "Enter imaginary part ";
        in >> obj.img;
        return in;
    }
};
ostream &operator<<(ostream &out, const Complex &obj)
    {
        out << "The Complex number is " << obj.real << " + " << obj.img << "i\n";
        return out;
    }
int main()
{
    Complex c1;
    cout << "Complex number with Default arguments :\n";
    cout << c1;

    Complex c2, c3, c4, c5;

    cin >> c2;
    cout << c2;

    cin >> c3;
    cout << c3;

    c4 = c2 + c3;
    cout << "\nNew Complex Number after additon of entered complex numbers\n";
    cout << c4;

    c5 = c2 * c3;
    cout << "\nNew Complex number after multiplication of entered complex numbers \n";
    cout << c5;

    return 0;
}