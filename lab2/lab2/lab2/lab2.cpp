/*******************************************************
 * Name: Madeeha Adam
 * Assignment: Lab 2 - Making Exact Change
 * Compiler used: Xcode
 * Description:
 *  This program allows the user to check out their own groceries. It asks the user for two inputs; the amount of the purchase and the amount tendered by the customer (assuming the amount tendered is >= the amount of the purchase). The program will then output some lines showing the amount of change returned and the number of bills and coins that will be dispensed as change in descending order of monetary amount.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

int main()
{
    //Create float variable to store the amount of the purchase
    float purchaseAmount = -1;
    
    //Create float variable to store the amount tendered
    float amountTendered = -1;
    
    /* Ask the user for the purchase amount and the amount tendered. If the user enters invalid input, keep asking them the question  until they enter valid input */
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
    } while(purchaseAmount < 0 || amountTendered < 0); /* Keep executing this loop until the user                                                    enters a valid amount for the two variables*/
    
    //Create a variable to store the amount of change
    float change;
    
    //Determine the amount of change
    change = amountTendered - purchaseAmount;
    
    /* Tell the user the amount of change they will receive. Format the output so that the change
     is shown correct to 2 decimal places */
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The change is $" << change <<endl;
    
    //create a variable to store how many $50 bills are required for the change
    int fiftyBill = 0;
    
    //Determine if $50 bills should be given as part of the change
    if(change > 49.99)
    {
        while(change > 49.99)
        {
            //Keep subtracting $50 from the change until the change is less that 50 dollars.
            change = change - 50;
            
            //Increment the fiftyBill variable every time a 50 dollar bill is used for change
            fiftyBill++;
            
        }
        
        //Check to see whether the word "bill" should be plural in the output
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
            //Keep subtracting $20 from the change until the change is less than 20 dollars.
            change = change - 20;
            
            //Increment the twentyBill variable every time a 20 dollar bill is used.
            twentyBill++;
        }
        
        //Check to see whether the word "bill" should be plural in the output
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
            //Keep subtracting $10 from the change until the change is less than 10 dollars.
            change = change - 10;
            
            //Increment the tenBill variable every time a 10 dollar bill is used.
            tenBill++;
        }
        
        //Check to see whether the word "bill" should be plural in the output
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
            //Keep subtracting $5 from the change until the change is less than 5 dollars.
            change = change - 5;
            
            //Increment the fiveBill variable every time a 5 dollar bill is used.
            fiveBill++;
        }
        
        //Check to see whether the word "bill" should be plural in the output
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
            //Keep subtracting $1 from the change until the change is less than 1 dollar.
            change = change - 1;
            
            //Increment the oneBill variable every time a 1 dollar bill is used.
            oneBill++;
        }
        
        //Check to see whether the word "bill" should be plural in the output
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
            //Keep subtracting 50 cents from the change until the change is less than 50 cents
            change = change - 0.50;
            
            //Increment the fiftyCoin variable every time a 50-cent coin is used
            fiftyCoin++;
        }
        
        //Check to see whether the word "coin" should be plural in the output
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
            //Keep subtracting 25 cents from the change until the change is less than 25 cents
            change = change - 0.25;
            
            //Increment the twentyFiveCoin variable every time a 25-cent coin is used
            twentyFiveCoin++;
        }
        
        //Check to see whether the word "coin" should be plural in the output
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
            //Keep subtracting 10 cents from the change until the change is less than 10 cents
            change = change - 0.10;
            
            //Increment the tenCoin variable every time a 10-cent coin is used
            tenCoin++;
        }
        
        //Check to see whether the word "coin" should be plural in the output
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
            //Keep subtracting 5 cents from the change until the change is less than 5 cents
            change = change - 0.05;
            
            //Increment the fiveCoin variable every time a 5-cent coin is used
            fiveCoin++;
        }
        
        //Check to see whether the word "coin" should be plural in the output
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
            //Keep subtracting 1 cent from the change until the change is less than 1 cent
            change = change - 0.01;
            
            //Increment the oneCoin variable every time a 1-cent coin is used
            oneCoin++;
        }
        
        //Check to see whether the word "coin" should be plural in the output
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

