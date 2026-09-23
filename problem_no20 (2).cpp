#include <iostream>      // Provides input/output functions such as std::cout
#include <string>        // Provides the std::string class
#include <utility>       // Provides std::move()

// Base class
class Employee {

protected:
    // Employee ID
    // protected allows derived classes to access this member
    int employeeId;

    // Stores employee name
    std::string name;

public:

    // Constructor of Employee
    Employee(int id, std::string employeeName)

        // Initialize employeeId with id
        : employeeId(id),

          // Move employeeName into name
          name(std::move(employeeName)) {}

    // Pure virtual function
    // Every derived class must provide its own salary calculation
    virtual double calculateSalary() const = 0;

    // Function to display common employee information
    void displayBasicDetails() const {

        // Display employee ID
        std::cout << "Employee ID: " << employeeId << '\n';

        // Display employee name
        std::cout << "Name: " << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;
};


// Derived class for permanent employees
class PermanentEmployee : public Employee {

private:
    // Basic salary of permanent employee
    double basicSalary;

    // Additional allowance
    double allowance;

public:

    // Constructor of PermanentEmployee
    PermanentEmployee(
        int id,
        std::string employeeName,
        double basic,
        double extra
    )

        // Calls the constructor of Employee
        : Employee(id, std::move(employeeName)),

          // Initializes basic salary
          basicSalary(basic),

          // Initializes allowance
          allowance(extra) {}

    // Overrides the pure virtual function
    double calculateSalary() const override {

        // Permanent employee salary
        // = basic salary + allowance
        return basicSalary + allowance;
    }
};


// Derived class for contract employees
class ContractEmployee : public Employee {

private:
    // Payment received per hour
    double hourlyRate;

    // Total number of hours worked
    int hoursWorked;

public:

    // Constructor of ContractEmployee
    ContractEmployee(
        int id,
        std::string employeeName,
        double rate,
        int hours
    )

        // Calls Employee constructor
        : Employee(id, std::move(employeeName)),

          // Initializes hourly rate
          hourlyRate(rate),

          // Initializes hours worked
          hoursWorked(hours) {}

    // Overrides the pure virtual function
    double calculateSalary() const override {

        // Contract employee salary
        // = hourly rate × hours worked
        return hourlyRate * hoursWorked;
    }
};


// Function to display an employee's payslip
// const Employee& means:
// 1. Employee can be passed by reference
// 2. The original object is not copied
// 3. The function cannot modify the employee
void displayPaySlip(const Employee& employee) {

    // Displays common employee information
    employee.displayBasicDetails();

    // Calls the appropriate calculateSalary()
    // depending on the actual object
    std::cout << "Salary: "
              << employee.calculateSalary()
              << "\n\n";
}


int main() {

    // Creates a PermanentEmployee object
    // ID = 101
    // Name = Asha
    // Basic salary = 40000
    // Allowance = 8000
    PermanentEmployee permanentEmployee(
        101,
        "Asha",
        40000.0,
        8000.0
    );

    // Creates a ContractEmployee object
    // ID = 102
    // Name = Vikas
    // Hourly rate = 500
    // Hours worked = 80
    ContractEmployee contractEmployee(
        102,
        "Vikas",
        500.0,
        80
    );

    // Passes PermanentEmployee object to displayPaySlip()
    displayPaySlip(permanentEmployee);

    // Passes ContractEmployee object to displayPaySlip()
    displayPaySlip(contractEmployee);

    // Indicates successful program termination
    return 0;
}