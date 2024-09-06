/*******************************************************
 * Name: Madeeha Adam
 * Assignment: Lab 2 - Making Exact Change
 * Compiler used: Xcode
 * Description:
 *  This program allows the user to check out their own groceries. It asks the user for two inputs; the amount of the purchase and the amount tendered by the customer (assuming the amount tendered is >= the amount of the purchase). The program will then output some lines showing the amount of change returned and the number of bills and coins that will be dispensed as change in descending order of monetary amount.
 **********************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

int main()
{
    //Create float variable for amount of purchase
    float purchaseAmount = -1;
    
    //Create float variable for amount tendered
    float amountTendered = -1;
    
    do
    {
        cout << "Enter the amount of the purchase and the amount tendered (separated by a space): " << endl;
        cin >> purchaseAmount;
        cin >> amountTendered;
        cout << "The purchase amount is " << purchaseAmount << endl;
        cout << "The amount tendered is " << amountTendered << endl;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    } while(purchaseAmount < 0 || amountTendered < 0);
    
    //Create a variable to store the amount of change
    float change;
    
    //Determine the amount of change
    change = amountTendered - purchaseAmount;
    cout << "The change is " << change <<endl;
    
    //create a variable for the amount of 50 dollar bills needed for change
    int fiftyBill = 0;
    
    //Determine if $50 bills should be given as part of the change
    if(change > 49.99)
    {
        while(change > 49.99)
        {
            change = change - 50;
            fiftyBill++;
            
        }
        
        if(fiftyBill > 1)
        {
            cout << fiftyBill << " $50 bills" << endl;
        }
        else
        {
            cout << fiftyBill << "$50 bill" << endl;
        }
    }
    
    //create a variable for the amount of 20 dollar bills needed for change
    int twentyBill =0;
    
    //Determine if $20 bills should be given as part of the change
    if(change > 19.99)
    {
        while(change > 19.99)
        {
            change = change - 20;
            twentyBill++;
        }
        
        if(twentyBill > 1)
        {
            cout << twentyBill << " $20 bills" << endl;
        }
        else
        {
            cout << twentyBill << " $20 bill" << endl;
        }
    }
    return 0;
}

