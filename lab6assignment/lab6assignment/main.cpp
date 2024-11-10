//
//  main.cpp
//  lab6assignment
//
//  Created by Sufyan Adam on 6/11/24.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
#include <cctype>
#include <cstring>
#include <iomanip>
using std::left;
using std::right;
#include <cstdlib>
struct Movie
{
    string title;
    int year;
    int rating;
    Movie* next;
};

void addMovie(Movie*& head)
{
    string title;
    cout << "\nEnter the movie's name: ";
    cin.ignore();
    getline(cin, title);
    Movie* temp = new Movie;
    temp->title = title;
    int year;
    cout << "\nEnter the year you saw " << title << " [like 2016] :";
    cin >> year;
    while(year < 1888)
    {
        cout << "\nInvalid input. Enter the year you saw " << title << " [like 2016]: ";
        cin.clear();
        cin.ignore();
        cin >> year;
    }
    temp->year = year;
    int rating;
    cout << "\nEnter your rating for " << title << " [1, 2, 3, 4, 5] :";
    cin >> rating;
    while(rating < 0 || rating > 5)
    {
        cout << "\nInvalid rating. Enter your rating for " << title << " [1, 2, 3, 4, 5] :";
        cin.clear();
        cin.ignore();
        cin >> rating;
    }
    temp->rating = rating;
    temp->next = head;
    head = temp;
}

void updateMovie(Movie*& head, string title, int sequenceNumber)
{
    Movie* current = head;
    int choice = -1;
    int currentSequenceNumber = 1;
    cout << title;

    while(current != nullptr)
    {
        if(currentSequenceNumber == sequenceNumber)
        {
            cout << "\nwe are in the if statement";
            while(choice < 0 || choice > 3)
            {
                cout << "\nWhat do you want to update about " << title << "?";
                cout << "\n1. Title";
                cout << "\n2. Year viewed";
                cout << "\n3. Rating";
                cout << "\n...your choice: ";
                cin >> choice;
            }
            
            switch (choice)
            {
                case 1: {
                    string newTitle;
                    cin.ignore();
                    cout << "\nEnter the new title: ";
                    getline(cin, newTitle);
                    current->title = newTitle;
                    break;
                }
                case 2: {
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
                    head = current;
                    break;
                }
                case 3: {
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
                    head = current;
                    break;
                }
            }
            return;
        }
        current = current->next;
        currentSequenceNumber++;
    }
    
    cout << "\nNo movie with the title " << title << " was found" << endl;
}

void removeMovie(Movie*& head, string title, int sequenceNumber)
{
    Movie* current = head;
    Movie* previous = nullptr;
    int currentSequenceNumber = 1;
    while(current != nullptr)
    {
        if(currentSequenceNumber == sequenceNumber)
        {
            if(previous == nullptr)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
        currentSequenceNumber++;
    }
    cout << "\nNo movie with the title " << title << " was found." << endl;
}

void listMovies(Movie* head)
{
    cout << left << std::setw(5) << "#";
    cout << left << std::setw(40) << "Title" ;
    cout << left << std::setw(10) << "Viewed";
    cout << left << std::setw(10) << "Rating" << endl;
    cout << right << std::setfill('-') << std::setw(4) << " " << std::setw(40) << " " << std::setw(10) << " " << std::setw(10) << "\n";
    int count = 1;
    while(head != nullptr)
    {
        cout << std::setfill(' ') << left << std::setw(5) << count << left << std::setw(40) << head->title << left << std::setw(10) << head->year << left << std::setw(10) << head->rating << "\n";
        head = head->next;
        count++;
    }
}
void menu(Movie* head, int& sequenceNumber)
{
    char choice;
    string title;
    
    do
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
        cin >> choice;
        
        if(choice == 'A' || choice == 'a')
        {
            addMovie(head);
            sequenceNumber++;
        }
        else if(choice == 'U' || choice == 'u')
        {
            cout << "\nEnter the name of the movie you want to update: ";
            cin.ignore();
            getline(cin, title);
            updateMovie(head, title, sequenceNumber);
        }
        else if(choice == 'E' || choice == 'e')
        {
            cout << "\nEnter the name of the movie you want to remove: ";
            cin.ignore();
            getline(cin, title);
            removeMovie(head, title, sequenceNumber);
        }
        else if(choice == 'L' || choice == 'l')
        {
            listMovies(head);
        }
        else if(choice == 'T' || choice == 't')
        {
            //call some function to arrange by title
        }
        else if(choice == 'V' || choice == 'v')
        {
            //call some function to arrange by year viewed
        }
        else if(choice == 'R' || choice == 'r')
        {
            //call some function to arrange by rating
        }
    } while (choice != 'Q' && choice != 'q');
}
int main()
{
    Movie* head = nullptr;
    int sequenceNumber = 0;
    menu(head, sequenceNumber);
    return 0;
}
