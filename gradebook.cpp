#include <iostream>
#include <iomanip>
using namespace std;

#include "gradebook.h"

GradeBook::GradeBook(string name, const int gradesArray[]){
    setCourseName(name);

    // copy from the input so all methods of the class
    //had access to the array
    for (int grade = 0; grade < students; grade++)
        grades[grade] = gradesArray[grade];
}

void GradeBook::setCourseName(string name){
    if(name.length() <= 25)
        courseName = name;
    else {
        courseName = name.substr(0,25);

        cout << "Name \"" << name << "\" exceeds maximum length.\n"
             << "Limitting courseName to first 25 characters.\n" << endl;
    }
}

string GradeBook::getCourseName(){
    return courseName;
}

void GradeBook::displayMessage(){
    cout << "Welcome to the Grade book for\n" << courseName << "!\n";
}

void GradeBook::processGrades(){
    outputGrades();

    cout << "\nClass average is " << setprecision(2)
         << fixed << getAverage() << endl;

    cout << "The lowest grade is " << getMinimum() <<
            "\nThe highest grade is " << getMaximum() << endl;

    outputBarChart();
}

int GradeBook::getMinimum(){
    int lowGrade = 100;

    for (int grade = 0; grade < students; grade++) {
        if (grades[grade] < lowGrade)
            lowGrade = grades[grade];
    }
    return lowGrade;
}

int GradeBook::getMaximum(){
    int highGrade = 0;

    for (int grade=0; grade < students; grade++) {
        if (grades[grade] > highGrade)
            highGrade = grades[grade];
    }
    return highGrade;
}

double GradeBook::getAverage(){
    int total = 0;

    for (int grade = 0; grade < students; grade++ ) {
        total += grades[grade];
    }

    return static_cast <double> (total) / students;
}

void GradeBook::outputBarChart(){
    cout << "\nGrades distribution: " << endl;

    const int frequencySize = 11;
    int frequency[frequencySize] = {0};

    for (int grade = 0; grade < students; grade++) {
        frequency[grades[grade]/10]++;
    }

    for (int count=0; count < frequencySize; count++) {
        if (count==0)
            cout << "  0-9: ";
        else if (count == 10)
            cout << "  100: ";
        else
            cout << count * 10 << "-" << (count * 10) + 9 << ": ";

        for (int stars = 0; stars < frequency[count]; stars++) {
            cout << "*";
        }
        cout << endl;
    }
}

void GradeBook::outputGrades(){
    cout << "\nThe grades are:" << endl;

    for (int student =0; student < students; student++) {
        cout << "Student " << setw(2) << student + 1 << ": "
             << setw(3) << grades[student] << endl;
    }
}


