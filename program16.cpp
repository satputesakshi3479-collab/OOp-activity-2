#include <iostream>
#include <string>
#include <utility>

using namespace std;

// Abstract base class
class Employee {
protected:
    int employeeId;
    string name;

public:
    // Constructor
    Employee(int id, string employeeName)
        : employeeId(id), name(move(employeeName)) {}

    // Pure virtual function
    virtual double calculateSalary() const = 0;

    // Display employee details
    void displayBasicDetails() const {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

// Permanent employee class
class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double allowance;

public:
    // Constructor
    PermanentEmployee(int id, string employeeName,
                      double basic, double extra)
        : Employee(id, move(employeeName)),
          basicSalary(basic),
          allowance(extra) {}

    // Calculate permanent employee salary
    double calculateSalary() const override {
        return basicSalary + allowance;
    }
};

// Contract employee class
class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    // Constructor
    ContractEmployee(int id, string employeeName,
                     double rate, int hours)
        : Employee(id, move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Calculate contract employee salary
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Function to print pay slip
void printPaySlip(const Employee& employee) {
    employee.displayBasicDetails();

    cout << "Salary: Rs. "
         << employee.calculateSalary()
         << endl << endl;
}

// Main function
int main() {

    // Create permanent employee
    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0
    );

    // Create contract employee
    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80
    );

    // Display permanent employee pay slip
    printPaySlip(permanentEmployee);

    // Display contract employee pay slip
    printPaySlip(contractEmployee);

    return 0;
}