#include <iostream>      // Provides input/output functions such as std::cout
#include <string>        // Provides the std::string class
#include <utility>       // Provides std::move()

// Base class
class Vehicle {

protected:
    // Registration number of the vehicle
    // protected means derived classes can access it
    std::string registrationNumber;

    // Rental rate charged per day
    double ratePerDay;

public:

    // Constructor of Vehicle
    Vehicle(std::string registration, double rate)

        // Initialize registrationNumber using move
        : registrationNumber(std::move(registration)),

          // Initialize ratePerDay with the given rate
          ratePerDay(rate) {}

    // Virtual function to calculate rent
    // Derived classes can override this function
    virtual double calculateRent(int days) const {

        // Normal rent = rate per day × number of days
        return ratePerDay * days;
    }

    // Virtual function to display vehicle information
    virtual void display() const {

        // Display registration number
        std::cout << "Registration: " << registrationNumber << '\n';

        // Display rental rate per day
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    // Virtual destructor
    // Ensures proper destruction of derived objects
    virtual ~Vehicle() = default;
};


// Car inherits publicly from Vehicle
class Car : public Vehicle {

private:
    // Stores the number of doors in the car
    int numberOfDoors;

public:

    // Constructor of Car
    Car(std::string registration, double rate, int doors)

        // Calls the constructor of the base class Vehicle
        : Vehicle(std::move(registration), rate),

          // Initializes numberOfDoors
          numberOfDoors(doors) {}

    // Overrides the display() function of Vehicle
    void display() const override {

        // Calls the display() function of the Vehicle class
        // to display common vehicle information
        Vehicle::display();

        // Displays car-specific information
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};


// Bike inherits publicly from Vehicle
class Bike : public Vehicle {

private:
    // Stores the engine capacity of the bike
    int engineCapacity;

public:

    // Constructor of Bike
    Bike(std::string registration, double rate, int capacity)

        // Calls Vehicle constructor
        : Vehicle(std::move(registration), rate),

          // Initializes engineCapacity
          engineCapacity(capacity) {}

    // Overrides calculateRent() from Vehicle
    double calculateRent(int days) const override {

        // Bike gets a 10% discount
        // Therefore, only 90% of normal rent is charged
        return ratePerDay * days * 0.9;
    }

    // Overrides display() from Vehicle
    void display() const override {

        // Calls Vehicle's display() to show common information
        Vehicle::display();

        // Displays bike-specific information
        std::cout << "Engine Capacity: "
                  << engineCapacity
                  << " cc\n";
    }
};


int main() {

    // Creates a Car object
    // Registration = MH12AB1234
    // Rate = 2000 per day
    // Number of doors = 5
    Car car("MH12AB1234", 2000.0, 5);

    // Creates a Bike object
    // Registration = MH12CD5678
    // Rate = 800 per day
    // Engine capacity = 150 cc
    Bike bike("MH12CD5678", 800.0, 150);


    // Prints heading for car details
    std::cout << "Car Details\n";

    // Calls Car's display() function
    car.display();

    // Calculates and displays rent for 3 days
    // 2000 × 3 = 6000
    std::cout << "Rent for 3 days: "
              << car.calculateRent(3)
              << "\n\n";


    // Prints heading for bike details
    std::cout << "Bike Details\n";

    // Calls Bike's display() function
    bike.display();

    // Calculates and displays bike rent for 3 days
    // 800 × 3 × 0.9 = 2160
    std::cout << "Rent for 3 days: "
              << bike.calculateRent(3)
              << '\n';


    // Indicates successful termination of the program
    return 0;
}