#include<iostream>
#include<iomanip>
#include <string>
#include <fstream>
using namespace std;

const int max_stu = 50;
const int max_cour = 10;


struct Student{

    string firstname;
    string lastname;
    string studentID;
    
    string major;
    float avg;
    string courses[max_cour];
    string grades[max_cour];
    int courseCount;

};

void registerStudent(Student students[], int &studentCount) {
    if (studentCount>= max_stu){
        cout <<"No more registerstion capacity. limit has reached";
        return; }

    Student newStudent;
    cout << "Enter first name: ";
    cin >> newStudent.firstname;
    cout << "Enter last name: ";
    cin >> newStudent.lastname;
    cout << "Enter student ID: ";
    cin >> newStudent.studentID;
    cout << "Enter magor: ";
    cin >> newStudent.major;
    newStudent.avg = 0.0;
    newStudent.courseCount = 0;

    students[studentCount] = newStudent ;
    studentCount++;
    cout << "Student registered successfully!\n";

}

void registerCourse(Student students[], int studentCount) {
    string studentID;
    cout << "Enter student ID: ";
    cin >> studentID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {

            if (students[i].courseCount >= max_cour) {
                cout << "Cannot register more courses. Maximum limit reached.\n";
                return;
                
            }

            string courseName;
            double grade;
            cout << "Enter course name: ";
            cin >> courseName;
            cout << "Enter grade: ";
            cin >> grade;

            students[i].courses[students[i].courseCount] = courseName;
            students[i].grades[students[i].courseCount] = grade;
            students[i].courseCount++;

            double total = 0.0;
            for (int j = 0; j < students[i].courseCount; j++) {
                total+= students[i].grades[j];
            }
            students[i].avg = total / students[i].courseCount;

            cout << "Course registered successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void listStudentsByMajor(const Student students[], int studentCount, const string& major) {
    cout << "List of students in " << major << ":\n";
    for (int i = 0; i < studentCount; i++) {
        if (students[i].major == major) {
            cout << "Name: " << students[i].firstname << " " << students[i].lastname
                 << ", ID: " << students[i].studentID
                 << ", avg: " << fixed << setprecision(2) << students[i].avg << "\n";
        }
    }
}


void listAllStudents(const Student students[], int studentCount){
    cout << "List of all students:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "Name: " << students[i].firstname <<" "<< students[i].lastname
             <<", ID: "<< students[i].studentID
             << ", Major: " << students[i].major
             << ", avg: " << fixed << setprecision(2) << students[i].avg << "\n";
    }
}




void issueReportCard(const Student students[], int studentCount) {
    string studentID;
    cout << "Enter student ID: ";
    cin >> studentID;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {
            cout << "Report Card for " << students[i].firstname << " " << students[i].lastname << "\n";
            cout << "Student ID: " << students[i].studentID << "\n";
            cout << "Major: " << students[i].major << "\n";
            cout << "avg: " << fixed << setprecision(2) << students[i].avg << "\n";
            cout << "Courses:\n";
            for (int j = 0; j < students[i].courseCount; j++) {
                cout << students[i].courses[j] << ": " << students[i].grades[j] << "\n";
            }
            return;
        }
    }
    cout << "Student not found!\n";
}


void saveDataToFile(const Student students[], int studentCount, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        outFile << students[i].firstname << " "
                << students[i].lastname << " "
                << students[i].studentID << " "
                << students[i].major << " "
                << students[i].avg << " "
                << students[i].courseCount << "\n";

        for (int j = 0; j < students[i].courseCount; j++) {
            outFile << students[i].courses[j] << " " << students[i].grades[j] << "\n";
        }
    }

    outFile.close();
    cout << "Data saved to file successfully!\n";
}

void loadDataFromFile(Student students[], int& studentCount, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    studentCount = 0;
    while (inFile >> students[studentCount].firstname
                  >> students[studentCount].lastname
                  >> students[studentCount].studentID
                  >> students[studentCount].major
                  >> students[studentCount].avg
                  >> students[studentCount].courseCount) {

        for (int j = 0; j < students[studentCount].courseCount; j++) {
            inFile >> students[studentCount].courses[j] >> students[studentCount].grades[j];
        }

        studentCount++;
        if (studentCount >= max_stu) break;
    }

    inFile.close();
    cout << "Data loaded from file successfully!\n";
}


int main(){


    Student students[max_stu];

    int choice;
    

}

