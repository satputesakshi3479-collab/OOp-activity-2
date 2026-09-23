#include <iostream>   // Includes the input and output library

// Defines a class named Number
class Number {
private:
    int value;   // Declares a private integer variable to store the number

public:
    // Constructor to initialize the value
    explicit Number(int givenValue) : value(givenValue) {
        // Assigns the given value to the value variable
    }

    // Overloads the unary minus (-) operator
    Number operator-() const {
        return Number(-value);   // Returns a new Number object with the negative value
    }

    // Function to display the value
    void display() const {
        std::cout << value << '\n';   // Prints the value on the screen
    }
};

// Main function
int main() {
    Number first(25);   // Creates a Number object with value 25

    Number second = -first;   // Applies the unary minus operator to first

    std::cout << "Original value: ";   // Displays the message for the original value
    first.display();                   // Displays the original value

    std::cout << "Negated value: ";    // Displays the message for the negated value
    second.display();                  // Displays the negated value

    return 0;   // Ends the program successfully
}