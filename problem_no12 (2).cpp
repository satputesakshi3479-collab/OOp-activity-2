#include <iostream>   // Header file for input/output operations like cout


/* ===================== BASE CLASS ===================== */

class Base
{
public:

    // Constructor of Base class
    Base()
    {
        std::cout << "Base constructor\n";
        // Prints message when Base object is constructed
    }

    // Destructor of Base class
    ~Base()
    {
        std::cout << "Base destructor\n";
        // Prints message when Base object is destroyed
    }
};


/* ===================== DERIVED CLASS ===================== */

class Derived : public Base
{
    // Derived publicly inherits from Base

public:

    // Constructor of Derived class
    Derived()
    {
        std::cout << "Derived constructor\n";
        // Prints message when Derived object is constructed
    }

    // Destructor of Derived class
    ~Derived()
    {
        std::cout << "Derived destructor\n";
        // Prints message when Derived object is destroyed
    }
};


/* ===================== MAIN FUNCTION ===================== */

int main()
{
    // Creates an object of Derived class
    Derived object;

    // When the object is created:
    // 1. Base constructor is called first
    // 2. Derived constructor is called second

    // When main() ends:
    // 1. Derived destructor is called first
    // 2. Base destructor is called second

    return 0;   // Ends the program successfully
}