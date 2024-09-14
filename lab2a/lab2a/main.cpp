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
    if(change < 49.99)
    {
        return 0;
    }
    else
    {
        change = change - 50;
        return 1 + countFiftyBills(change);
    }
}

int countTwentyBills(float& change)
{
    if(change < 19.99)
    {
        return 0;
    }
    else
    {
        change = change - 20;
        return 1 + countTwentyBills(change);
    }
}

int countTenBills(float& change)
{
    if(change < 9.99)
    {
        return 0;
    }
    else
    {
        change = change - 10;
        return 1 + countTenBills(change);
    }
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
    
    //create a variable to represent the amount of change
    float change;
    change = amountTendered - purchaseAmount;
    
    cout << countFiftyBills(change) << endl;
    cout << countTwentyBills(change) << endl;
    cout << countTenBills(change) << endl;
        
    return 0;
}
