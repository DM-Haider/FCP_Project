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

int main(){


    Student students[max_stu];

    int choice;

}