#include <iostream>   // Header file for input/output operations like cout


/* ===================== ACCOUNT CLASS ===================== */

class Account
{
private:
    double balance;   // Stores the account balance
                      // This is a private data member


    // Declares Auditor as a friend class
    // This allows Auditor to access private members of Account
    friend class Auditor;


public:

    // Constructor of Account class
    explicit Account(double initialBalance)
        : balance(initialBalance)
    {
        // Initializes balance with the given initialBalance
    }
};


/* ===================== AUDITOR CLASS ===================== */

class Auditor
{
public:

    // Function to inspect an Account object
    // const Account& means the account is passed by reference
    // and cannot be modified inside this function
    void inspect(const Account& account) const
    {
        // Accesses the private member 'balance' of Account
        // This is allowed because Auditor is a friend of Account
        std::cout << "Account Balance: "
                  << account.balance
                  << '\n';
    }
};


/* ===================== MAIN FUNCTION ===================== */

int main()
{
    // Creates an Account object
    // Initial balance is 5000.0
    Account account(5000.0);

    // Creates an Auditor object
    Auditor auditor;


    // Calls the inspect() function of Auditor
    // and passes the Account object to it
    auditor.inspect(account);


    // Indicates successful completion of the program
    return 0;
}