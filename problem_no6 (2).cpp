#include <iostream>     // Includes input/output functions like cout
#include <string>       // Includes the string data type
#include <utility>      // Includes utility functions like move()

class Employee {        // Defines the base class Employee

protected:              // Members can be accessed by this class and derived classes
    std::string name;   // Stores the employee's name

public:                 // Public members can be accessed from outside the class

    // Constructor of Employee class
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName)) {}   // Initializes name with employeeName
};

class Developer : public Employee {   // Developer inherits from Employee

private:                               // Private members can be accessed only inside Developer
    std::string language;              // Stores the programming language

public:                                // Public members can be accessed from outside the class

    // Constructor of Developer class
    Developer(std::string employeeName, std::string programmingLanguage)
        : Employee(std::move(employeeName)),   // Calls Employee constructor
          language(std::move(programmingLanguage)) {} // Initializes language

    void display() const {             // Function to display developer details
        std::cout << "Developer: " << name << '\n';     // Displays developer's name
        std::cout << "Language: " << language << '\n';  // Displays programming language
    }
};

int main() {                           // Main function where program execution starts

    Developer developer("Neha", "C++"); // Creates Developer object with name and language

    developer.display();                // Calls display() function

    return 0;                           // Ends the program successfully
}