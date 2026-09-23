#include <iostream>                  // Includes the input/output library

class Base {                         // Defines the base class
public:                              // Public access specifier

    void show() const {              // Defines a public function named show()
        std::cout << "Base public function\n";  // Prints a message
    }
};

class PublicDerived : public Base {  // PublicDerived publicly inherits from Base
};                                  // No additional members in PublicDerived

class PrivateDerived : private Base { // PrivateDerived privately inherits from Base
public:                               // Public access specifier

    void callBaseShow() const {       // Defines a function to call Base's show()
        show();                       // Calls the inherited show() function
    }
};

int main() {                          // Main function; program execution starts here

    PublicDerived publicObject;       // Creates an object of PublicDerived

    publicObject.show();              // Calls Base's public show() through public inheritance

    PrivateDerived privateObject;     // Creates an object of PrivateDerived

    privateObject.callBaseShow();     // Calls callBaseShow(), which internally calls show()

    privateObject.show();             // ERROR: show() is private due to private inheritance

    return 0;                         // Ends the program successfully
}