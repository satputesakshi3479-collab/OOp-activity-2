#include <iostream>   // Includes the input and output library

// Defines the base class Shape
class Shape {
public:
    // Virtual function to calculate area
    virtual double area() const {
        return 0.0;   // Returns 0 as the default area
    }

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

    // Overrides the area function of Shape
    double area() const override {
        return length * width;   // Returns the area of the rectangle
    }
};

// Defines the Circle class that inherits from Shape
class Circle : public Shape {
private:
    double radius;   // Stores the radius of the circle

public:
    // Constructor to initialize the radius
    explicit Circle(double givenRadius) : radius(givenRadius) {
        // Assigns the given radius to the radius variable
    }

    // Overrides the area function of Shape
    double area() const override {
        constexpr double PI = 3.141592653589793;   // Defines the constant value of PI
        return PI * radius * radius;                // Returns the area of the circle
    }
};

// Function to print the area of any Shape object
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';   // Calculates and displays the area
}

// Main function
int main() {
    Rectangle rectangle(5.0, 3.0);   // Creates a Rectangle object with length 5 and width 3

    Circle circle(2.0);   // Creates a Circle object with radius 2

    printArea(rectangle);   // Calls printArea to display the rectangle's area

    printArea(circle);      // Calls printArea to display the circle's area

    return 0;   // Ends the program successfully
}