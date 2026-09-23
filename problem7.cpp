#include <iostream>   // Includes the input and output library

// Defines a class named Complex
class Complex {
private:
    int real;        // Stores the real part of the complex number
    int imaginary;   // Stores the imaginary part of the complex number

public:
    // Constructor to initialize the complex number
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {
        // Initializes the real and imaginary values
    }

    // Declares a friend function to overload the + operator
    friend Complex operator+(int value, const Complex& number);

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

// Defines the friend function to add an integer and a Complex object
Complex operator+(int value, const Complex& number) {
    // Adds the integer to the real part and keeps the imaginary part unchanged
    return Complex(value + number.real, number.imaginary);
}

// Main function
int main() {
    Complex number(2, 3);   // Creates a Complex object with value 2 + 3i

    Complex result = 10 + number;   // Adds 10 to the complex number using the overloaded + operator

    std::cout << "Result: ";   // Displays the result message
    result.display();          // Displays the resulting complex number

    return 0;   // Ends the program successfully
}