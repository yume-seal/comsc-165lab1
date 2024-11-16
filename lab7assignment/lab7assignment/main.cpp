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
using std::left;
using std::right;

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

/* This function allows the user to create a new movie object and put it in the linked list
 Params: Movie pointer
 Return: NONE*/
void addMovie(Movie*& firstMoviePtr, Movie*& lastMoviePtr)
{
    string title; //string variable for title of the movie
    cout << "\nEnter the movie's name: "; //ask user for input
    cin.ignore(); //ignore whitespace...
    getline(cin, title); //get user input
    Movie* temp = new Movie; //create a temporary movie pointer and put a new movie object in it
    temp->title = title; //set the user entered title as the title of the movie
    int year; //integer variable for the year the movie was viewed.
    string buff;
    cout << "\nEnter the year you saw " << title << " [like 2016]: ";
    cin >> buff;
    year = atoi(buff.c_str());
    while(year < 1888) //make sure this is a valid time to have seen a movie
    {
        cout << "\nInvalid input. Enter the year you saw " << title << " [like 2016]: ";
        cin.clear();
        cin.ignore();
        cin >> buff;
        year = atoi(buff.c_str());
    }
    temp->year = year;
    int rating;
    cout << "\nEnter your rating for " << title << " [1, 2, 3, 4, 5]: ";
    cin >> buff;
    rating = atoi(buff.c_str());
    while(rating < 1 || rating > 5) //make sure the rating is in the interval
    {
        cout << "\nInvalid rating. Enter your rating for " << title << " [1, 2, 3, 4, 5]: ";
        cin.clear();
        cin.ignore();
        cin >> buff;
        rating = atoi(buff.c_str());
    }
    temp->rating = rating;
    if(firstMoviePtr == nullptr)
    {
        firstMoviePtr = temp;
        lastMoviePtr = temp;
    }
    else
    {
        lastMoviePtr->next = temp;
        lastMoviePtr = temp;
    }
}

/* This function allows user to update information about the movies in the linked list
 Params: Movie pointer, integer value
 Return: NONE*/
void updateMovie(Movie*& firstMoviePtr, int sequenceNumber)
{
    Movie* current = firstMoviePtr;
    firstMoviePtr = current; //keep track of which movie object we are on in the list
    int choice = -1;
    int currentSequenceNumber = 1; //

    while(current != nullptr) //make sure we aren't updating a movie object that doesn't exist
    {
        if(currentSequenceNumber == sequenceNumber) //we have found the movie object the user wants to update
        {
            while(choice < 0 || choice > 3) //make sure the user didn't make a choice out of the interval
            {
                cout << "\nWhat do you want to update about " << current->title << "?";
                cout << "\n1. Title";
                cout << "\n2. Year viewed";
                cout << "\n3. Rating";
                cout << "\n...your choice: ";
                cin >> choice;
            }
            
            switch (choice)
            {
                case 1: { //update title
                    string newTitle;
                    cin.ignore();
                    cout << "\nEnter the new title: ";
                    getline(cin, newTitle);
                    current->title = newTitle;
                    break;
                }
                case 2: { //update year
                    int year;
                    cout << "\nEnter the new year: ";
                    cin >> year;
                    while(year < 1888)
                    {
                        cout << "\nInvalid input. Enter the new year: ";
                        cin.clear();
                        cin.ignore();
                        cin >> year;
                    }
                    current->year = year;
                    break;
                }
                case 3: { //update rating
                    int rating;
                    cout << "\nEnter the new rating: ";
                    cin >> rating;
                    while(rating > 5 || rating < 1)
                    {
                        cout << "\nInvalid input. Enter the new rating: ";
                        cin.clear();
                        cin.ignore();
                        cin >> rating;
                    }
                    current->rating = rating;
                    break;
                }
            }
            return;
        }
        current = current->next; //go to the next object in the list
        currentSequenceNumber++; //increment the count...
    }
    
    cout << "\nNo movie was found" << endl;
}

/* This function allows the user to delete a movie from the linked list
 Params: Movie pointer, integer variable
 Return: NONE*/
