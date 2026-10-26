//Write a C++ program to demonstrate the concept of templates.
//Implement a function template to find the maximum of two values and a class template to perform basic arithmetic operations on two numbers.

#include <iostream>
using namespace std;

// Function Template
template <class T>
T findMaximum(T a, T b)
{
    return (a > b) ? a : b;
}

// Class Template
template <class T>
class Calculator
{
private:
    T num1, num2;

public:
    Calculator(T a, T b)
    {
        num1 = a;
        num2 = b;
    }

    void display()
    {
        cout << "\nAddition: " << num1 + num2;
        cout << "\nSubtraction: " << num1 - num2;
        cout << "\nMultiplication: " << num1 * num2;

        if (num2 != 0)
            cout << "\nDivision: " << num1 / num2;
        else
            cout << "\nDivision: Not possible (division by zero)";
    }
};

int main()
{
    int a = 10, b = 5;

    cout << "FUNCTION TEMPLATE";
    cout << "\nMaximum of " << a << " and " << b
         << " is: " << findMaximum(a, b);

    float x = 12.5f, y = 4.5f;

    cout << "\nMaximum of " << x << " and " << y
         << " is: " << findMaximum(x, y);

    cout << "\n\nCLASS TEMPLATE (INTEGER)";
    Calculator<int> c1(20, 10);
    c1.display();

    cout << "\n\nCLASS TEMPLATE (FLOAT)";
    Calculator<float> c2(7.5f, 2.5f);
    c2.display();

    return 0;
}
