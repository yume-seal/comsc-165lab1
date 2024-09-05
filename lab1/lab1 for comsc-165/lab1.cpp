/***********************************************************
 * Name: Madeeha Adam
 * Assignment: Lab 1 - Console Programming Basics
 * Compiler used: Xcode
 * Description:
 *  This program reads and outputs two sets of inputs, including two calculated values in
 * the output.
** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;
using std::getline;

#include <cstdlib>

int main()
{
    //Create a variable to store user's age
    int age;
    
    //Ask user for their age
    cout << "Enter your age: " << endl;

    //Get user input and store it in age
    cin >> age;
    
    //If the user gives invalid input for their age, keep prompting them for their age
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter your age: " << endl;
        cin >> age;
    }
    
    
    //Create a variable to store user's name
    string name;
    
    //Ask user for their name
    cout << "Enter your name: " << endl;
    cin.ignore(200, '\n');
    
    //Get user input and put it in name
    getline(cin, name);
    
    //Create a variable to store the temperature in degrees F
    float fTemperature;
    
    //Ask user for the temperature outside right now
    cout << "Enter the temperature outside right now (degrees F): " << endl;
    
    //Get user input and put it in temperature
    cin >> fTemperature;
    
    //If user doesn't give a float keep asking them for the temperature
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Enter the temperature outside right now (degrees F): " << endl;
        cin >> fTemperature;
    }
    
    //Create a variable to store the temperature in degrees C
    float cTemperature;
    
    //Convert the temperature from degrees F to C
    cTemperature = (fTemperature - 32) * 5/9;
    
    //Create a variable to store the city the user is in
    string city;
    
    //Ask user what city they are in
    cout << "What city are you in right now?" << endl;
    cin.ignore(200, '\n');
   
    //Get user input and put it in city
    getline (cin, city);
    
    //Print information to the user
    cout << name << " is " << age << " years old and will be " << age + 2 << " two years from now." << endl;
    cout << "It's " << fTemperature << " degrees F in " << city << " -- that's ";
    
    //Apply formatting so that the outputted C temperature is rounded to 1 decimal place
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << cTemperature << " degrees C." << endl;
    
    return 0;
}
