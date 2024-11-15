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

/* This function prints out the menu
 Params: Movie pointer, integer value
 Return: NONE*/
void menu(Movie*& firstMoviePtr, Movie*& lastMoviePtr, int& sequenceNumber)
{
    char choice; //variable for user input
    
    do //print the menu
    {
        cout << "MENU\n";
        cout << "A Add a movie\n";
        cout << "U Update a movie\n";
        cout << "E rEmove a movie\n";
        cout << "L List all movies\n";
        cout << "T arrange by Title\n";
        cout << "V arrange by year Viewed\n";
        cout << "R arrange by Rating\n";
        cout << "Q Quit\n";
        cout << "...your choice: ";
        cin >> choice; //get user's choice
        
        //evaluate user's choice and call appropriate function
        if(choice == 'A' || choice == 'a')
        {
            //addMovie(head);
            sequenceNumber++;
        }
        else if(choice == 'U' || choice == 'u')
        {
            int number;
            cout << "\nWhich movie to update (1 - " << sequenceNumber << ")?";
            cin >> number;
          //  updateMovie(head, number);
        }
        else if(choice == 'E' || choice == 'e')
        {
            int number = 0;
            cout << "\nWhich movie to remove (1 - " << sequenceNumber << ")?";
            cin >> number;
            if(number > sequenceNumber || number < 1)
            {
                cout << "No such movie.";
            }
           // removeMovie(head, number);
           // sequenceNumber--;
        }
        else if(choice == 'L' || choice == 'l')
        {
           // listMovies(head);
        }
        else if(choice == 'T' || choice == 't')
        {
           // arrangeTitle(head);
            //listMovies(head);
        }
        else if(choice == 'V' || choice == 'v')
        {
            //arrangeYear(head);
           // listMovies(head);
        }
        else if(choice == 'R' || choice == 'r')
        {
          //  arrangeRating(head);
            //listMovies(head);
        }
        else if(choice == 'Q' || choice == 'q') //exit the function if the choice is q
        {
            return;
        }
        else //if none of these match the user's input, then make them enter something again.
        {
            cout << "\nInvalid input. Try again: ";
            cin >> choice;
        }
    } while (choice != 'Q' && choice != 'q');
}

int main() {
    Movie* firstMoviePtr = nullptr;
    Movie* lastMoviePtr = nullptr;
    int sequenceNumber = 0;
    serialiseUp(firstMoviePtr, lastMoviePtr);
    menu(firstMoviePtr, lastMoviePtr, sequenceNumber);
    return 0;
}
