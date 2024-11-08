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

void addMovie(Movie* head)
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
            //call some function to update movie
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