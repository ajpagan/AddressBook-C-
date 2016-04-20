/*****************************************************************************
*
*    Name:        Allen Pagan
*
*    Homework:    Project 2
*
*    Class:       ICS 212
*
*    Instructor:  Ravi Narayan
*
*    Date:        November 22, 2014
*
*    File:        printMenu.cpp
*
*    Description: Displays the menu for main.cpp and gets user menu selection
******************************************************************************/

#include <iostream>
using namespace std;

/*******************************************************************************
*
*  Function name:       printMenu
*
*  DESCRIPTION:         A userinterface function - This function displays the menu for the
*                       user and obtains their selection
*
*  Parameters:          none
*
*  Return values:       The option on the menu must be a number (1-7)
*
******************************************************************************/

int printMenu()
{
    int menuChoice = 0;
    char extra;
    do
    {
        cout << "\t\t Address Book Menu Options\n";
        cout << "(1)  Add a new record to the database.\n";
        cout << "(2)  Modify a record in the database using the name as the key.\n";
        cout << "(3)  Print information about a record using the name as the key.\n";
        cout << "(4)  Print all information in the database.\n";
        cout << "(5)  Delete an existing record from the database using the name as a key.\n";
        cout << "(6)  Reverse order of the list: \n";
        cout << "(7)  Quit.\n";
        cout << "Please enter the number of your menu choice.\n";
        cin >> menuChoice;
        if(cin.fail())
        {
            cin.clear();
 
        }
        extra = cin.get();
        while(extra != '\n')
        extra = cin.get();
    }while(menuChoice != 1 && menuChoice != 2 && menuChoice != 3 &&
    menuChoice != 4 && menuChoice != 5 && menuChoice != 6 && menuChoice != 7);
 
    return menuChoice;
}  

