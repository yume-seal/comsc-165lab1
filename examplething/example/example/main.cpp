//
//  main.cpp
//  example
//
//  Created by Sufyan Adam on 20/9/24.
//

#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    // insert code here...
 //   std::cout << "Hello World!\n";
   // std::cout << std::setw(20) << std::left << "Hello, World!"
     //   << std::setw(30) << std::left << "Name\n";
    
    std::cout << std::left << "Name";
    std::cout << std::setw(10) << std::right << "Age";
    std::cout << std::setw(10) << "City";
    std::cout << std::setw(20) << "Class Rank";
    std::cout << std::setw(7) << "GPA\n";
    std::cout << std::setw(0) << std::setfill('-') << std::setw(51) << "" << std::endl << std::setfill(' ');
    std::cout << std::left << "Some Name";
    std::cout << std::setw(10) << std::right << "31";
    std::cout << std::setw(10) << "Some City";
    std::cout << std::setw(20) << "32";
    std::cout << std::setw(7) << "2.0\n";
    std::cout << std::setw(0) << std::setfill('-') << std::setw(51) << "" << std::endl << std::setfill(' ');
    return 0;
}
