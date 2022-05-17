#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char mystring[80] = "ComputerScience";
  char yourstring[80];
  char* astring = NULL;  //cant find address "container"
  //---------------------------------------

  //yourstring = mystring;  
  strncpy(astring, mystring, 80);

  astring = mystring; // make a copy? no, just referencing it
  strncpy(yourstring, mystring, 80); // make a copy?
  cout << astring << endl;
  cout << yourstring << endl;

  astring[0] = '*'; // which one actually made a copy?
  cout << mystring << endl;
  cout << yourstring << endl;

  return 0;
}
