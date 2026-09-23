#include <iostream>     // Header file for input/output operations like cout
#include <string>       // Header file for using the string data type
#include <utility>      // Header file that provides std::move()


/* ===================== BASE CLASS ===================== */

class Person
{
protected:
    std::string name;    // Stores the person's name
                         // protected members can be accessed by derived classes

public:

    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName))
    {
        // Initializes name using the value of personName
        // std::move() transfers the string's contents efficiently
    }
};


/* ===================== DERIVED CLASS ===================== */

class Student : public Person
{
    // Student publicly inherits from Person

private:
    int rollNumber;      // Stores the student's roll number

public:

    // Constructor of Student class
    Student(std::string studentName, int roll)

        // Constructor initializer list
        : Person(std::move(studentName)),  // Calls Person constructor
          rollNumber(roll)                 // Initializes rollNumber
    {
    }

    // Function to display student information
    void display() const
    {
        // Displays the name inherited from Person
        std::cout << "Name: " << name << '\n';

        // Displays the student's roll number
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};


/* ===================== MAIN FUNCTION ===================== */

int main()
{
    // Creates a Student object
    // "Kiran" is passed as the student's name
    // 24 is passed as the roll number
    Student student("Kiran", 24);

    // Calls the display() function of Student
    student.display();

    // Indicates successful completion of the program
    return 0;
}