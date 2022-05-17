#include <iostream>
using namespace std;

int main(){
  int digit;
  cout << "Enter an integer between 0 and 999: ";
  cin >> digit;
  cout << endl;
  int ones = (digit % 10);
  int tens = ((digit / 10) % 10);
  int hundreds = (digit / 100);
  cout << "1's digit is " << ones << endl;
  cout << "10's digit is " << tens << endl;
  cout << "100's digit is " << hundreds << endl;


  return 0;
}
