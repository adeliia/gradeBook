#include <iostream>
#include <string>
#include "gradebook.h"

using namespace std;


int main()
{
    string nameOfCourse;
    GradeBook myGradeBook("CS101 Programming in C++ and some more strings");

    cout << "Initial course name is: " << myGradeBook.getCourseName() << endl;

    //cout << "Please enter the name of the course:" << endl;
    //getline(cin, nameOfCourse);
    //myGradeBook.setCourseName(nameOfCourse);

    myGradeBook.displayMessage();
    myGradeBook.determineClassAverage();

    return 0;
}
