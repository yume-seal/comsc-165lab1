//
//  main.cpp
//  lab5assignment
//
//  Created by Sufyan Adam on 14/10/24.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>

#include <iomanip>

#include <string>
using std::string;

struct Expense {
    string description;
    int amount;
};

void searchString(Expense expenses[], int& size)
{
    Expense searchedExpense;
    
    char stringSearch[100];
    
    cout << "Please enter the search string: ";
    
    cin >> stringSearch;
    
    for(int counter = 0; counter <= size; counter++)
    {
        if(strstr(expenses[counter].description.c_str(), stringSearch) != NULL)
        {
            searchedExpense = expenses[counter];
            cout << "AMOUNT: " << searchedExpense.amount << " " << "DESC: " << searchedExpense.description << endl;
        }
        else
        {
            cout << "No results found for: " << stringSearch;
        }
    }
}
Expense spend()
{
    Expense newExpense;
    cout << "Please enter the description for the expense: ";
    string desc;
    cin.ignore();
    getline(cin, desc);
    
    while(desc.empty())
    {
        cout << "\nThe description cannot be empty. Please try again: ";
        cin.clear();
        getline(cin, desc);
    }
    
    newExpense.description = desc;
    
    cout << "Please enter the amount of the expense: ";
    float amount;
    cin >> amount;
    
    while(amount == 0)
    {
        cout << "\nThe amount cannot be 0. Please try again: ";
        cin.clear();
        cin.ignore(INT_MAX, 10);
        cin >> amount;
    }
    
    newExpense.amount = amount;
    
    return newExpense;
}

void showAll(Expense expenses[], int size)
{
    for(int counter = 0; counter <= size; counter++)
    {
        if(expenses[0].amount == 0)
        {
            cout << "There is no expense entry available" << endl;
        }
        else
        {
            cout << "AMOUNT: " << expenses[counter].amount << " " << "DESC: " << expenses[counter].description << endl;
        }
    }
}

void menu(Expense expenses[], int& size)
{
    int option = 0;
    string buff;
    
    while(option != 5)
    {
        cout << "Expense Tracking Menu" << endl;
        cout << std::right << std::setw(13) << "1. Show all" << endl;
        cout << std::right << std::setw(10) << "2. Spend" << endl;
        cout << std::right << std::setw(43) << "3. Search expenses containing this string" << endl;
        cout << std::right << std::setw(62) << "4. Search expenses with greater than or equal to this amount" << endl;
        cout << std::right << std::setw(9) << "5. Exit" << endl;
        
        cout << "Enter your option: ";
        
        cin >> buff;
        option = atoi(buff.c_str());
        
        while(option < 1 || option > 5)
        {
            cout << "\nInvalid input. Please enter an integer between 1 and 5: ";
            cin.ignore(INT_MAX, '\n');
            cin.clear();
            cin >> option;
        }
        
        if(option == 1)
        {
            showAll(expenses, size);
        }
        else if(option == 2)
        {
            size++;
            Expense newExpense = spend();
            expenses[size] = newExpense;
        }
        else if(option == 3)
        {
            searchString(expenses, size);
        }
    }
}

int main()
{
    int const CAPACITY = 100;
    Expense expenses[CAPACITY];
    int size = -1;
    menu(expenses, size);
    return 0;
}
