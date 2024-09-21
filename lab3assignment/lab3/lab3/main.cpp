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
    cin >> buf; someStudent.gpa = atoi(buf.c_str());
    
    return someStudent;
}

void outputStudent()
{
    
}

int main()
{
    inputStudent();
    return 0;
}
