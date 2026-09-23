#include <iostream>   // Includes the input and output library

// Defines a class named Counter
class Counter {
private:
    int value;   // Stores the current counter value

public:
    // Constructor to initialize the counter
    explicit Counter(int initialValue = 0) : value(initialValue) {
        // Assigns the initial value to the counter
    }

    // Overloads the prefix increment operator (++counter)
    Counter& operator++() {
        ++value;       // Increases the value by 1
        return *this;  // Returns the current object
    }

    // Overloads the postfix increment operator (counter++)
    Counter operator++(int) {
        Counter old = *this;   // Stores the current value before incrementing
        ++value;               // Increases the value by 1
        return old;            // Returns the old value
    }

    // Function to display the counter value
    void display() const {
        std::cout << value << '\n';   // Prints the current value
    }
};

// Main function
int main() {
    Counter counter(5);   // Creates a Counter object with initial value 5

    std::cout << "After prefix increment: ";   // Displays the prefix increment message
    ++counter;                                   // Increases the counter before using its value
    counter.display();                          // Displays the updated value

    std::cout << "Value returned by postfix increment: ";   // Displays the postfix message
    Counter oldValue = counter++;   // Stores the old value and then increases the counter

    oldValue.display();   // Displays the value returned by postfix increment

    std::cout << "Counter after postfix increment: ";   // Displays the current counter message
    counter.display();                                    // Displays the updated counter value

    return 0;   // Ends the program successfully
}