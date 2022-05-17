/* Vaneet Saini 
  vsaini@usc.edu
  Program takes an integer of long long type and adds
  commas where appropriate
*/

/********************************************************
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;


int main()
{
  long long n;
  cout << "Enter an integer:" << endl;
  cin >> n;
  /*====================*/
  /* Start of your code */
  long long var;  

  if (n < 1000){
    cout << n << endl;   //prints n if less than 1000
  }

  if (n < 0){
    cout << '-';   //turns negative numbes positive
    n *= -1;
  }

  if (n == 0){
    cout << 0;   //prints 0 instead of nothing
  }
  
  long long digits = 1+(int)log10(n);   //amt of digits in n
  long long largestDiv = pow(10, (int)log10(n)); //largest divisor
  long long remain = (digits % 3);  //remainder of n 

  if (remain == 0){   //if digits is 3, 6, 9, etc
    remain = 3;      // triplet for determining , 
  }

  while(largestDiv != 0){  //true condition
    var = n / largestDiv;    
    largestDiv /= 10;
    remain -= 1;
    cout << var % 10;    //prints number 1 by 1
    if (remain == 0 && largestDiv != 0){
      cout << ',';  //adds comma when no more triplet 
      remain = 3;  //begins next triplet
    }
  }

  /* End of your code */
  /*==================*/
  
  return 0;
}
