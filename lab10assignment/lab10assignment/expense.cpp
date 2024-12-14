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

double Expense::getAmount()const
{
    return amount;
}

void Expense::setAmount(double amount)
{
    this->amount = amount;
}

string Expense::getDescription()const
{
    return description;
}

void Expense::setDescription(string description)
{
    this->description = description;
}

bool Expense::contains(string& searchString) const
{
    string lowerDesc = description;
    transform(lowerDesc.begin(), lowerDesc.end(), lowerDesc.begin(), ::tolower);
    string lowerString = searchString;
    transform(lowerString.begin(), lowerString.end(), lowerString.begin(), ::tolower);
    return(lowerDesc.find(lowerString) != string::npos);
}
