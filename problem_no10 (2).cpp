#include <iostream>                         // Includes input/output functions like cout

class Academic {                            // Defines the Academic class

protected:                                  // Protected members can be accessed by derived classes
    int academicMarks;                      // Stores academic marks

public:                                     // Public members can be accessed from outside the class

    explicit Academic(int marks)            // Constructor of Academic class
        : academicMarks(marks) {}           // Initializes academicMarks with marks

    void showAcademic() const {             // Function to display academic marks
        std::cout << "Academic Marks: "     // Prints the label
                  << academicMarks << '\n'; // Prints academic marks
    }
};

class Sports {                              // Defines the Sports class

protected:                                  // Protected members can be accessed by derived classes
    int sportsMarks;                        // Stores sports marks

public:                                     // Public members

    explicit Sports(int marks)              // Constructor of Sports class
        : sportsMarks(marks) {}             // Initializes sportsMarks with marks

    void showSports() const {               // Function to display sports marks
        std::cout << "Sports Marks: "       // Prints the label
                  << sportsMarks << '\n';   // Prints sports marks
    }
};

class Student : public Academic, public Sports { // Student inherits from both Academic and Sports

public:                                         // Public members

    Student(int academic, int sports)           // Constructor of Student class
        : Academic(academic),                   // Calls Academic constructor
          Sports(sports) {}                     // Calls Sports constructor

    void showTotal() const {                    // Function to display total marks
        std::cout << "Total Marks: "            // Prints the label
                  << academicMarks + sportsMarks // Adds academic and sports marks
                  << '\n';                      // Moves to the next line
    }
};

int main() {                                    // Main function; execution starts here

    Student student(80, 15);                    // Creates Student object with 80 academic and 15 sports marks

    student.showAcademic();                     // Calls showAcademic() function

    student.showSports();                       // Calls showSports() function

    student.showTotal();                        // Calls showTotal() function

    return 0;                                   // Ends the program successfully
}