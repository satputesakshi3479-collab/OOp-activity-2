#include <iostream>   // Includes the input and output library

// Defines the base class Animal
class Animal {
public:
    // Virtual function to make a sound
    virtual void sound() const {
        std::cout << "Animal makes a sound\n";   // Prints the animal sound message
    }

    // Virtual destructor for safe destruction of derived objects
    virtual ~Animal() = default;
};

// Defines the Dog class that inherits from Animal
class Dog : public Animal {
public:
    // Overrides the sound function of the Animal class
    void sound() const override {
        std::cout << "Dog barks\n";   // Prints the dog sound
    }
};

// Defines the Cat class that inherits from Animal
class Cat : public Animal {
public:
    // Overrides the sound function of the Animal class
    void sound() const override {
        std::cout << "Cat meows\n";   // Prints the cat sound
    }
};

// Main function
int main() {
    Dog dog;   // Creates a Dog object
    Cat cat;   // Creates a Cat object

    Animal* animal = &dog;   // Base class pointer points to the Dog object
    animal->sound();         // Calls Dog's sound function using virtual function

    animal = &cat;           // Base class pointer now points to the Cat object
    animal->sound();         // Calls Cat's sound function using virtual function

    return 0;   // Ends the program successfully
}