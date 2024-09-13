/*
*  Name: Madeeha Adam
*  Assignment: Lab 2A: Making Exact Change Using Functions
* Compiler used: Xcode
*  Description:
*   This program allows the user to check out their own groceries. It asks the user for two inputs; the amount of the purchase and the amount tendered by the customer (assuming the amount tendered is >= the amount of the purchase). The program will then output some lines showing the amount of change returned and the number of bills and coins that will be dispensed as change in descending order of monetary amount.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <ctime>

#include <string>
using std::string;


int countFiftyBills(float& change)
{
    int numOfFiftyBills = 0;
    
    if(change > 49.99)
    {
        change = change - 50;
        numOfFiftyBills++;
        countFiftyBills(change);
    }
    
    return numOfFiftyBills;
}

int main()
{
    
    // Print Welcome message
    cout << "Welcome to My Change Program" << endl;
    
    //declaring variable to hold the current time
    time_t seconds;
    
    //Pass seconds by reference to time function to get current time
    time(&seconds);
    
    //Convert the time to a string
    string currentTimeString = asctime(localtime(&seconds));
    
    //Print the current time
    cout << "\nThe time is " << currentTimeString << endl;
    
    //Create the float variable to store the amount of the purchase
    float purchaseAmount = -1;
    
    //Create the float variable to store the amount tendered
    float amountTendered = -1;
    
    /* Ask the user for the purchase amount and the amount tendered. If the user enters invalid input, keep asking them the question until they enter valid input*/
    do
    {
        cout << "Enter the amount of the purchase and the amount tendered (separated by a space): " << endl;  //Ask the user for input
        cin >> purchaseAmount; //get user input and put it in purchaseAmount
        cin >> amountTendered; //get user input and put it in amountTendered
            
        // Check the user's input to see if it is valid or not
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    } while(purchaseAmount < 0 || amountTendered < 0); /* Keep executing this loop until the user enters a valid amount for the two variables*/
    
    cout << countFiftyBills(amountTendered) << endl;
        
    return 0;
}
