//
//  expense.cpp
//  lab10assignment
//
//  Created by Sufyan Adam on 14/12/24.
//
#include "expense.h"
#include <algorithm>
#include <cctype>
#include <string>
using std::string;


Expense::Expense()
{
    amount = 0;
    description = "";
}

Expense::Expense(double expenseAmount, const string expenseDescription)
{
    amount = expenseAmount;
    description = expenseDescription;
}

//getter method to get the amount of the expense
double Expense::getAmount()const
{
    return amount;
}

//setter method to set the amount of the expense
void Expense::setAmount(double amount)
{
    this->amount = amount;
}

//getter method to set the description of the expense
string Expense::getDescription()const
{
    return description;
}
//setter method to set the description of the expense
void Expense::setDescription(string description)
{
    this->description = description;
}

//method to see if the expense contains a certain search string in the description
bool Expense::contains(string& searchString) const
{
    string lowerDesc = description;
    transform(lowerDesc.begin(), lowerDesc.end(), lowerDesc.begin(), ::tolower);
    string lowerString = searchString;
    transform(lowerString.begin(), lowerString.end(), lowerString.begin(), ::tolower);
    return(lowerDesc.find(lowerString) != string::npos);
}
