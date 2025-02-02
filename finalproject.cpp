#include<iostream>
#include<iomanip>
#include<string>
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