void removeMovie(Movie*& firstMoviePtr, int sequenceNumber)
{
    Movie* current = firstMoviePtr;
    Movie* previous = nullptr;
    int currentSequenceNumber = 1;
    while(current != nullptr) //make sure there is something in the list
    {
        if(currentSequenceNumber == sequenceNumber) //we have found the movie to delete
        {
            if(previous == nullptr) //check if we are in the head of the list
            {
                firstMoviePtr = current->next; //make the head become the null pointer because it's going to be deleted
            }
            else
            {
                previous->next = current->next; //rearrange the objects so we can delete current and make the next object the head
            }
            delete current; //delete the movie object
            return;
        }
        previous = current;
        current = current->next; //iterate through the linkedlist
        currentSequenceNumber++;
    }
}

/* This function arranges the movies in the table in alphabetical order
 Params: Movie pointer
 Return: NONE*/
void arrangeTitle(Movie* firstMoviePtr)
{
    if(firstMoviePtr == nullptr) //if there is nothing in the list then don't do anything
    {
        return;
    }
    for(Movie* current = firstMoviePtr; current; current = current->next) //loop through the whole list
    {
        for(Movie* tsugi = current->next; tsugi; tsugi = tsugi->next) //do a bubble sort
        {
            if(tsugi->title < current->title) //if the next movie object is supposed to be in front of current then swap the objects and their pointers
            {
                swap(*current, *tsugi);
                swap(current->next, tsugi->next);
            }
        }
    }
}

/* This function arranges the movies in the order of most recently viewed
 Params: Movie pointer
 Return: NONE*/
void arrangeYear(Movie* firstMoviePtr)
{
    if(firstMoviePtr == nullptr) //don't do anything if the list is empty
    {
        return;
    }
    for(Movie* current = firstMoviePtr; current; current = current->next) //iterate through entire list
    {
        for(Movie* tsugi = current->next; tsugi; tsugi = tsugi->next) //bubble sort
        {
            if(tsugi->year > current->year) //if the year of the next movie is greater than current, swap them
            {
                //swapping the objects and the pointers...
                swap(*current, *tsugi);
                swap(current->next, tsugi->next);
            }
        }
    }
}

/* This function arranges the movies by the rating
 Params: Movie pointer
 Return: None*/
void arrangeRating(Movie* firstMoviePtr)
{
    if(firstMoviePtr == nullptr) //don't do anything if the list is empty
    {
        return;
    }
    for(Movie* current = firstMoviePtr; current; current = current->next) //iterate through the whole list
    {
        for(Movie* tsugi = current->next; tsugi; tsugi = tsugi->next) //bubble sort
        {
            if(tsugi->rating > current->rating) //if the rating of the next movie is greater than put it in front of current
            {
                swap(*current, *tsugi); //swap the two pointers
                swap(current->next, tsugi->next);
            }
        }
    }
}

void listMovies(Movie* firstMoviePtr)
{
    //print the table
    cout << left << std::setw(5) << "#";
    cout << left << std::setw(40) << "Title" ;
    cout << left << std::setw(10) << "Viewed";
    cout << left << std::setw(10) << "Rating" << endl;
    cout << right << std::setfill('-') << std::setw(4) << " " << std::setw(40) << " " << std::setw(10) << " " << std::setw(10) << "\n";
    int count = 1; //count the objects
    while(firstMoviePtr != nullptr) //print all the objects in the table
    {
        cout << std::setfill(' ') << left << std::setw(5) << count << left << std::setw(40) << firstMoviePtr->title << left << std::setw(10) << firstMoviePtr->year << left << std::setw(10) << firstMoviePtr->rating << "\n";
        firstMoviePtr = firstMoviePtr->next;
        count++;
    }
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
            addMovie(firstMoviePtr, lastMoviePtr);
            sequenceNumber++;
        }
        else if(choice == 'U' || choice == 'u')
        {
            int number;
            cout << "\nWhich movie to update (1 - " << sequenceNumber << ")?";
            cin >> number;
            updateMovie(firstMoviePtr, number);
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
            removeMovie(firstMoviePtr,number);
            sequenceNumber--;
        }
        else if(choice == 'L' || choice == 'l')
        {
            listMovies(firstMoviePtr);
        }
        else if(choice == 'T' || choice == 't')
        {
            arrangeTitle(firstMoviePtr);
            listMovies(firstMoviePtr);
        }
        else if(choice == 'V' || choice == 'v')
        {
            arrangeYear(firstMoviePtr);
            listMovies(firstMoviePtr);
        }
        else if(choice == 'R' || choice == 'r')
        {
            arrangeRating(firstMoviePtr);
            listMovies(firstMoviePtr);
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
