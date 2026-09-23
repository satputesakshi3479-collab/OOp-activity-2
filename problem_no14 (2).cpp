#include <iostream>   // Header file for input/output operations like cout


/* ===================== BASE CLASS ===================== */

class Vehicle
{
public:

    // Virtual function of the base class
    virtual void move() const
    {
        std::cout << "Vehicle is moving\n";
        // Displays a general vehicle movement message
    }

    // Virtual destructor
    // Ensures proper destruction of derived class objects
    virtual ~Vehicle() = default;
};


/* ===================== CAR CLASS ===================== */

class Car : public Vehicle
{
    // Car publicly inherits from Vehicle

public:

    // Overrides the move() function of Vehicle
    void move() const override
    {
        std::cout << "Car moves on roads\n";
        // Displays how a car moves
    }
};


/* ===================== BOAT CLASS ===================== */

class Boat : public Vehicle
{
    // Boat publicly inherits from Vehicle

public:

    // Overrides the move() function of Vehicle
    void move() const override
    {
        std::cout << "Boat moves on water\n";
        // Displays how a boat moves
    }
};


/* ===================== MAIN FUNCTION ===================== */

int main()
{
    // Creates an object of Car class
    Car car;

    // Creates an object of Boat class
    Boat boat;


    // Calls the move() function of Car
    car.move();

    // Calls the move() function of Boat
    boat.move();


    // Indicates successful completion of the program
    return 0;
}