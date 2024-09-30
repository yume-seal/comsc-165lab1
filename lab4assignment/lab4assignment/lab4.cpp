/*
*  main.cpp
*  lab4assignment
*
*  Created by Sufyan Adam on 29/9/24.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <iomanip> //so we can use setw and stuff

#include <string>
using std::string;
using std::getline;

#include <fstream> //so we can do serialisation
using std::ofstream;
using std::ifstream;

#include <cstdlib> //for atoi and atof

#include <algorithm>
using std::sort;

//create the Course struct
struct Course
{
    string courseName;
    int units;
    int year;
    char grade;
};

void serialiseCoursesUp(Course courses[], int& size)
{
    ifstream fin;
    fin.open("courses.txt");
    
    while(fin.good())
    {
        string buffer;
        getline(cin, buffer);
        if(buffer == "EOF")
        {
            break;
        }
        else
        {
            courses[size].courseName = buffer;
            fin >> courses[size].units;
            fin.ignore(1000, 10);
            fin >> courses[size].year;
            fin.ignore(1000, 10);
            fin >> courses[size].grade;
            fin.ignore(1000, 10);
        }
    }
    
    fin.close();
}
Course cinOneCourse(int sqeuenceNumber)
{
    //declare a course object
    Course newCourse;
    cout << "Enter the name of the course (Press \"Q\" to quit): " << endl;
    getline(cin, newCourse.courseName);
    
    if(newCourse.courseName == "q" || newCourse.courseName == "Q")
    {
        return newCourse;
    }
    
    cout << "Enter the amount of units for the course: " << endl;
    string units;
    getline(cin, units);
    newCourse.units = atoi(units.c_str());
    
    cout << "Enter the year in which the course is taken: " << endl;
    string year;
    getline(cin, year);
    newCourse.year = atoi(year.c_str());
    
    cout << "Enter the grade received for this course (if the course is in progress or planned, enter '?'): " << endl;
    cin >> newCourse.grade;
    
    return newCourse;
}

int main()
{
    const int CAPACITY = 100; //max amount of courses in the array
    Course courses[CAPACITY];
    int size = 0; //array size
    courses[size] = cinOneCourse(0);
    size++;
    
    return 0;
}
