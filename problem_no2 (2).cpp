#include <iostream>      // Header file for input and output operations like cout and endl
#include <memory>        // Header file for smart pointers like unique_ptr and make_unique
#include <string>        // Header file for using the string data type
#include <vector>        // Header file for using the vector container
using namespace std;     // Allows us to use cout, string, vector, etc. without std::

class PaymentMethod // parent or base class
{
protected: //access specifier
    string transactionId;    // Stores the transaction ID
    double amount;           // Stores the payment amount

public: //access specifier

    // Constructor of PaymentMethod class
    PaymentMethod(string tid, double amt)
        : transactionId(tid),     // Initializes transactionId with tid
          amount(amt)              // Initializes amount with amt
    {
    }

    // Pure virtual function
    // Every derived payment class must implement this function
    virtual bool processPayment() const = 0;

    // Virtual destructor
    // Ensures proper destruction of derived class objects
    virtual ~PaymentMethod() = default;
};


class CreditCardPayment : public PaymentMethod //child class or derived class
{
    // CreditCardPayment publicly inherits from PaymentMethod

private:  //access specifier
    string maskedCardNumber;     // Stores the masked credit card number

public: //access specifier

    // Constructor of CreditCardPayment
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt),       // Calls PaymentMethod constructor
          maskedCardNumber(card)         // Initializes maskedCardNumber
    {
    }

    // Overrides the pure virtual function of PaymentMethod
    bool processPayment() const override
    {
        // Displays credit card transaction details
        cout << "Credit-card transaction " << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;

        // Returns true indicating successful payment
        return true;
    }
};

class UPIPayment : public PaymentMethod //child  class
{
private: //access specifier
    string upiId;       // Stores the UPI ID

public:  //access specifier

    // Constructor of UPIPayment
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt),       // Calls PaymentMethod constructor
          upiId(upi)                     // Initializes upiId
    {
    }

    // Overrides the pure virtual function
    bool processPayment() const override
    {
        // Displays UPI transaction details
        cout << "UPI transaction " << transactionId
             << " for Rs. " << amount
             << " from " << upiId
             << " completed." << endl;

        // Returns true indicating successful payment
        return true;
    }
};

class NetBankingPayment : public PaymentMethod // child class
{
private: //access specifier
    string bankName;       // Stores the name of the bank

public:  //access specifier

    // Constructor of NetBankingPayment
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt),       // Calls PaymentMethod constructor
          bankName(bank)                 // Initializes bankName
    {
    }

    // Overrides the pure virtual function
    bool processPayment() const override
    {
        // Displays net-banking transaction details
        cout << "Net-banking transaction " << transactionId
             << " for Rs. " << amount
             << " through " << bankName
             << " completed." << endl;

        // Returns true indicating successful payment
        return true;
    }
};

int main()
{
    // Creates a vector that stores unique pointers
    // to PaymentMethod objects
    vector<unique_ptr<PaymentMethod>> payments;


    // Creates a CreditCardPayment object dynamically
    // and stores it inside the payments vector
    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001",                  // Transaction ID
            2500,                      // Payment amount
            "XXXX-XXXX-1234"           // Masked card number
        )
    );


    // Creates a UPIPayment object and stores it in the vector
    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002",                  // Transaction ID
            1200,                      // Payment amount
            "student@upi"              // UPI ID
        )
    );


    // Creates a NetBankingPayment object and stores it in the vector
    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003",                  // Transaction ID
            5000,                      // Payment amount
            "Example Bank"             // Bank name
        )
    );


    // Displays the heading
    cout << "=== Payment Gateway ===" << endl;


    // Loops through every payment stored in the vector
    for (const auto& payment : payments)
    {
        // Calls the appropriate processPayment() function
        // depending on the actual object type
        payment->processPayment();
    }


    // Indicates successful completion of the program
    return 0;
}