#include <iostream>   // Includes input and output library

// Base class
class Base {
public:

    // Virtual destructor
    virtual ~Base() {
        std::cout << "Base destructor\n";   // Displays message
    }
};

// Derived class inherits from Base
class Derived : public Base {
public:

    // Derived class destructor
    ~Derived() override {
        std::cout << "Derived destructor\n";   // Displays message
    }
};

// Main function
int main() {

    // Creates a Derived object using a Base class pointer
    Base* pointer = new Derived();

    // Deletes the object using the Base pointer
    delete pointer;

    return 0;   // Ends the program successfully
}