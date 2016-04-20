#include <iostream>
class     llist
{
     private:
          record         *start;
          char           fileName[16];
          int            readFile();
          int            writeFile();
          record *       reverse(record *);
          void           cleanUp();

     public:
          llist();
          llist(char []);
          ~llist( );
           int addRecord(char[], char[], int, char[]);
           int printRecord(char [ ]);
           int modifyRecord(char[], char[], char[]);
          void printAllRecords();
          int deleteRecord(char []);
          void reverse();
          friend std::ostream& operator<<(std::ostream&, llist&);
};