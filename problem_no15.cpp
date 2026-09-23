#include <iostream>   // Header file for input/output operations like cout


/* ===================== ABSTRACT BASE CLASS ===================== */

class Shape
{
public:

    // Pure virtual function
    // It does not have a definition in the Shape class
    // Every derived class must provide its own area() function
    virtual double area() const = 0;

    // Virtual destructor
    // Allows proper destruction of derived class objects
    virtual ~Shape() = default;
};


/* ===================== RECTANGLE CLASS ===================== */

class Rectangle : public Shape
{
    // Rectangle publicly inherits from Shape

private:
    double length;    // Stores the length of the rectangle
    double width;     // Stores the width of the rectangle

public:

    // Constructor of Rectangle class
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength),       // Initializes length
          width(givenWidth)          // Initializes width
    {
    }

    // Overrides the pure virtual area() function
    double area() const override
    {
        // Calculates and returns the area of rectangle
        return length * width;
    }
};


/* ===================== CIRCLE CLASS ===================== */

class Circle : public Shape
{
    // Circle publicly inherits from Shape

private:
    double radius;       // Stores the radius of the circle

public:

    // Constructor of Circle class
    // explicit prevents unwanted implicit conversion
    explicit Circle(double givenRadius)
        : radius(givenRadius)        // Initializes radius
    {
    }

    // Overrides the pure virtual area() function
    double area() const override
    {
        // Calculates and returns the area of circle
        // Formula: π × radius × radius
        return 3.141592653589793 * radius * radius;
    }
};


/* ===================== MAIN FUNCTION ===================== */

int main()
{
    // Creates a Rectangle object
    // Length = 5.0 and Width = 3.0
    Rectangle rectangle(5.0, 3.0);

    // Creates a Circle object
    // Radius = 2.0
    Circle circle(2.0);


    // Calls area() of Rectangle
    // 5.0 × 3.0 = 15.0
    std::cout << "Rectangle Area: "
              << rectangle.area()
              << '\n';


    // Calls area() of Circle
    // π × 2.0 × 2.0 ≈ 12.5664
    std::cout << "Circle Area: "
              << circle.area()
              << '\n';


    // Indicates successful completion of the program
    return 0;
}