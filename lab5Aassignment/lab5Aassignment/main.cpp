/*
* Name: Madeeha Adam
* Assignment Lab 5A Track Expenses Using C Strings and Dynamic Arrays
* Compiler used: Xcode
* Description: The program allows the user to enter information about expenses and stores them in an array. It allows the user to also search through the array to find different expenses.
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

#include <vector>

#include <string>
#include <cstring>
using std::string;

#include <cctype>
#include <string>

struct Expense { //struct for the expenses in the array
    char description[100];
    float amount;
};
/* This function takes a user entered float and searches for expense objects that have an amount >= the float.
 
 Params: Array of expense objects (IN)
         integer value (IN) used to represent the amount of valid objects in the array
 Return: NONE*/
void searchAmount(Expense *expenses, int& size)
{
    float searchAmount = 0; //declare a float to hold user input
    cout << "Please enter the amount: ";
    cin >> searchAmount; //put the input in the float
    bool found = false; //declare a boolean variable to check whether the amount is found
    
    for(int counter = 0; counter <= size; counter++) //make a loop to search through the array
    {
        if(expenses[counter].amount >= searchAmount)
        {
            found = true;
            //print the expense with the matching amount
            cout << "AMOUNT: (" << expenses[counter].amount << ")" << "DESC: (" << expenses[counter].description << ")" << endl;
        }
    }
    
    if(found == false)
    {
        //if there's no matching amount, say so
        cout << "\nNo results found with an amount greater than or equal to " << searchAmount << endl;
    }
}
/* This function takes characters entered by the user and searched for expenses that have those characters in their description.
 Params: Array of expense objects (IN)
 Return: NONE */
void searchString(Expense *expenses)
{
    Expense searchedExpense; //make an expense to hold the searched expense
    char stringSearch[100]; //make a array for the search string
    char lowerSearch[100]; //make a array to convert search string to lowercase
    char descriptionCopy[100]; //make a array to convert the expense desc to lower case
    bool found = false;
    cout << "Please enter the search string: ";
    cin >> stringSearch;
    int copy = 0;
    for(int copy = 0; stringSearch[copy] != '\0'; copy++) //copy search string to another array
    {
        lowerSearch[copy] = stringSearch[copy];
    }
    lowerSearch[copy + 1] = '\0';
    
    for(int count = 0; lowerSearch[count] != '\0'; count++) //convert the new array to lowercase
    {
        lowerSearch[count] = tolower(lowerSearch[count]);
    }
    
    int countSize = 0; //declare a variable to keep track of the expenses in the array
    for(int counter = 0; expenses[countSize].description[counter] != '\0'; counter++)
    {
        descriptionCopy[counter] = tolower(expenses[countSize].description[counter]);
        
        if(strstr(descriptionCopy, lowerSearch) != NULL) //if the desc and search string are the same, print the expense with the search string.
        {
            found = true;
            searchedExpense = expenses[countSize];
            cout << "\nAMOUNT: (" << searchedExpense.amount << ") " << "DESC: (" << searchedExpense.description << ") " << endl;
        }
        
        countSize++; //if it wasn't found, check the next expense
    }
    if(found == false)
    {
        cout << "\nNo results found for: " << stringSearch << endl;
    }
}

/* This function allows the user to create a new expense object
 Params: NONE
 Return: Expense object
 */
Expense spend()
{
    Expense newExpense; //make a new expense for user to fill
    cout << "Please enter the description of the expense: ";
    char desc[100]; //create char array to store user input
    cin.ignore();
    cin.getline(desc, 100);
    
    while(desc[0] == '\0') //don't allow the user to put an empty desc
    {
        cout << "\nThe description cannot be empty. Please try again: ";
        cin.clear();
        cin >> desc;
    }
    int countChar = 0; //create variable to keep track of how many characters user entered
    while(desc[countChar] != '\0')//transfer user input to expense desc
    {
        newExpense.description[countChar] = desc[countChar];
        countChar++;
    }
    
    newExpense.description[countChar] = '\0'; //put the ending character
    
    cout << "Please enter the amount of the expense: "; //ask for user input
    float amount;
    cin >> amount;
    
    while(amount <= 0) //make sure the user spent more than 0 dollars
    {
        cout << "\nThe amount cannot be 0 or less. Please try again: ";
        cin.clear();
        cin.ignore(INT_MAX, 10);
        cin >> amount;
    }
    
    newExpense.amount = amount; //put the user input in the expense amount
    
    return newExpense; //return the new expense to put in array of expenses
}

/* This function displays all the expense objects in the array.
 Params: Array of expenses (IN)
         integer value to keep track of array size (IN)
 Return: NONE
 */
void showAll(Expense *expenses, int& size)
{
   if(size < 0) //don't display empty array
   {
       cout << "\nThere is no expense entry available" << endl;
   }
   else
   {
       cout << "\nExpenses: " << endl;
             
        for(int counter = 0; counter <= size; counter++) //loop through the array to display all the expenses in it
        {
            cout << "AMOUNT: (" << expenses[counter].amount << ") " << "DESC: (" << expenses[counter].description << ")" << endl;
        }
   }
}

/* This function displays a menu for the user and calls different functions based on the option the user selects
 Params: Array of expenses (IN)
         Integer value (IN)
 Return: NONE
 */
void menu(Expense *expenses, int& size)
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
        cout << std::right << std::setw(43) << "3. Search expenses containing this string"<< endl;
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
            searchString(expenses);
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
    int capacity = 2; //make the amount for the dynamic array
    Expense *expenses = new Expense[capacity]; //create a dynamic array
    int size = -1; //variable to keep track of the size of the array

    menu(expenses, size); //call menu function
}
