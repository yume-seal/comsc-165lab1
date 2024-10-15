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

void menu(Expense expenses[], int size)
{
    cout << "Expense Tracking Menu" << endl;
    cout << std::right << std::setw(13) << "1. Show all" << endl;
    cout << std::right << std::setw(10) << "2. Spend" << endl;
    cout << std::right << std::setw(43) << "3. Search expenses containing this string" << endl;
    cout << std::right << std::setw(62) << "4. Search expenses with greater than or equal to this amount" << endl;
    cout << std::right << std::setw(9) << "5. Exit" << endl;
    
    cout << "Enter your option: ";
    
    int option = 0;
    string buff;
    
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
}

int main()
{
    int const CAPACITY = 100;
    Expense expenses[CAPACITY];
    int size = 0;
    menu(expenses, size);
    return 0;
}
