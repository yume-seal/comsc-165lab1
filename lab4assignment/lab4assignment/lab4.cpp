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

void serialiseCoursesDown(Course courses[], int& size)
{
    ofstream fout;
    fout.open("courses.txt", ios::app);
    
    for(int i = 0; i < size; i++)
    {
        fout << courses[i].courseName << endl;
        fout << courses[i].units << endl;
        fout << courses[i].year << endl;
        fout << courses[i].grade << endl;
        fout << "EOF";
    }
}
void serialiseCoursesUp(Course courses[], int& size)
{
    ifstream fin;
    fin.open("courses.txt");
    
    if(!fin)
    {
        cout << "This file does not exist!" << endl;
    }
    
    while(fin.good())
    {
        string buffer;
        getline(fin, buffer);
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
    string courseName;
    getline(cin, courseName);
    
    if(courseName == "q" || courseName == "Q")
    {
        return newCourse;
    }
    else
    {
        newCourse.courseName = courseName;
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
    
    serialiseCoursesUp(courses, size);
    courses[size] = cinOneCourse(0);
    size++;
    
    serialiseCoursesDown(courses, size);
    return 0;
}
