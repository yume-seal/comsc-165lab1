//
//  main.cpp
//  lab3
//
//  Created by Sufyan Adam on 20/9/24.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;
using std::getline;

#include <iomanip>

struct Student
{
    string name;
    string city;
    int age;
    int classRank;
    float gpa;
};

Student inputStudent()
{
    string buf;
    //create a student object
    Student someStudent;
    
    //Ask the user for the Student's name
    cout << "Enter the name of the Student: ";
    
    //Store the student's name in the student object
    getline(cin, someStudent.name);
    
    //Ask the user for the Student's city
    cout << "\nEnter the name of the Student's city: ";
    
    //Store the city in the student object
    getline(cin, someStudent.city);
    
    //Ask the user for the Student's age
    cout << "\nEnter the Student's age: ";
    
    //Store the age in the student object
    cin >> buf; someStudent.age = atoi(buf.c_str());
    
    //Ask the user for the Student's class rank
    cout << "\nEnter the Student's class rank: ";
    
    //Store the class rank in the student object
    cin >> buf; someStudent.classRank = atoi(buf.c_str());
    
    //Ask the user for the Student's gpa
    cout << "\nEnter the Student's gpa: ";
    
    //Store the gpa in the student object
    cin >> buf; someStudent.gpa = atof(buf.c_str());
    cin.ignore(INT_MAX, '\n');
    
    return someStudent;
}


void outputStudent(Student student)
{
    cout << "" << std::setw(20) << std::left << student.name;
    cout << "" << std::setw(15) << std::setfill(' ') << student.city;
    cout << "" << std::setw(7) << std::setfill(' ') << student.age;
    cout << "" << std::setw(15) << student.classRank;
    cout << "" << std::setw(7) << student.gpa << "\n";
    cout << std::setw(0) << std::setfill('-') << std::setw(64) << std::left << "" << std::setfill(' ') << endl;
}

int main()
{
    Student student1 = inputStudent();
    Student student2 = inputStudent();
    //Student student3 = inputStudent();
    
    cout << std::setw(20) << std::left << "Name";
    cout << std::setw(15) << std::left << "City";
    cout << std::setw(7) << "Age";
    cout << std::setw(15) << "Class Rank";
    cout << std::setw(7) << "GPA" << "\n";
    cout << std::setw(0) << std::setfill('-') << std::setw(64) << "" << std::setfill(' ') << endl;
    
    outputStudent(student1);
    outputStudent(student2);
    return 0;
}
