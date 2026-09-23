#include <iostream>   // Includes the input and output library

// Function to add two integers
int add(int first, int second) {   // Defines a function that takes two integers
    return first + second;         // Returns the sum of the two integers
}

// Function to add two double values
double add(double first, double second) {   // Defines a function that takes two double values
    return first + second;                 // Returns the sum of the two double values
}

// Function to add three integers
int add(int first, int second, int third) {   // Defines a function that takes three integers
    return first + second + third;            // Returns the sum of the three integers
}

// Main function
int main() {   // Program execution starts from the main function

    // Calls the add function with two integers
    std::cout << "Sum of two integers: " << add(10, 20) << '\n';   // Displays the sum of 10 and 20

    // Calls the add function with two double values
    std::cout << "Sum of two doubles: " << add(2.5, 3.7) << '\n';   // Displays the sum of 2.5 and 3.7

    // Calls the add function with three integers
    std::cout << "Sum of three integers: " << add(10, 20, 30) << '\n';   // Displays the sum of 10, 20, and 30

    return 0;   // Ends the program successfully
}

// Compiled By - Mr. Chandan Prasad