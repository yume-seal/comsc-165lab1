/*
 Name: Madeeha Adam
 Assignment: Lab 5 - Tracking Expenses with Arrays and Strings
 Compiler used: Xcode
 Description: The program allows the user to enter information about expenses and stores them in an array. It allows the user to also search through the array to find different
 expenses.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>

#include <iomanip>

#include <string>
using std::string;

struct Expense { //make the struct for expense objects
    string description;
    float amount;
};

/* This function takes a user entered float and searches for expense objects that
 have an amount >= the float.
 Parameters: Array of expense objects (IN)
             integer value (IN) used to represent the amount of valid objects in the array
 Return: NONE
 */
void searchAmount(Expense expenses[], int& size)
{
    Expense searchedExpense;
    
    float searchAmount = 0;
    cout << "Please enter the amount: ";
    cin >> searchAmount;
    bool found = false;
    
    for(int counter = 0; counter <= size; counter++)
    {
        if(expenses[counter].amount >= searchAmount)
        {
            found = true;
            cout << "AMOUNT: (" << expenses[counter].amount << ") " << "DESC: (" << expenses[counter].description << ")" << endl;
        }
    }
    if(found == false)
    {
        cout << "\nNo results found with an amount greater than or equal to " << searchAmount;
    }
}

/* This function takes a user entered string and prints an expense object that contains that string.
 Parameters: Array of expense objects (IN)
             integer value (IN) used to represent the amount of valid objects in the array.
 Return: NONE*/
void searchString(Expense expenses[], int& size)
{
    Expense searchedExpense;
    
    char stringSearch[100];
    bool found = false;
    
    cout << "Please enter the search string: ";
    
    cin >> stringSearch;
    
    for(int counter = 0; counter <= size; counter++)
    {
        if(strstr(expenses[counter].description.c_str(), stringSearch) != NULL)
        {
            found = true;
            searchedExpense = expenses[counter];
            cout << "AMOUNT: (" << searchedExpense.amount << ") " << "DESC: (" << searchedExpense.description << ")" << endl;
        }
    }
    
    if(found == false)
    {
        cout << "\nNo results found for: " << stringSearch << endl;
    }
}

/* This function allows the user to enter an expense entry and returns the expense object
 that the user entered.
 Parameters: NONE
 Return: Expense object*/
Expense spend()
{
    Expense newExpense; //make new empty expense object for user to fill
    cout << "Please enter the description for the expense: ";
    string desc;
    cin.ignore(); //ignore whitespace
    getline(cin, desc); //get user input
    
    while(desc.empty()) //make sure the user enters something for the description
    {
        cout << "\nThe description cannot be empty. Please try again: ";
        cin.clear();
        getline(cin, desc);
    }
    
    newExpense.description = desc; // put user input in the empty expense object
    
    cout << "Please enter the amount of the expense: ";
    float amount;
    cin >> amount;
    
    while(amount <= 0) //make sure the amount is something valid
    {
        cout << "\nThe amount cannot be 0 or less. Please try again: ";
        cin.clear();
        cin.ignore(INT_MAX, 10);
        cin >> amount;
    }
    
    newExpense.amount = amount; //put user input in the expense object
    
    return newExpense; //return user filled expense object
}

/* This function displays all the expense objects in the array.
 Parameters: Array of expense objects
             Integer value (IN) that is used to represent how many valid objects is in the array.*/
void showAll(Expense expenses[], int size)
{
    if(size < 0) //check there is something in the array
    {
        cout << "\nThere is no expense entry available." << endl;
    }
    else //if there is something then print it
    {
        cout << "Expenses: " << endl;
        
        for(int counter = 0; counter <= size; counter++)
        {
            cout << "AMOUNT: (" << expenses[counter].amount << ") " << "DESC: (" << expenses[counter].description << ")" << endl;
        }
    }
}

/* This function displays the menu for the user to see what they want to do. Based on the
 option the user selects, it calls an appropriate function or terminates the program.
 Parameter: Array of expenses (IN)
            Integer value (IN) that represents the number of valid objects in the array
 Return: NONE
 */
void menu(Expense expenses[], int& size)
{
    int option = 0;
    string buff;
    
    //print the menu all the time so the user can keep doing different options until they
    //want the program to stop.
    while(option != 5)
    {
        cout << "Expense Tracking Menu" << endl;
        cout << std::right << std::setw(13) << "1. Show all" << endl;
        cout << std::right << std::setw(10) << "2. Spend" << endl;
        cout << std::right << std::setw(43) << "3. Search expenses containing this string" << endl;
        cout << std::right << std::setw(62) << "4. Search expenses with greater than or equal to this amount" << endl;
        cout << std::right << std::setw(9) << "5. Exit" << endl;
        
        cout << "Enter your option: ";
        
        cin >> buff; //get user input
        option = atoi(buff.c_str()); //convert to integer and put in option variable
        
        while(option < 1 || option > 5) //if the user writes daft things ask them for the option again
        {
            cout << "\nInvalid input. Please enter an integer between 1 and 5: ";
            cin.ignore(INT_MAX, '\n');
            cin.clear();
            cin >> option;
        }
        
        if(option == 1) //call the function to show all expenses
        {
            showAll(expenses, size);
        }
        else if(option == 2) //call the function to make a new expense entry
        {
            size++;
            Expense newExpense = spend();
            expenses[size] = newExpense;
        }
        else if(option == 3) //call the function to search the expenses by string
        {
            searchString(expenses, size);
        }
        else if(option == 4) //call the function to search the expenses by amount
        {
            searchAmount(expenses, size);
        }
    }
}

/* this is the main function */
int main()
{
    int const CAPACITY = 100; //this is the max amount of expenses the user can enter
    Expense expenses[CAPACITY];
    int size = -1; //set the size to -1 bc 0 is first element and first element will only // be added when user enters it
    menu(expenses, size); //call the menu function to fill the array and stuff.
    return 0;
}
