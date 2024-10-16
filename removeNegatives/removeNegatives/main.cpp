// midterm programming question
//  main.cpp
//  removeNegatives
//
//  Created by Sufyan Adam on 11/10/24.
//

#include <iostream>
using namespace std;

struct information {
    int negatives;
    bool isNegativeOne;
    bool hasOnlyZeros;
};

void removeNegatives(int numbers[], int size)
{
    information Info;
    int countNegatives =0;
    int countNegativeOnes =0;
    int countZeros = 0;
    bool hasOnlyZeros;
    bool isNegativeOne;
    for(int i = 0; i <= size; i++)
    {
        if(numbers[i] == -1)
        {
            countNegativeOnes++;
        }
        
        if(numbers[i] == 0)
        {
            countZeros++;
        }
        if(numbers[i] < 0)
        {
            numbers[i] = 0;
            countNegatives++;
            countZeros++;
        }
    }
    
    Info.negatives = countNegatives;
    
    if(countNegativeOnes == size)
    {
        isNegativeOne = true;
    }
    else
    {
        isNegativeOne = false;
    }
    
    if(countZeros == size)
    {
        hasOnlyZeros = true;
    }
    else
    {
        hasOnlyZeros = false;
    }
    
    Info.hasOnlyZeros = hasOnlyZeros;
    Info.isNegativeOne = isNegativeOne;
    
    cout << "Has only zeros?" << Info.hasOnlyZeros << endl;
    cout << "Had negative ones?" << Info.isNegativeOne << endl;
    cout << "Number of negative numbers: " << Info.negatives << endl;
}
int main() {
    int numList0[] = {-1};
    int numList1[] = {-1, -1, -1};
    int numList2[] = {0};
    int numList3[] = {10, -1};
    int numList4[] = {0, -1};
    int numList5[] = {-1, 10};
    int numList6[] = {-1, 0};
    int numList7[] = {10, -1, 20, 30};
    int numList8[] = {10, -1, 0, -1};
    int numList9[] = {10, 20, 30, -1, 40, -1, 0, 50};
    
    removeNegatives(numList0, 1);
    removeNegatives(numList1, 3);
    removeNegatives(numList2, 1);
    removeNegatives(numList3, 2);
    removeNegatives(numList4, 2);
    removeNegatives(numList5, 2);
    removeNegatives(numList6, 2);
    removeNegatives(numList7, 4);
    removeNegatives(numList8, 4);
    removeNegatives(numList9, 8);
    return 0;
}
