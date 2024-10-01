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
using std::setw;
using std::setfill;
using std::left;
using std::right;

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
    fout.open("courses.txt");
    
    for(int i = 0; i <= size; i++)
    {
        if(!courses[i].courseName.empty())
        {
            fout << courses[i].courseName << endl;
            fout << courses[i].units << endl;
            fout << courses[i].year << endl;
            fout << courses[i].grade << endl;
        }
    }
}
void serialiseCoursesUp(Course courses[], int& size)
{
    size = 0;
    ifstream fin;
    fin.open("courses.txt");
    
    if(!fin)
    {
        cout << "This file does not exist!" << endl;
    }
    
    while(fin.good() && !fin.eof())
    {
        string buffer;
        getline(fin, buffer);
        if(buffer.empty())
        {
            break;
        }
        courses[size].courseName = buffer;
        fin >> courses[size].units;
        fin.ignore(1000, 10);
        fin >> courses[size].year;
        fin.ignore(1000, 10);
        fin >> courses[size].grade;
        fin.ignore(1000, 10);
        size++;
    }
    
    fin.close();
}

Course cinOneCourse(int sequenceNumber)
{
    //declare a course object
    Course newCourse;
    cout << "Enter the name of course #" << sequenceNumber << "(Press \"Q\" to quit): " << endl;
    string courseName;
    getline(cin, courseName);
    
    if(courseName == "q" || courseName == "Q")
    {
        
        return newCourse;
    }

    newCourse.courseName = courseName;
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
    cin.ignore(1000, 10);
    
    return newCourse;
}

void coutAllCourses(Course courses[], int& size)
{
    cout << left << setw(20) << "Course";
    cout << left << setw(6) << "Year";
    cout << setw(8) << "Units";
    cout << setw(7) << "Grade" << endl;
    cout << setw(41) << setfill('-') << "" << setfill(' ') << endl;
    
    for(int i = 0; i <= size; i++)
    {
        if(!courses[i].courseName.empty())
        {
            cout << left << setw(20) << courses[i].courseName;
            cout << left << setw(6) << courses[i].year;
            cout << setw(8) << courses[i].units;
            cout << setw(7) << courses[i].grade << endl;
            cout << setw(41) << setfill('-') << "" << setfill(' ') << endl;
        }
    }
}
int main()
{
    const int CAPACITY = 100; //max amount of courses in the array
    Course courses[CAPACITY];
    int size = 0; //array size
    serialiseCoursesUp(courses, size);
    coutAllCourses(courses, size);
    for(int counter = 0; counter < CAPACITY; counter++)
    {
        Course newCourse = cinOneCourse(size + 1);
        
        if(newCourse.courseName.empty())
        {
            break;
        }
        else
        {
            courses[size] = newCourse;
            coutAllCourses(courses, size);
            size++;
        }
        
    }
    
    serialiseCoursesDown(courses, size);
    
    return 0;
}
