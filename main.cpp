#include <iostream>
#include <string>
#include "gradebook.h"

using namespace std;


int main()
{
    //GradeBook::students reffer to the static const value
    int gradesArray[GradeBook::students]
            = { 87, 68, 94, 100, 83, 78, 85, 91, 76, 87};

    GradeBook myGradeBook("CS101 Programming in C++", gradesArray);

    myGradeBook.displayMessage();
    myGradeBook.processGrades();

    return 0;
}
