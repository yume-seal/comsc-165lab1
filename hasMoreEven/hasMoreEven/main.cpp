// midterm coding question
//  main.cpp
//  hasMoreEven
//
//  Created by Sufyan Adam on 11/10/24.
//

#include <iostream>
using namespace std;


bool hasMoreEven() {
    
    int number = -1;
    while(number != 0)
    {
        string buff;
        cout << "Enter a number: " << endl;
        cin >> buff;
        number = atoi(buff.c_str());
        cout << number;
    }
    
    int numOfEvenNumbers = 0;
    int numOfOddNumbers = 0;
    
    if(number % 2 == 0)
    {
        numOfEvenNumbers++;
    }
    else
    {
        numOfOddNumbers++;
    }
    
    if(numOfEvenNumbers > numOfOddNumbers)
    {
        cout << "returned true";
        return true;
    }
    else
    {
        cout << "returned false";
        return false;
    }
}

int main() {
    hasMoreEven();
    return 0;
}
