//
//  main.cpp
//  lab5Aassignment
//
//  Created by Sufyan Adam on 19/10/24.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

#include <vector>

#include <string>
using std::string;

struct Expense {
    char description[100];
    float amount;
};

Expense spend()
{
    Expense newExpense;
    cout << "Please enter the description of the expense: ";
    char desc[100];
    cin.ignore();
    cin.getline(desc, 100);
    
    while(desc[0] == '\0')
    {
        cout << "\nThe description cannot be empty. Please try again: ";
        cin.clear();
        cin >> desc;
    }
    int countChar = 0;
    while(desc[countChar] != '\0')
    {
        newExpense.description[countChar] = desc[countChar];
        countChar++;
    }
    
    newExpense.description[countChar] = '\0';
    
    cout << "Please enter the amount of the expense: ";
    float amount;
    cin >> amount;
    
    while(amount <= 0)
    {
        cout << "\nThe amount cannot be 0 or less. Please try again: ";
        cin.clear();
        cin.ignore(INT_MAX, 10);
        cin >> amount;
    }
    
    newExpense.amount =amount;
    
    return newExpense;
}
void showAll(Expense *expenses, int& size)
{
   if(size < 0)
   {
       cout << "\nThere is no expense entry available" << endl;
   }
   else
   {
       cout << "Expenses: " << endl;
             
        for(int counter = 0; counter <= size; counter++)
        {
            cout << "AMOUNT: (" << expenses[counter].amount << ") " << "DESC: (" << expenses[counter].description << ")" << endl;
        }
   }
}

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
            //searchString(expenses, size);
        }
        else if(option == 4) //call the function to search the expenses by amount
        {
            //searchAmount(expenses, size);
        }
    }
}

int main()
{
    const int CAPACITY = 2;
    Expense *expenses = new Expense[CAPACITY];
    int size = -1;

    menu(expenses, size);
}
