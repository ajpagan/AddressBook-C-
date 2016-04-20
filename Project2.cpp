#include <string.h>
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
*    File:        Project2.cpp
*
*    Description: Holds all the method calls for Project2.cpp which include add
*                 record, modify record, delete record, print record,
*                 write file, read file and clean up, along with the constructer
*                 de-constructer and reverse methods
******************************************************************************/


#include "record.h"
#include "llist.h"
#include <iostream>
#include <fstream>
using namespace std;

/*******************************************************************************
*
*  Function name:       addRecord
*
*  DESCRIPTION:         adds a record to the "address book"
*
*  Parameters:          name (char*): Name of the person
*                       address (char*): Address of person
*                       birthYear (int): Year the person was born
*                       number (char*): Telephone number of the person
*
*  Return values:        0 : success
*
******************************************************************************/

int llist::addRecord(char name[], char address[], int birthYear, char number[])
{
        #ifdef debugMode
        {
            cout << "\n(Add Record) Name: " <<  name << endl;
            cout << "(Add Record) Address: " << address << endl;
            cout << "(Add Record) Year of birth: " << birthYear << endl;
            cout << "(Add Record)Telephone number: " <<  number << endl;
        }
        #endif

        struct record *contact;
        contact = start;
 

        if((start) == NULL)
        {
            start = new (struct record);

            strcpy((*start).name, name);

            strcpy((*start).address, address);
 
            (*start).birthYear = birthYear;
 
            strcpy((*start).number, number);

            (*start).next = NULL;
        }
        else
        {
            while((*contact).next != NULL)
            {
                contact = (*contact).next;
            }
            
            (*contact).next = new (struct record);
        
            strcpy((*contact).next->name, name);
        
            strcpy((*contact).next->address, address);
 
            (*contact).next->birthYear = birthYear;
        
            strcpy((*contact).next->number, number);
            
            (*contact).next->next  = NULL;
        }

        return 0;
}
            
 
/*******************************************************************************
*
*  Function name:      printRecord
*
*  DESCRIPTION:        prints a record from the "address book" using the name as the key
*
*  Parameters:         name (char*): Name of the person
*
*  Return values:      0 : success
******************************************************************************/

nt llist::printRecord(char name[])
{
    int found = 0;
         
    #ifdef debugMode
    {   
        cout << "(Print Record) \n(Debug) Name: " << name << endl;
    }
    #endif

    struct record *contact;
    contact = start;
            
    if(start != NULL)
    {
        while(contact != NULL)
        {
            if(strcmp(contact->name, name) == 0)
            {
                cout << "Name:    " <<  (*contact).name << endl;
                cout << "Address: " << (*contact).address << endl;
                cout << "Birth:   " << (*contact).birthYear << endl;
                cout << "Number:  " << (*contact).number << endl;
                contact = contact ->next;
                found = 1;
 
            }
            else
            {
                contact = contact->next;
            }
        }
    }
    else
    {
        found = 2;
    }
     
    return found;
}
    
    
/*******************************************************************************
*
*  Function name:      modifyRecord
*
*  DESCRIPTION:        Modifys a record to the "address book"
*
*  Parameters:         name (char*): Name of the person
*                      address (char*): Address of person
*                      number (char*): Telephone number of the person
*
*  Return values:      0 : success
*
******************************************************************************/

int llist::modifyRecord(char name[], char address[], char number[])
{
    int found = 0;
    #ifdef debugMode
    {
        cout << "\n(Modify Record) Name: " <<  name << endl;
        cout << "(Modify Record) Address: " << address << endl;
        cout << "(Modify Record) Telephone number: " << number << endl;
    }       
    #endif
     
    struct record *contact;   
    contact = start;
            
    if(start != NULL)
    {
        while(contact != NULL)
        {
            if(strcmp(contact->name, name) == 0)
            {
                
                strcpy((*contact).name, name);
                strcpy((*contact).address, address);
                strcpy((*contact).number, number);
             
                found = 1;
                contact = contact->next;
         
            }
            else
            {
                contact = contact->next;
     
            }
        }
    }
    else
    {
        found = 2;
    }

    return found;
}


/*******************************************************************************
*
*  Function name:      printAllRecords
*
*  DESCRIPTION:        Prints all the records in the "address book"
*
*  Parameters:
*
*  Return values:      0: success
*                      1: No records
*
******************************************************************************/

void llist::printAllRecords()
{
    struct record *contact;
    contact = start;
         
    #ifdef debugMode
    {   
        cout << "(Print All Records)\n";
    }
    #endif
     
    if(start != NULL)
    {
        while(contact != NULL)
        {
            cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
            cout << "Name:    " <<  (*contact).name << endl;
            cout << "Address: " << (*contact).address << endl;
            cout << "Birth:   " << (*contact).birthYear << endl;
            cout << "Number:  " << (*contact).number << endl;
            cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
            cout << "\n";
            contact = contact -> next;

        }
    }
    else
    {
        cout << "No records available\n";
    }
    
}
     
    
/*******************************************************************************
*
*  Function name:      deleteRecord
*
*  DESCRIPTION:        Deletes a the record in the "address book" using the name as the key
*
*  Parameters:
*
*  Return values:      0 Success
*
******************************************************************************/

