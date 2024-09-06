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
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The change is $" << change <<endl;
    
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
    
    //create a variable for the amount of 10 dollar bills needed for change
    int tenBill = 0;
    
    //Determine if $10 bills should be given as part of the change
    if(change > 9.99)
    {
        while(change > 9.99)
        {
            change = change - 10;
            tenBill++;
        }
        
        if(tenBill > 1)
        {
            cout << tenBill << " $10 bills" << endl;
        }
        else
        {
            cout << tenBill << " $10 bill" << endl;
        }
    }
    
    //create a variable for the amount of 5 dollar bills needed for change
    int fiveBill = 0;
    
    //Determine if $5 bills should be given as part of the change
    if(change > 4.99)
    {
        while(change > 4.99)
        {
            change = change - 5;
            fiveBill++;
        }
        
        if(fiveBill > 1)
        {
            cout << fiveBill << " $5 bills" << endl;
        }
        else
        {
            cout << fiveBill << " $5 bill" << endl;
        }
    }
    
    //create a variable for the amount of 1 dollar bills needed for change
    int oneBill = 0;
    
    //Determine if $1 bills should be given as part of the change
    if(change > 0.99)
    {
        while(change > 0.99)
        {
            change = change - 1;
            oneBill++;
        }
        
        if(oneBill > 1 )
        {
            cout << oneBill << " $1 bills" << endl;
        }
        else
        {
            cout << oneBill << " $1 bill" << endl;
        }
    }
    
    //create a variable for the amount of 50 cent coins needed for change
    int fiftyCoin = 0;
    
    //Determine if 50 cent coins should be given as part of the change
    if(change > 0.49)
    {
        while(change > 0.49)
        {
            change = change - 0.50;
            fiftyCoin++;
        }
        
        if(fiftyCoin > 1)
        {
            cout << fiftyCoin << " 50-cent coins" << endl;
        }
        else
        {
            cout << fiftyCoin << " 50-cent coin" << endl;
        }
    }
    
    //create a variable for the amount of 25 cent coins needed for change
    int twentyFiveCoin = 0;
    
    //Determine if 25 cent coins should be given as part of the change
    if(change > 0.24)
    {
        while(change > 0.24)
        {
            change = change - 0.25;
            twentyFiveCoin++;
        }
        
        if(twentyFiveCoin > 1)
        {
            cout << twentyFiveCoin << " 25-cent coins" << endl;
        }
        else
        {
            cout << twentyFiveCoin << " 25-cent coin" << endl;
        }
    }
    
    //create a variable for the amount of 10 cent coins needed for change
    int tenCoin = 0;
    
    //Determine if 10 cent coins should be given as part of the change
    if(change > 0.09)
    {
        while(change > 0.09)
        {
            change = change - 0.10;
            tenCoin++;
        }
        
        if(tenCoin > 1)
        {
            cout << tenCoin << " 10-cent coins" << endl;
        }
        else
        {
            cout << tenCoin << " 10-cent coin" << endl;
        }
    }
    
    //create a variable for the amount of 5 cent coins needed for change
    int fiveCoin =0;
    
    //Determine is 5 cent coins should be given as part of the change
    if(change > 0.04)
    {
        while(change > 0.04)
        {
            change = change - 0.05;
            fiveCoin++;
        }
        
        if(fiveCoin > 1)
        {
            cout << fiveCoin << " 5-cent coins" << endl;
        }
        else
        {
            cout << fiveCoin << " 5-cent coin" << endl;
        }
    }
    
    //create a variable for the amount of 1 cent coins needed for change
    int oneCoin = 0;
    
    //Determine if 1 cent coins should be given as part of the change
    if(change > 0.009)
    {
        while(change > 0.009)
        {
            change = change - 0.01;
            oneCoin++;
        }
        
        if(oneCoin > 1)
        {
            cout << oneCoin << " 1-cent coins" << endl;
        }
        else
        {
            cout << oneCoin << " 1-cent coin" << endl;
        }
    }
    
    return 0;
}

