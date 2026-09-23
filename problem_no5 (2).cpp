#include <iostream>     // Provides input/output functions like cout
#include <string>       // Provides the std::string data type
#include <utility>      // Provides std::move()

using namespace std;    // Allows us to use string, cout, etc. without std::


class Person // parent or base class declaration
{
protected: // access specifier
    string name;        // Stores the name of the person
                        // protected means derived classes can access it

public: // access specifier

    // Constructor of Person class
    explicit Person(string personName)
        : name(move(personName))   // Moves personName into name
    {
    }

    // Function to display the person's name
    void displayName() const
    {
        cout << "Name: " << name << '\n';   // Prints the name
    }
};

class Student : public Person // child class or derived class
{
private: // access specifier
    int rollNumber;     // Stores the student's roll number

public:

    // Constructor of Student class
    Student(string studentName, int roll)
        : Person(move(studentName)),        // Calls Person constructor
          rollNumber(roll)                  // Initializes rollNumber
    {
    }

    // Function to display student information
    void displayStudent() const
    {
        displayName();     // Calls displayName() inherited from Person

        cout << "Roll Number: "
             << rollNumber << '\n';        // Prints roll number
    }
};


int main()
{
    // Creates a Student object named student
    // "Amit" is passed as name and 101 as roll number
    Student student("Amit", 101);

    // Calls displayStudent() to display student's information
    student.displayStudent();

    // Indicates that the program ended successfully
    return 0;
}