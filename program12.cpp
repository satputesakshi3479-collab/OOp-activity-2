#include <iostream>   // Includes input and output library
#include <memory>     // Provides smart pointers like unique_ptr
#include <vector>     // Provides vector container

// Abstract base class
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double area() const = 0;

    // Pure virtual function to display shape name
    virtual void displayName() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

// Rectangle class inherits from Shape
class Rectangle : public Shape {
private:
    double length;   // Stores length of rectangle
    double width;    // Stores width of rectangle

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Overrides the area function of Shape
    double area() const override {
        return length * width;   // Returns rectangle area
    }

    // Overrides the displayName function
    void displayName() const override {
        std::cout << "Rectangle";   // Displays shape name
    }
};

// Circle class inherits from Shape
class Circle : public Shape {
private:
    double radius;   // Stores radius of circle

public:
    // Constructor to initialize radius
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}

    // Overrides the area function of Shape
    double area() const override {
        constexpr double PI = 3.141592653589793;   // Stores value of PI
        return PI * radius * radius;                // Returns circle area
    }

    // Overrides the displayName function
    void displayName() const override {
        std::cout << "Circle";   // Displays shape name
    }
};

// Main function
int main() {

    // Creates a vector to store Shape smart pointers
    std::vector<std::unique_ptr<Shape>> shapes;

    // Creates Rectangle object and adds it to the vector
    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));

    // Creates Circle object and adds it to the vector
    shapes.push_back(std::make_unique<Circle>(2.0));

    // Loops through all shapes in the vector
    for (const auto& shape : shapes) {

        // Displays the name of the shape
        shape->displayName();

        // Calculates and displays the area
        std::cout << " Area: " << shape->area() << '\n';
    }

    return 0;   // Ends the program successfully
}