/*****************************************************************************
*
*    Name:        Allen Pagan
*
*    Homework:    Project2
*
*    Class:       ICS 212
*
*    Instructor:  Ravi Narayan
*
*    Date:        November 22, 2014
*
*    File:        main.cpp
*
*    Description: This is a driver for Project2.cpp to test the address book
*                 functions,add record, modify record, print record, delete
*                 record, and reverse functions
******************************************************************************/

#include <iostream>
#include "record.h"
#include "main.h"
#include "llist.h"
using namespace std;

int main(int argc, char* argv[])
{
    #ifdef debugMode
    {
        printf("\n\n\t\t\tDEBUG MODE IS ON \n\n");
    }
    #endif



    llist mylist;

    char name [25];
    char address [80];
    char number [15];
    int birthYear = 0;
    int menuChoice;
    char extra;
    bool valid = false;
    int count;
    
    do
    {
        menuChoice = printMenu();
        switch(menuChoice)
        {
                        
            case 1 : 
                    
                cout << "Please enter name" << endl;
                cin.getline(name, 25, '\n');
                count = cin.gcount();
                if(count > 23)
                cin.ignore();
                         
                cout << "Please enter your address followed by an !\n";
                cin.getline(address,80, '!');
                
                cout << "Please enter the year of birth:\n";
                valid = false;
                while(!valid)
                {
                    valid = true;
                    cin >> birthYear;
    
                    if(cin.fail())
                    {  
                        valid = false;
                        cin.clear();
                        extra = cin.get();
                        while(extra != '\n')
                        {
                            extra = cin.get();
                        }
                        cout << "Invalid input, please enter a number:\n";
                    }
                    else
                    {
                        if(birthYear > 2014 || birthYear < 0)
                        {
                            cout << "Please enter valid year\n";
                            valid = false;
                        }
                    }
                }
                cin.get();
                
                cout << "Please enter the phone number:\n";
                cin.getline(number, 15, '\n');
                 
                mylist.addRecord(name, address, birthYear, number);
                break;
    
            case 2:
                cout << "Please enter name" << endl;
                cin.getline(name, 25, '\n');
                    
                cout << "Please enter your address followed by an !\n";
                cin.getline(address,80, '!');
                cin.get();
                     
                cout << "Please enter the phone number:\n";
                cin.getline(number, 15, '\n');
                
                if(mylist.modifyRecord(name, address, number) == 0)
                {           
                    cout << "There is no one named " << name << " in the address book\n\n" << endl;
                }
                else
                {
                
                  if(mylist.modifyRecord(name, address, number) == 2)
                    cout << "The address book is empty\n\n";
                }  
                
                break;
         
            case 3:
                cout << "Please enter the name:";
                
                cin.getline(name, 25, '\n');

                if(mylist.printRecord(name) == 0)
                {
                    cout << "There is no one named %s in the address book\n\n" << name << endl;
                }    
                
                break;
                
            case 4:
                            
                cout << mylist;
                break;
                
            case 5:
                cout << "Please enter the name:" << endl;
                cin.getline(name, 25, '\n');
                    
                mylist.deleteRecord(name);
                break;
                
            case 6:
                mylist.reverse();
                break;
        }       
    }while(menuChoice != 7);
        
                
     return 0;   
}                   
