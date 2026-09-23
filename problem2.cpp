#include <iostream>   // Includes the input and output library

// Function to calculate the area of a square
int calculateArea(int side) {   // Defines a function that takes the side of a square
    return side * side;         // Returns the area of the square
}

// Function to calculate the area of a rectangle
int calculateArea(int length, int width) {   // Defines a function that takes length and width
    return length * width;                  // Returns the area of the rectangle
}

// Function to calculate the area of a circle
double calculateArea(double radius) {   // Defines a function that takes the radius of a circle
    constexpr double PI = 3.141592653589793;   // Defines the constant value of PI
    return PI * radius * radius;               // Returns the area of the circle
}

// Main function
int main() {   // Program execution starts from the main function

    // Calls the function for square area
    std::cout << "Square Area: " << calculateArea(5) << '\n';   // Displays the area of a square with side 5

    // Calls the function for rectangle area
    std::cout << "Rectangle Area: " << calculateArea(6, 4) << '\n';   // Displays the area of a rectangle with length 6 and width 4

    // Calls the function for circle area
    std::cout << "Circle Area: " << calculateArea(2.0) << '\n';   // Displays the area of a circle with radius 2

    return 0;   // Ends the program successfully
}