#include <iostream>   // Includes the input and output library

// Defines a class named Complex
class Complex {
private:
    int real;        // Stores the real part of the complex number
    int imaginary;  // Stores the imaginary part of the complex number

public:
    // Constructor to initialize the complex number
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {
        // Initializes real and imaginary values
    }

    // Overloads the + operator for adding two complex numbers
    Complex operator+(const Complex& other) const {
        // Adds the real parts and imaginary parts of two complex numbers
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Function to display the complex number
    void display() const {
        std::cout << real;   // Displays the real part

        if (imaginary >= 0) {   // Checks if the imaginary part is positive or zero
            std::cout << " + ";   // Displays the plus sign
        } else {
            std::cout << " - ";   // Displays the minus sign
        }

        // Displays the absolute value of the imaginary part followed by i
        std::cout << (imaginary >= 0 ? imaginary : -imaginary) << "i\n";
    }
};

// Main function
int main() {
    Complex first(2, 3);   // Creates the first complex number: 2 + 3i

    Complex second(4, 5);   // Creates the second complex number: 4 + 5i

    Complex sum = first + second;   // Adds the two complex numbers using overloaded + operator

    std::cout << "First complex number: ";   // Displays the first number message
    first.display();                         // Displays the first complex number

    std::cout << "Second complex number: ";  // Displays the second number message
    second.display();                        // Displays the second complex number

    std::cout << "Sum: ";   // Displays the sum message
    sum.display();          // Displays the sum of the two complex numbers

    return 0;   // Ends the program successfully
}