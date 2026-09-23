#include <iostream>      // Provides input/output functions such as std::cout
#include <string>        // Provides the std::string class
#include <utility>       // Provides std::move()

class University {       // Outer class named University
public:

    // Nested class Department is declared inside University
    class Department {

    private:
        std::string name;    // Stores the name of the department

    public:

        // Constructor of Department
        // 'explicit' prevents unwanted implicit conversions
        explicit Department(std::string departmentName)

            // Initializer list initializes name
            // std::move transfers the string instead of copying it
            : name(std::move(departmentName)) {}

        // Function to display department information
        // const means this function does not modify the object
        void display() const {

            // Prints the department name
            std::cout << "Department: " << name << '\n';
        }
    };
};

int main() {

    // Creates an object of the nested Department class
    // Syntax: OuterClass::NestedClass
    University::Department department(
        "Artificial Intelligence and Data Science"
    );

    // Calls the display() function using the department object
    department.display();

    // Indicates successful program termination
    return 0;
}