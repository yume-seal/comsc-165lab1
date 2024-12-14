//
//  expense.h
//  lab10assignment
//
//  Created by Sufyan Adam on 14/12/24.
//

#ifndef EXPENSE_H
#define EXPENSE_H
#include <string>
using std::string;

class Expense
{
private:
    double amount;
    string description;
    
public:
    Expense();
    Expense(double amount, string description);
    double getAmount() const;
    void setAmount(double amount);
    string getDescription() const;
    
    void setDescription(string description);
    
    bool contains(string& searchString) const;
};
#endif
