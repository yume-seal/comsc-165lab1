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

void updateMovie(Movie*& head, string title)
{
    Movie* current = head;
    int choice = -1;
    cout << title;

    while(current != nullptr)
    {
        if(current->title == title)
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
                    cout << "\nEnter the new title: ";
                    cin >> newTitle;
                    current->title = newTitle;
                    break;
                }
                case 2: {
                    int year;
                    cout << "\nEnter the new year: ";
                    cin >> year;
                    current->year = year;
                    head = current;
                    break;
                }
                case 3: {
                    int rating;
                    cout << "\nEnter the new rating: ";
                    cin >> rating;
                    current->rating = rating;
                    head = current;
                    break;
                }
            }
            return;
        }
        current = current->next;
    }
    
    cout << "\nNo movie with the title " << title << " was found" << endl;
}

void menu(Movie* head)
{
    char choice;
    
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
        }
        else if(choice == 'U' || choice == 'u')
        {
            string title;
            cout << "\nEnter the name of the movie you want to update: ";
            cin.ignore();
            getline(cin, title);
            updateMovie(head, title);
        }
        else if(choice == 'E' || choice == 'e')
        {
            //call dome function to remove a movie
        }
        else if(choice == 'L' || choice == 'l')
        {
            //call some function to list all movies
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
    menu(head);
    return 0;
}
