#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    float grade;
    int creditHours;
};

int main() {
    int numCourses;
    vector<Course> courses;

    cout << "Enter the number of courses taken: ";
    cin >> numCourses;

    float totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < numCourses; ++i) {
        Course c;
        cout << "\nEnter course name: ";
        cin >> ws; // clear input buffer
        getline(cin, c.name);
        cout << "Enter grade for " << c.name << " (on 10-point scale): ";
        cin >> c.grade;
        cout << "Enter credit hours for " << c.name << ": ";
        cin >> c.creditHours;

        courses.push_back(c);
        totalCredits += c.creditHours;
        totalGradePoints += c.grade * c.creditHours;
    }

    float CGPA = totalGradePoints / totalCredits;

    cout << "\n--------------------------------------------\n";
    cout << "Course Grades:\n";
    cout << left << setw(20) << "Course Name" << setw(10) << "Grade" << setw(15) << "Credit Hours" << endl;
    cout << "--------------------------------------------\n";

    for (const auto& c : courses) {
        cout << left << setw(20) << c.name << setw(10) << c.grade << setw(15) << c.creditHours << endl;
    }

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << fixed << setprecision(2) << CGPA << endl;

    return 0;
}
