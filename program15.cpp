#include <iostream>   // Includes input and output library
#include <string>     // Includes string library

// Abstract base class
class Payment {
public:

    // Pure virtual function for making payment
    virtual void pay(double amount) const = 0;

    // Virtual destructor
    virtual ~Payment() = default;
};

// CardPayment class inherits from Payment
class CardPayment : public Payment {
public:

    // Overrides the pay function
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using card\n";
        // Displays card payment message
    }
};

// UpiPayment class inherits from Payment
class UpiPayment : public Payment {
public:

    // Overrides the pay function
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using UPI\n";
        // Displays UPI payment message
    }
};

// NetBankingPayment class inherits from Payment
class NetBankingPayment : public Payment {
public:

    // Overrides the pay function
    void pay(double amount) const override {
        std::cout << "Paid Rs. " << amount << " using net banking\n";
        // Displays net banking payment message
    }
};

// Function to process payment
void processPayment(const Payment& payment, double amount) {

    // Calls the appropriate pay function at runtime
    payment.pay(amount);
}

// Main function
int main() {

    // Creates a CardPayment object
    CardPayment card;

    // Creates a UpiPayment object
    UpiPayment upi;

    // Creates a NetBankingPayment object
    NetBankingPayment netBanking;

    // Processes card payment of Rs. 1250
    processPayment(card, 1250.0);

    // Processes UPI payment of Rs. 750
    processPayment(upi, 750.0);

    // Processes net banking payment of Rs. 500
    processPayment(netBanking, 500.0);

    return 0;   // Ends the program successfully
}