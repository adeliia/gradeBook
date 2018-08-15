#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <iostream>

using namespace std;

class GradeBook {
    public:
        const static int students = 10;

        GradeBook(string name, const int []);

        void setCourseName(string name);
        string getCourseName();
        void displayMessage();
        void processGrades();
        int getMinimum();
        int getMaximum();
        double getAverage();
        void outputBarChart();
        void outputGrades();
    private:
        string courseName;
        int grades [students];
};

#endif // GRADEBOOK_H
