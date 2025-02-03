#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_COURSES = 10;


struct Course {
    string name;
    float grade;
    int units;
};



struct Student{
    string firstName;
    string lastName;
    string studentID;
    string major;

    float gpa;
    Course courses[MAX_COURSES];
    int courseCount;
};

void registerStudent(Student students[], int& studentCount){
    if(studentCount>= MAX_STUDENTS) {
        cout <<"Cannot register more students. Maximum limit reached.\n";
        return;
    }


    Student newStudent;
    cout << "Enter first name: ";
    cin >> newStudent.firstName;
    
    cout << "Enter last name: ";
    cin >> newStudent.lastName;
    
    cout << "Enter student ID: ";
    cin >> newStudent.studentID;
    
    cout << "Enter major: ";
    cin >> newStudent.major;
    
    newStudent.gpa = 0.0;
    newStudent.courseCount = 0;

    students[studentCount]= newStudent;
    studentCount++;
    cout << "Student registered successfully!\n"; }



void registerCourse (Student students[] , int studentCount){
    
    string studentID;
    cout << "Enter student ID: ";
    cin >> studentID;

    for (int i = 0; i<studentCount; i++){
        if (students[i].studentID == studentID){
            if (students[i].courseCount >= MAX_COURSES)  {
                
                cout << "Cannot register more courses. Maximum limit reached.\n";
                
                return;}
            

            Course newCourse;
            cout << "Enter course name: ";
            cin >> newCourse.name;
            
            cout << "Enter course grade: ";
            cin >> newCourse.grade;    
            cout << "Enter course units: ";
            cin >> newCourse.units;

            students[i].courses[students[i].courseCount] = newCourse;
            students[i].courseCount++;

            
            float totalGradePoints = 0.0;
            int totalUnits = 0;
            
            for (int j = 0; j < students[i].courseCount; j++) {
            
                totalGradePoints += students[i].courses[j].grade * students[i].courses[j].units;    
                totalUnits += students[i].courses[j].units;
            }
            
            students[i].gpa = (totalUnits > 0) ? (totalGradePoints / totalUnits) : 0.0;

            cout << "Course registered successfully!\n";
            return;
        }
        
    }
    
    cout << "Student not found!\n";
}




void listStudentsByMajor (const Student students[]  ,  int studentCount,  const string& major) {
    cout << "List of students in " << major << ":\n";
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].major == major) {
            
            cout << "Name: " << students[i].firstName << " " << students[i].lastName << ", ID: " << students[i].studentID << ", GPA: " << fixed << setprecision(2) << students[i].gpa << "\n";
            
        }
    }
}

void listAllStudents(const Student students[] , int studentCount) {
    cout << "List of all students:\n";
    
    for (int i = 0; i < studentCount; i++) {
        cout << "Name: " << students[i].firstName << " " << students[i].lastName
             << ", ID: " << students[i].studentID
             << ", Major: " << students[i].major
             << ", GPA: " << fixed << setprecision(2) << students[i].gpa << "\n";
    }

    
}



void issueReportCard(const Student students[], int studentCount) {
    string studentID;
    cout << "Enter student ID: ";
    cin >> studentID;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == studentID) {
            
            cout << "Report Card for " << students[i].firstName << " " << students[i].lastName << "\n";
            cout << "Student ID: " << students[i].studentID << "\n";
            cout << "Major: " << students[i].major << "\n";
            cout << "GPA: " << fixed << setprecision(2) << students[i].gpa << "\n";
            
            cout << "Courses:\n";
            
            for (int j = 0; j < students[i].courseCount; j++) {
                cout << students[i].courses[j].name << ": Grade = " << students[i].courses[j].grade
                     << ", Units = " << students[i].courses[j].units << "\n";
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
        outFile << students[i].firstName << " "
                << students[i].lastName << " "
                << students[i].studentID << " "
                << students[i].major << " "
                << students[i].gpa << " "
                << students[i].courseCount << "\n";

        
        for (int j = 0; j < students[i].courseCount; j++) {
        
            outFile << students[i].courses[j].name << " "
                    << students[i].courses[j].grade << " "
                    << students[i].courses[j].units << "\n";}
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
    while (inFile >> students[studentCount].firstName
                  >> students[studentCount].lastName
                  >> students[studentCount].studentID
                  >> students[studentCount].major
                  >> students[studentCount].gpa
                  >> students[studentCount].courseCount) {

        for (int j = 0; j < students[studentCount].courseCount; j++) {
            inFile >> students[studentCount].courses[j].name
                   >> students[studentCount].courses[j].grade
                   >> students[studentCount].courses[j].units;
        }

        studentCount++;
        if (studentCount >= MAX_STUDENTS) break;
    }

    inFile.close();
    cout << "Data loaded from file successfully!\n";
}

int main() {
    
    Student students[MAX_STUDENTS];
    
    int studentCount = 0;
    int choice;
    
    const string filename = "students_data.txt";

    loadDataFromFile(students, studentCount, filename);

    do {
        cout << "\n1. Register Student\n";
        cout << "2. Register Course\n";
        cout << "3. List Students by Major\n";
        cout << "4. List All Students\n";
        cout << "5. Issue Report Card\n";
        cout << "6. Save Data to File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        
            case 1:
                registerStudent(students, studentCount);
                break;
            
            case 2:
                registerCourse(students, studentCount);
                break;
            
            case 3: {
                string major;
                cout << "Enter major to filter by: ";
                cin >> major;
                listStudentsByMajor(students, studentCount, major);
                break;
            }
            case 4:
                listAllStudents(students, studentCount);
                break;
            case 5:
                issueReportCard(students, studentCount);
                break;
            case 6:
                saveDataToFile(students, studentCount, filename);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
