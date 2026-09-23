#include <iostream>              // Includes input/output functions like cout
#include <string>                // Includes the string data type
#include <utility>               // Includes utility functions like move()

class Person {                   // Defines the base class Person

protected:                       // Protected members can be accessed by derived classes
    std::string name;             // Stores the person's name

public:                          // Public members can be accessed from outside the class

    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName)) {}   // Initializes name with personName

    void showPerson() const {              // Function to display person's details
        std::cout << "Name: " << name << '\n';  // Prints the person's name
    }
};

class Employee : public Person {           // Employee inherits from Person

protected:                                  // Protected members
    int employeeId;                         // Stores employee ID

public:                                     // Public members

    // Constructor of Employee class
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)),  // Calls Person constructor
          employeeId(id) {}                 // Initializes employeeId

    void showEmployee() const {             // Function to display employee details
        std::cout << "Employee ID: " << employeeId << '\n'; // Prints employee ID
    }
};

class Manager : public Employee {           // Manager inherits from Employee

private:                                    // Private members
    int teamSize;                           // Stores the number of team members

public:                                     // Public members

    // Constructor of Manager class
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), // Calls Employee constructor
          teamSize(size) {}                     // Initializes teamSize

    void showManager() const {                  // Function to display manager details

        showPerson();                            // Calls Person's showPerson() function

        showEmployee();                          // Calls Employee's showEmployee() function

        std::cout << "Team Size: " << teamSize << '\n'; // Prints team size
    }
};

int main() {                                    // Main function; execution starts here

    Manager manager("Ravi", 501, 8);             // Creates Manager object

    manager.showManager();                       // Calls showManager() function

    return 0;                                    // Ends the program successfully
}