/*
*  Name: Madeeha Adam
*  Assignment: Lab 4 - Read and Write Course Objects Using a Text File
*  Compiler used: Xcode
*  Description: This program allows the user to keep track of all their courses by allowing them to enter their courses and then view them in a table. It also saves the user entered course information to a text file and then loads it into the table when the
    user runs the program again.
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

/* This function saves the user input to a file.
 Parameters: Array of Course objects (IN)
             Integer value (IN) that represents the amount of valid
             elements in the array of course objects.
 Return: NONE
 */
void serialiseCoursesDown(Course courses[], int& size)
{
    ofstream fout; //create ofstream object to write to the file
    fout.open("courses.txt");
    
    //add all the course objects in the size of the array to the file
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

/* This function reads the saved user input from the file
 Parameters: Array of course objects (IN)
             Integer value (IN) that represents the amount of valid elements in
             the array of course objects
 Return: NONE
 */
void serialiseCoursesUp(Course courses[], int& size)
{
    //reset the size to 0
    size = 0;
    ifstream fin; //create an ifstream object to read the file
    fin.open("courses.txt");
    
    if(!fin) //check if the file is existing
    {
        cout << "This file does not exist!" << endl;
    }
    
    while(fin.good() && !fin.eof()) //make sure we can read the file
    {
        string buffer;
        getline(fin, buffer);
        
        //be extra sure that we are not reading empty lines
        if(buffer.empty())
        {
            break;
        }
        
        //if we are not reading empty lines, put the information from the file into the course object in the array starting from index 0
        courses[size].courseName = buffer;
        fin >> courses[size].units;
        fin.ignore(1000, 10);
        fin >> courses[size].year;
        fin.ignore(1000, 10);
        fin >> courses[size].grade;
        fin.ignore(1000, 10);
        size++; //increment the size of the array so we don't overwrite the first course object if there are more than one course object in the file
    }
    
    fin.close(); //close the file
}

/* This function creates an empty course object and then prompts the user to fill it in
 Parameters: integer value (IN) that represents the course's # (for example course #1, #2 etc)
 Return: course object filled in with user entered values*/
Course cinOneCourse(int sequenceNumber)
{
    //declare a course object
    Course newCourse;
    //promt user for the name of the course
    cout << "Enter the name of course #" << sequenceNumber << "(Press \"Q\" to quit): " << endl;
    string courseName;
    getline(cin, courseName); //put the user input in courseName
    
    //if the user pressed Q, return an empty (invalid) course object
    if(courseName == "q" || courseName == "Q")
    {
        
        return newCourse;
    }

    //put the user input into the course object if they did not press Q
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

/* This function prints the course objects the user enters.
 Parameters: Array of course objects (IN)
             Integer value that tells the amount of valid elements in the array
 Return: NONE */
void coutAllCourses(Course courses[], int& size)
{
    //print the table header
    cout << left << setw(20) << "Course";
    cout << left << setw(6) << "Year";
    cout << setw(8) << "Units";
    cout << setw(7) << "Grade" << endl;
    cout << setw(41) << setfill('-') << "" << setfill(' ') << endl; //to make the rows of the table
    
    //print all the valid course objects in the array
    for(int i = 0; i <= size; i++)
    {
        if(!courses[i].courseName.empty()) //make sure not to print an empty course
        {
            cout << left << setw(20) << courses[i].courseName;
            cout << left << setw(6) << courses[i].year;
            cout << setw(8) << courses[i].units;
            cout << setw(7) << courses[i].grade << endl;
            cout << setw(41) << setfill('-') << "" << setfill(' ') << endl;
        }
    }
}

/* This is the main function*/
int main()
{
    const int CAPACITY = 100; //max amount of courses in the array
    Course courses[CAPACITY];
    int size = 0; //array size
    serialiseCoursesUp(courses, size); //if there are any saved courses, restore them
    coutAllCourses(courses, size); //print the saved courses
    
    //Allow the user to fill the array with the amount of course objects less than the capacity of the array.
    for(int counter = 0; counter < CAPACITY; counter++)
    {
        //create a new course object to be filled in by the user
        Course newCourse = cinOneCourse(size + 1);
        
        //If the user didn't press Q, add the course to the array
        if(newCourse.courseName.empty())
        {
            break; //if the user pressed Q, end the program
        }
        else
        {
            courses[size] = newCourse;
            coutAllCourses(courses, size); //print the table so the user can see all their courses
            size++;
        }
        
    }
    //save user input to the file
    serialiseCoursesDown(courses, size);
    
    return 0;
}
