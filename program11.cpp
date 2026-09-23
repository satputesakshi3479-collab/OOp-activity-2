#include <iostream>   // Includes the input and output library

// Defines the base class Shape
class Shape {
public:
    // Declares a pure virtual function for calculating area
    virtual double area() const = 0;   // Makes Shape an abstract class

    // Virtual destructor for safe destruction of derived objects
    virtual ~Shape() = default;
};

// Defines the Rectangle class that inherits from Shape
class Rectangle : public Shape {
private:
    double length;   // Stores the length of the rectangle
    double width;    // Stores the width of the rectangle

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {
        // Initializes the rectangle dimensions
    }

    // Implements the pure virtual area function
    double area() const override {
        return length * width;   // Returns the area of the rectangle
    }
};

// Main function
int main() {

    Rectangle rectangle(8.0, 4.0);   // Creates a Rectangle object with length 8 and width 4

    // Calculates and displays the rectangle area
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';

    return 0;   // Ends the program successfully
}