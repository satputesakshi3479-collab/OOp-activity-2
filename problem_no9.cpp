#include <iostream>                    // Includes input/output functions like cout
#include <string>                      // Includes the string data type
#include <utility>                     // Includes utility functions like move()

class Vehicle {                        // Defines the base class Vehicle

protected:                             // Protected members can be accessed by derived classes
    std::string registrationNumber;    // Stores vehicle registration number

public:                                // Public members can be accessed from outside the class

    // Constructor of Vehicle class
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {} // Initializes registration number

    void start() const {               // Function to start the vehicle
        std::cout << "Vehicle " << registrationNumber
                  << " started\n";     // Displays vehicle registration number and start message
    }
};

class Car : public Vehicle {           // Car publicly inherits from Vehicle

public:                                // Public members

    // Constructor of Car class
    explicit Car(std::string registration)
        : Vehicle(std::move(registration)) {} // Calls Vehicle constructor

    void openBoot() const {            // Function to open the car boot
        std::cout << "Car boot opened\n"; // Displays boot opened message
    }
};

class Bike : public Vehicle {          // Bike publicly inherits from Vehicle

public:                                // Public members

    // Constructor of Bike class
    explicit Bike(std::string registration)
        : Vehicle(std::move(registration)) {} // Calls Vehicle constructor

    void helmetReminder() const {      // Function to give helmet reminder
        std::cout << "Please wear a helmet\n"; // Displays helmet reminder
    }
};

int main() {                           // Main function; program execution starts here

    Car car("MH12AB1234");             // Creates a Car object with registration number

    Bike bike("MH12CD5678");           // Creates a Bike object with registration number

    car.start();                       // Calls start() function inherited from Vehicle

    car.openBoot();                    // Calls Car's openBoot() function

    bike.start();                      // Calls start() function inherited from Vehicle

    bike.helmetReminder();             // Calls Bike's helmetReminder() function

    return 0;                          // Ends the program successfully
}