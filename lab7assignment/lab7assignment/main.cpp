//
//  main.cpp
//  lab7assignment
//
//  Created by Sufyan Adam on 14/11/24.
//

#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iomanip>

#include <algorithm>
using std::swap;

#include <string>
using std::string;

struct Movie //create movie struct
{
    string title;
    int year;
    int rating;
    Movie* next;
};

void serialiseUp(Movie*& firstMoviePtr, Movie*& lastMoviePtr)
{
    ifstream fin;
    fin.open("movies.txt");
    while(fin.good())
    {
        string buff;
        getline(fin, buff);
        if(buff == "EOF")
        {
            break;
        }
        
        Movie* temp = new Movie;
        temp->title = buff;
        fin >> temp->year;
        fin.ignore(200, '\n');
        fin >> temp->rating;
        fin.ignore(200, '\n');
        temp->next = nullptr;
        if(!firstMoviePtr)
        {
            firstMoviePtr = temp;
        }
        if(lastMoviePtr)
        {
            lastMoviePtr->next = temp;
            lastMoviePtr = temp;
        }
    }
    fin.close();
}

int main() {
    Movie* firstMoviePtr = nullptr;
    Movie* lastMoviePtr = nullptr;
    serialiseUp(firstMoviePtr, lastMoviePtr);
    return 0;
}
