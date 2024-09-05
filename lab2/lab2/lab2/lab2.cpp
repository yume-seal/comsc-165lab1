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
    } while(purchaseAmount == -1 || amountTendered == -1);
    return 0;
}

