/* Vaneet Saini
 vsaini@usc.edu
 This program finds the length of a number,
 the number of steps it took to get to 1,
 using hailstone sequences
 */

#include <iostream>
using namespace std;

int main(){

  int num;
  cout << "Enter a number: ";
  cin >> num;
  cout << endl;

  int count = 0;

  while (num != 1){       //true condition
    if (num % 2 == 0){  // even condition 
      num /= 2;
      cout << num <<  ' ';
      count++;    //add to count to find length 
    }

    else if (num % 2 == 1){  //odd condition
      num = (num * 3) + 1;
      cout << num << ' ';
      count++;    //add to count to find length 
    }

    else if (num == 1){  //break loop if 1
      break;
    }
  }
  cout << endl;
  cout << "Length: " << count << endl;
  return 0;
}
