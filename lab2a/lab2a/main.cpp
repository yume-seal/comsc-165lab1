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

float countOneCoins(float& change)
{
    int oneCoin = 0;
    
    while(change > 0.009)
    {
        change = change - 0.01;
        oneCoin++;
    }
    
    if(oneCoin != 0)
    {
        if(oneCoin > 1)
        {
            cout << oneCoin << " 1-cent coins" << endl;
        }
        else
        {
            cout << oneCoin << " 1-cent coin" << endl;
        }
    }
    return change;
}

float countChange(float& change, float denomination)
{
    bool isCoin = false;
    bool isDollar = false;
    int billsAndCoins = 0;
    cout.setf(ios::fixed);
    cout.precision(0);
    
    if(denomination > 0.99)
    {
        isDollar = true;
    }
    else if(denomination > 0.009)
    {
        isCoin = true;
    }
    else
    {
        countOneCoins(change);
    }
    
    if(isDollar == true)
    {
        while(change > denomination)
        {
            change = change - (denomination + 0.01);
            billsAndCoins++;
        }
        if(billsAndCoins != 0)
        {
            if(billsAndCoins > 1)
            {
                cout << billsAndCoins << " $" << denomination + 0.01 << " bills" << endl;
            }
            else
            {
                cout << billsAndCoins << " $" << denomination + 0.01 << " bill" << endl;
            }
        }
    }
        
        if(isCoin == true)
        {
            while(change > denomination)
            {
                change = change - (denomination + 0.01);
                billsAndCoins++;
            }
            
            if(billsAndCoins != 0)
            {
                if(billsAndCoins > 1)
                {
                    cout << billsAndCoins << " " << (denomination + 0.01) * 100 << "-cent coins" << endl;
                }
                else
                {
                    cout << billsAndCoins << " " << (denomination + 0.01) * 100 << "-cent coin" << endl;
                }
            }
        }
    return change;
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
    
    /* Tell the user the amount of change they will receive. Format the output so that the change
         is shown correct to 2 decimal places */
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout << "The change is $" << change << endl;
    
    countChange(change, 49.99);
    countChange(change, 19.99);
    countChange(change, 9.99);
    countChange(change, 4.99);
    countChange(change, 0.99);
    countChange(change, 0.49);
    countChange(change, 0.24);
    countChange(change, 0.09);
    countChange(change, 0.04);
    countChange(change, 0.009);
    
    return 0;
}