int llist::deleteRecord(char name[])
{
    #ifdef debugMode
    {
        cout << "\n(Delete Record)\n Name: " << name << endl;
    }
    #endif
    
    struct record* searchContact;
    struct record* previousContact;
    searchContact = start;
    previousContact = start;
    int found = 0;
    if(start != NULL)
    {
        while(searchContact != NULL)
        {
            if(strcmp((*start).name, name) == 0)
            {
                searchContact = (*start).next;
 
                delete start;
 
                (start) = searchContact;
                found = 1;
            }
            else
            {
                while(searchContact != NULL)
                {
                    if(strcmp((*searchContact).name, name) == 0)
                    {
                        (*previousContact).next = (*searchContact).next;
     
                        delete searchContact;
    
                        searchContact = (*previousContact).next;
                    }
                    else  
                    {
                        previousContact = searchContact;
                        searchContact = (*searchContact).next;
                    }
                }
         
            }
        }
    }
 
    return found;
}

/*******************************************************************************
 *
 *  Function name:      writeFile
 *
 *  DESCRIPTION:        Writes all the contacts in the "address book" to a designated file
 *
 *  Parameters:         int (error status)
 *
 *  Return values:      none
 *
 ******************************************************************************/

int llist::writeFile()    
{
    struct record *contact;
    contact = start;
    ofstream file(fileName);
    int open = 1;
         
    if(file.is_open())
    {
        if(start != NULL)
        {
            file << "\n";
 
            while(contact != NULL)
            {   
                file << "\n";
                file << (*contact).name << endl;
                file << (*contact).address << '!'  << endl;
                file << (*contact).birthYear << endl;
                file << (*contact).number << endl;
                contact = contact -> next;
            }
        }
    }
    else
    {
        open = 2;       
    }                

    file.close();
    return open;
}
    
    
/*******************************************************************************
*
*  Function name:      readFile
*
*  DESCRIPTION:        Reads all the records from the designated file
*
*  Parameters:
*
*  Return values:      0 Success
*
******************************************************************************/

int llist::readFile()
{
    int found = 0;
    char name[25];
    char address[80];
    int birthYear;
    char number[15];    
                     
    ifstream file (this->fileName);
    
    char letter;
    if(file.is_open())
    {
        if(file.get() != EOF)
        {
            if(file.get() == '\n')
            {
 
                do
                {
                    file.getline(name, 25, '\n');
 
                    file.getline(address,80,'!');
 
                    file >> birthYear;
                
                    file.get(letter);
                
                    file.getline(number, 15, '\n');
 
                    addRecord(name,address,birthYear,number);
    
                }while(file.get() != EOF);
    
            }
        }            
        else
        {
            found = 1;
        }
    }
    return found;
}

             
/*******************************************************************************
 *
 *  Function name:      cleanUp
 *
 *  DESCRIPTION:        Goes through all records and deletes each one from the heap
 *
 *  Parameters:         start (struct record**)
 *
 *  Return values:      none
 *
 ******************************************************************************/
                    
 
void llist::cleanUp()
{   
    struct record *contact;
    contact = start;
             
    if(start != NULL)
    {
        while(contact != NULL)
        {
            free(contact);
            contact = contact -> next;
        }
    start = NULL;
    }       
             
}

/*******************************************************************************
 *  
 *  Function name:      reverse
 *  
 *  DESCRIPTION:        Reverses the order of the list
 *  
 *  Parameters:
 *
 *  Return values:      none
 *
 ******************************************************************************/
    
    
void llist::reverse()
{            
    struct record *contact;
    contact = start;
        
    if(start->next != NULL)
    {
        reverse(contact);
    }
    
}

/*******************************************************************************
 *
 *  Function name:      operator<< (operator overload)
 *
 *  DESCRIPTION:        Function to overload the << operator
 *
 *  Parameters:         ostream , llist
 *
 *  Return values:      none
 *
 ******************************************************************************/

std::ostream& operator<< (std::ostream& os, llist& list)
{   
    struct record *contact;
    contact = list.start;
    
    #ifdef debugMode
    {   
        cout << "(Print All Records)\n";
    }
    #endif
     
    if(list.start != NULL)
    {
        while(contact != NULL)
        {
            os << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
            os << "Name:    " <<  (*contact).name <<endl;
            os << "Address: " << (*contact).address << endl;
            os << "Birth:   " << (*contact).birthYear << endl;
            os << "Number:  " << (*contact).number << endl; 
            os << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
            os << "\n";
            contact = contact -> next;
 
        }
    }
    else
    {
        cout << "No records available\n";
    }
    
    return os;
}

/*******************************************************************************
 *   
 *  Function name:      private reverse
 *   
 *  DESCRIPTION:        Function to overload the << operator
 *   
 *  Parameters:         recird pointer
 *
 *  Return values:      none
 *
 ******************************************************************************/
            
record* llist::reverse(struct record *contact)
{
    if(contact->next == NULL)
    {
        start = contact;
    }
    else
    {   
        reverse(contact -> next);
        (*contact->next).next = contact; 
        contact->next = NULL;
    }
    
    return(NULL);
} 

/*******************************************************************************
*
*  Function name:      llist constructor
*
*  DESCRIPTION:        Initiates the list to Null, gets th name of the file and
*                       calls readFile
* 
*  Parameters:
* 
*  Return values:      none
*           
******************************************************************************/
 
llist::llist()
{
    this->start = NULL; 
    strcpy(fileName, "Project2.txt");
    readFile();
}
        
        
/*******************************************************************************
*
*  Function name:      llist de-constructer
*
*  DESCRIPTION:        calls the writefile and clean up methods
*       
*  Parameters:
*
*  Return values:      none
*  
******************************************************************************/

llist::~llist()
{ 
    writeFile();
    cleanUp();
}