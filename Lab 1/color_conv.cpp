#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   cout << "Enter 3 integers (red, green, and blue), in that order:";
   // Enter your code here
   double red, green, blue;
   cin >> red >> green >> blue;
   double cyan, magenta, yellow, black;
   double white;
   double maxOfRedGreen = max(red / 255.0, green / 255.0);
   white = max(maxOfRedGreen, blue / 255.0);
   cyan = (white - (red / 255.0)) / white;
   magenta = (white - (green / 255.0)) / white;
   yellow = (white - (blue / 255.0)) / white;
   black = 1 - white;

   cout << "cyan: " << cyan << endl;
   cout << "magenta: " << magenta << endl;
   cout << "yellow: " << yellow << endl;
   cout << "black: " << black << endl;
   
   
   
   
   return 0;
}
