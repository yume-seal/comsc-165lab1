/* Name: Madeeha Adam
*  Assignment: Lab 3 - Saving Student Objects into a file
*  Compiler used: Xcode
*  Description:
*  This program allows the user to enter information about 3 students. The program outputs
    the student information in a table and saves it to a file before the program ends.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;
using std::getline;

//For outputting information to the file
#include <fstream>
using std::ofstream;

#include <iomanip>

//This is to create a student object
struct Student
{
    string name;
    string city;
    int age;
    int classRank;
    float gpa;
};

/* This function creates an empty student object and prompts the user for information
 about the student which it will put into the student object
 Parameters: NONE
 Return: Student object
 */
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
    cout << "\nEnter the Student's class rank(out of 1000): ";
    
    //Store the class rank in the student object. If the user enters and invalid class rank
    // prompt them to enter it again.
    cin >> buf; someStudent.classRank = atoi(buf.c_str());
    while(someStudent.classRank < 1 || someStudent.classRank > 1000)
    {
        cout << "\nInvalid input. Please try again: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> buf; someStudent.classRank = atof(buf.c_str());
    }
    
    //Ask the user for the Student's gpa
    cout << "\nEnter the Student's gpa (must be between 0 and 4): ";
    
    //Store the gpa in the student object. If the user enters an invalid gpa prompt them
    // to enter it again.
    cin >> buf; someStudent.gpa = atof(buf.c_str());
    while(someStudent.gpa < 0 || someStudent.gpa > 4)
    {
        cout << "\nInvalid input. Please try again: ";
        cin >> buf; someStudent.gpa = atof(buf.c_str());
    }
    
    //clear the buffer...
    cin.ignore(INT_MAX, '\n');
    
    return someStudent;
}

/* This function takes a student object and outputs the attributes of the student in the table. We use the setw function to make space between the words.
 
 Parameters: student: student object
 Return: NONE
 */
void outputStudent(Student student)
{
    cout << "" << std::setw(20) << std::left << student.name;
    cout << "" << std::setw(15) << std::setfill(' ') << student.city;
    cout << "" << std::setw(7) << std::setfill(' ') << student.age;
    cout << "" << std::setw(15) << student.classRank;
    cout << "" << std::setw(7) << student.gpa << "\n";
    cout << std::setw(0) << std::setfill('-') << std::setw(64) << std::left << "" << std::setfill(' ') << endl;
}

/* This function saves the student object's attributes that the user entered to a file
 Parameters: student: Student object
 Return: boolean value to determine whether the file was opened. It's not necessary though,
 this function could be a void function but writing it as a bool helps me understand it better.
 */
bool saveStudentData(Student student)
{
    ofstream outFile; //declare ofstream object to output information to a file
    
    //open the file to output to
    outFile.open("students.txt", ios::app);
    
    if(!outFile.is_open()) //if the File cannot be opened for some reason, let us know...
    {
        cout << "File cannot be opened" << endl;
        return false;
    }
    
    //output the information to the file
    outFile << "Name: " << student.name << endl;
    outFile << "City: " << student.city << endl;
    outFile << "Age: " << student.age << endl;
    outFile << "Class Rank: " << student.classRank << endl;
    outFile << "GPA: " << student.gpa << endl;
    
    outFile.close(); //close the file
    
    return true; //true because we were able to open the file and write to it.
}

/*this is the main function*/
int main()
{
    //If the user inputs any decimal values, output those values to the nearest 2 decimal places.
    cout.setf(ios::fixed);
    cout.precision(2);
    
    //create 3 students and call the inputStudent function on them...
    Student student1 = inputStudent();
    cout << "\n"; //Make a new line so it looks nice in the output...
    Student student2 = inputStudent();
    cout << "\n";
    Student student3 = inputStudent();
    cout << "\n";
    
    //This is for formatting the table header...
    cout << std::setw(20) << std::left << "Name";
    cout << std::setw(15) << std::left << "City";
    cout << std::setw(7) << "Age";
    cout << std::setw(15) << "Class Rank";
    cout << std::setw(7) << "GPA" << "\n";
    cout << std::setw(0) << std::setfill('-') << std::setw(64) << "" << std::setfill(' ') << endl;
    
    //call the outputStudent function on the 3 students so their attributes can be put in the table
    outputStudent(student1);
    outputStudent(student2);
    outputStudent(student3);
    
    //call the saveStudentData function on the 3 students so the attributes the user
    //entered can be saved
    saveStudentData(student1);
    saveStudentData(student2);
    saveStudentData(student3);
    
    return 0;
}
