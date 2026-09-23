#include <iostream>      // Header file for input and output operations like cout and endl
#include <memory>        // Header file for smart pointers like unique_ptr and make_unique
#include <string>        // Header file for using the string data type
#include <vector>        // Header file for using the vector container
using namespace std;     // Allows us to use cout, string, vector, etc. without std::

class Vehicle // parent or base clas
{
protected: //access specifier
    string vehicleId;             // Stores the unique ID of the vehicle
    string registrationNumber;    // Stores the vehicle registration number
    double fuelLevel;             // Stores the current fuel level

public: //access specifier

    // Constructor of Vehicle class
    Vehicle(string vid, string reg)
        : vehicleId(vid),              // Initializes vehicleId with vid
          registrationNumber(reg),     // Initializes registrationNumber with reg
          fuelLevel(100.0)             // Sets initial fuel level to 100%
    {
    }

    // Function to start the vehicle engine
    void startEngine() const
    {
        cout << "Vehicle " << vehicleId
             << " engine started." << endl;
        // Displays the vehicle ID and engine status
    }

    // Function to add fuel to the vehicle
    void refuel(double amount)
    {
        fuelLevel += amount;
        // Adds the given amount of fuel to the current fuel level

        if (fuelLevel > 100.0)
        {
            fuelLevel = 100.0;
            // Prevents fuel level from going above 100%
        }
    }

    // Virtual function to display vehicle information
    virtual void displayInfo() const
    {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
        // Displays basic vehicle information
    }

    // Virtual destructor
    // Ensures proper destruction of derived class objects
    virtual ~Vehicle() = default;
};

class Truck : public Vehicle //child class
{
    // Truck publicly inherits from Vehicle

private:  //access specifier
    double cargoCapacity;       // Stores the truck's cargo capacity

public: //access specifier

    // Constructor of Truck class
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg),          // Calls Vehicle constructor
          cargoCapacity(capacity)     // Initializes cargo capacity
    {
    }

    // Overrides the displayInfo() function of Vehicle
    void displayInfo() const override
    {
        cout << "Truck | ";
        // Displays the type of vehicle

        Vehicle::displayInfo();
        // Calls displayInfo() of the base Vehicle class

        cout << "Cargo capacity: "
             << cargoCapacity
             << " tonnes" << endl;
        // Displays the truck's cargo capacity
    }
};

class DeliveryVan : public Vehicle //child class
{
    // DeliveryVan publicly inherits from Vehicle

private: //access specifier
    int packageCount;       // Stores the number of packages loaded

public:  //access specifier

    // Constructor of DeliveryVan class
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg),          // Calls Vehicle constructor
          packageCount(packages)       // Initializes package count
    {
    }

    // Overrides displayInfo() of Vehicle
    void displayInfo() const override
    {
        cout << "Delivery Van | ";
        // Displays the vehicle type

        Vehicle::displayInfo();
        // Calls displayInfo() from the Vehicle class

        cout << "Packages loaded: "
             << packageCount << endl;
        // Displays the number of packages loaded
    }
};

class Bike : public Vehicle // child class
{
    // Bike publicly inherits from Vehicle

private: //access specifier
    bool hasDeliveryBox;       // Stores whether the bike has a delivery box

public: //access specifier

    // Constructor of Bike class
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg),          // Calls Vehicle constructor
          hasDeliveryBox(hasBox)      // Initializes delivery box status
    {
    }

    // Overrides displayInfo() of Vehicle
    void displayInfo() const override
    {
        cout << "Delivery Bike | ";
        // Displays the vehicle type

        Vehicle::displayInfo();
        // Calls displayInfo() from the base class

        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
        // Displays whether the delivery box is available
    }
};

int main()
{
    // Creates a vector that stores unique pointers
    // to Vehicle objects
    vector<unique_ptr<Vehicle>> fleet;


    // Creates a Truck object and adds it to the fleet
    fleet.push_back(
        make_unique<Truck>(
            "V001",              // Vehicle ID
            "MH12-AB-1234",      // Registration number
            10.5                 // Cargo capacity in tonnes
        )
    );


    // Creates a DeliveryVan object and adds it to the fleet
    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002",              // Vehicle ID
            "MH12-CD-5678",      // Registration number
            50                   // Number of packages
        )
    );


    // Creates a Bike object and adds it to the fleet
    fleet.push_back(
        make_unique<Bike>(
            "V003",              // Vehicle ID
            "MH12-EF-9012",      // Registration number
            true                 // Delivery box is available
        )
    );


    // Displays the heading
    cout << "=== Fleet Status ===" << endl;


    // Loops through every vehicle in the fleet
    for (const auto& vehicle : fleet)
    {
        // Calls the startEngine() function
        vehicle->startEngine();

        // Calls the appropriate displayInfo()
        // based on the actual object type
        vehicle->displayInfo();

        // Prints a blank line
        cout << endl;
    }


    // Indicates successful completion of the program
    return 0;
}