#include <iostream>      // Header file for input/output operations like cout
#include <string>        // Header file for using the string data type
#include <utility>       // Header file that provides std::move()


/* ===================== BASE CLASS ===================== */

class Person
{
protected:
    std::string name;    // Stores the name of the person

public:

    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName))
    {
        // Initializes name using personName
        // std::move() transfers the string efficiently
    }

    // Function to display the person's name
    void displayName() const
    {
        std::cout << "Name: " << name << '\n';
        // Displays the person's name
    }
};


/* ===================== STUDENT CLASS ===================== */

class Student : virtual public Person
{
    // Student virtually inherits from Person
    // This creates a virtual base class relationship

public:

    // Constructor of Student
    Student()
        : Person("Unknown")
    {
        // Normally this would initialize Person
        // However, because Person is a virtual base,
        // the most-derived class will actually initialize Person
    }
};


/* ===================== EMPLOYEE CLASS ===================== */

class Employee : virtual public Person
{
    // Employee virtually inherits from Person
    // This is the second virtual inheritance path to Person

public:

    // Constructor of Employee
    Employee()
        : Person("Unknown")
    {
        // Normally this would initialize Person
        // But Person is a virtual base, so TeachingAssistant
        // will initialize Person instead
    }
};


/* ===================== TEACHING ASSISTANT CLASS ===================== */

class TeachingAssistant : public Student, public Employee
{
    // TeachingAssistant inherits from both Student and Employee

public:

    // Constructor of TeachingAssistant
    explicit TeachingAssistant(std::string assistantName)

        // Initializes the virtual base class Person
        : Person(std::move(assistantName)),

          // Calls Student constructor
          Student(),

          // Calls Employee constructor
          Employee()
    {
    }
};


/* ===================== MAIN FUNCTION ===================== */

int main()
{
    // Creates a TeachingAssistant object
    // "Riya" is passed as the person's name
    TeachingAssistant assistant("Riya");

    // Calls displayName() from the single shared Person object
    assistant.displayName();

    // Indicates successful completion of the program
    return 0;
}