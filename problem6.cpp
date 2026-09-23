#include <iostream>   // Includes the input and output library

// Defines a class named Distance
class Distance {
private:
    int meters;   // Stores the distance in meters

public:
    // Constructor to initialize the distance
    explicit Distance(int value) : meters(value) {
        // Assigns the given value to meters
    }

    // Overloads the greater-than (>) operator
    bool operator>(const Distance& other) const {
        return meters > other.meters;   // Compares the two distances
    }

    // Function to display the distance
    void display() const {
        std::cout << meters << " meters\n";   // Prints the distance in meters
    }
};

// Main function
int main() {
    Distance first(120);   // Creates the first Distance object with 120 meters

    Distance second(90);   // Creates the second Distance object with 90 meters

    std::cout << "First distance: ";   // Displays the first distance message
    first.display();                   // Displays the first distance

    std::cout << "Second distance: ";  // Displays the second distance message
    second.display();                 // Displays the second distance

    // Compares the two distances using the overloaded > operator
    if (first > second) {
        std::cout << "First distance is greater\n";   // Displays this if first is greater
    } else {
        std::cout << "Second distance is greater or equal\n";   // Displays this if second is greater or equal
    }

    return 0;   // Ends the program successfully
}