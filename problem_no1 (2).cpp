#include <iostream>   // C++ header file that provides input/output functions like cout and endl
#include <string>     // Header file that provides the string data type

using namespace std;  // Allows us to use cout, string, endl, etc. without writing std::

class Employee {   // Declares the Employee class

protected: //access specifier
    int empId;           // Stores the employee ID
    string name;         // Stores the employee's name
    string department;   // Stores the employee's department

public:  //access specifier

    // Constructor of Employee class
    Employee(int id, string n, string dept)
        : empId(id),              // Initializes empId with id
          name(n),                 // Initializes name with n
          department(dept)         // Initializes department with dept
    {
    }

    // Function to display basic employee information
    void displayBasicInfo() const
    {
        // Displays employee ID, name and department
        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;
    }

    // Pure virtual function for calculating salary
    // Every derived class must provide its own implementation
    virtual double calculateSalary() const = 0;

    // Virtual destructor
    // Allows proper destruction of derived class objects
    virtual ~Employee() = default;
};


class FullTimeEmployee : public Employee { //derived class or child class
    // FullTimeEmployee publicly inherits from Employee

private: //access specifier
    double monthlySalary;   // Stores the monthly salary of a full-time employee

public:  //access specifier

    // Constructor of FullTimeEmployee
    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept),     // Calls Employee constructor
          monthlySalary(salary)      // Initializes monthlySalary
    {
    }

    // Overrides the calculateSalary() function of Employee
    double calculateSalary() const override
    {
        return monthlySalary;        // Returns the monthly salary
    }

    // Function to display full-time employee details
    void display() const
    {
        displayBasicInfo();          // Calls the function inherited from Employee

        // Displays employee type and salary
        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary()    // Calls calculateSalary()
             << endl;                // Moves output to the next line
    }
};

class PartTimeEmployee : public Employee {  //child or derived class
    // PartTimeEmployee publicly inherits from Employee

private:  //access specifier
    double hourlyRate;       // Stores the amount paid per hour
    int hoursWorked;         // Stores the total number of hours worked

public: //access specifier

    // Constructor of PartTimeEmployee
    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)
        : Employee(id, n, dept),    // Calls Employee constructor
          hourlyRate(rate),          // Initializes hourlyRate
          hoursWorked(hours)         // Initializes hoursWorked
    {
    }

    // Overrides the calculateSalary() function
    double calculateSalary() const override
    {
        // Calculates salary using hourly rate × hours worked
        return hourlyRate * hoursWorked;
    }

    // Function to display part-time employee details
    void display() const
    {
        displayBasicInfo();          // Calls the function inherited from Employee

        // Displays employee type and calculated salary
        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary()    // Calculates and displays salary
             << endl;                // Moves output to the next line
    }
};

class Intern : public Employee { // derived or child class
    // Intern publicly inherits from Employee

private:  //access specifier
    double stipend;        // Stores the stipend given to the intern

public:  //access specifier

    // Constructor of Intern class
    Intern(int id, string n, string dept, double stipendAmount)
        : Employee(id, n, dept),    // Calls Employee constructor
          stipend(stipendAmount)    // Initializes stipend
    {
    }

    // Overrides the calculateSalary() function
    double calculateSalary() const override
    {
        return stipend;             // Returns the intern's stipend
    }

    // Function to display intern details
    void display() const
    {
        displayBasicInfo();         // Calls the function inherited from Employee

        // Displays employee type and stipend
        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary()   // Calls calculateSalary()
             << endl;               // Moves output to the next line
    }
};

int main()
{
    // Creates a FullTimeEmployee object
    // ID = 101, Name = Amit, Department = IT, Salary = Rs. 65000
    FullTimeEmployee f1(101, "Amit", "IT", 65000);

    // Creates a PartTimeEmployee object
    // ID = 102, Name = Sneha, Department = HR
    // Hourly rate = Rs. 250 and hours worked = 120
    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);

    // Creates an Intern object
    // ID = 103, Name = Rohan, Department = Marketing
    // Stipend = Rs. 15000
    Intern i1(103, "Rohan", "Marketing", 15000);

    // Displays the heading of the payroll
    cout << "=== Employee Payroll ===" << endl;

    // Displays Full-Time employee information
    f1.display();

    // Displays Part-Time employee information
    p1.display();

    // Displays Intern information
    i1.display();

    // Indicates successful completion of the program
    return 0;
}