#include <iostream>   // Header file that provides input/output functions like cout


/* ===================== ACADEMIC CLASS ===================== */

class Academic
{
public:

    // Function to display academic information
    void display() const
    {
        std::cout << "Academic information\n";
        // Prints academic information
    }
};


/* ===================== SPORTS CLASS ===================== */

class Sports
{
public:

    // Function to display sports information
    void display() const
    {
        std::cout << "Sports information\n";
        // Prints sports information
    }
};


/* ===================== STUDENT CLASS ===================== */

// Student inherits from both Academic and Sports
// This is called Multiple Inheritance
class Student : public Academic, public Sports
{
public:

    // Function to display information from both parent classes
    void displayAll() const
    {
        Academic::display();
        // Calls display() function of Academic class

        Sports::display();
        // Calls display() function of Sports class
    }
};


/* ===================== MAIN FUNCTION ===================== */

int main()
{
    // Creates an object named student of Student class
    Student student;


    // Calls display() function specifically from Academic class
    student.Academic::display();


    // Calls display() function specifically from Sports class
    student.Sports::display();


    // Calls displayAll() function of Student class
    // This internally calls both Academic::display()
    // and Sports::display()
    student.displayAll();


    // Indicates successful termination of program
    return 0;
}