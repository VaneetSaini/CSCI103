#include "bigint.h"
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

//******************************************************************
//START OF THE CONSTRUCTORS SECTION
//******************************************************************

/*
// Create a default BigInt with base 10.
// This function is complete. You do not have to add anything.
*/
BigInt::BigInt(){
  base = 10;
  isPositive = true;
}

/*
// Create a BigInt with a specified base.
// This function is complete. You do not have to add anything.
*/
BigInt::BigInt(int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    base = setbase;
    isPositive = true;
}

/*
// Destructure. You do not have to add anything.
// This function is complete
*/
BigInt::~BigInt(){}

/*
//  Create a BigInt from string.
//  Don't forget to set the base accordingly
//  The input string will contain
//      - numbers (0-9) and/or 
//      - uppercase letters (A-Z) [A=10, B=11, ... , Z=35]
//  The input string may contain
//      - a negative sign ('-') to signify that the number is negative.
//  Note: char '0' = int 48 (see ASCII table)
//  Note: char 'A' = int 65
*/
BigInt::BigInt(const string &s, int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
    int last = 0;  //depends if neg or not 

    if (s[0] == '-'){  //if first char is a s-, isPositive = false
      isPositive = false;
      last = 1;
    }
    else isPositive = true;

    int dec_num; int char_to_num; int temp1; int temp2; 
    int x = 0;
    base = setbase;

    for (int i = s.size() - 1; i >= last; i--){
      dec_num = ((int)(s[i]) - '0');  //convert to int
      char_to_num = ((int)(s[i])  - '0' - 7);//convert char to number 
      if (dec_num < 10){
        if (x == 0){
          vec.push_back(dec_num);
        }
        else if (x != 0){
          dec_num += x;
          if (dec_num < 10){
            vec.push_back(dec_num);
          }
          else{
            temp1 = dec_num / base;
            temp2 = dec_num % base;
            vec.push_back(temp2);
            x = temp1;
          }
        }
      }
      else{
        temp1 = char_to_num / base;
        temp2 = char_to_num % base;
        if (x != 0){
          temp2 += x;
        }
        vec.push_back(temp2);
        x = temp1;
      }
    }

    if (x != 0){
      vec.push_back(x);
    }
}


/*
//  Create a BigInt from int (base 10).
//  - Convert the int (base 10) input into a specified base (setbase).
//  - Don't forget to set the base accordingly
//  For example:
//     BigInt k(6,2) <- int 6 base 10 to BigInt base 2
//          - Result:  BigInt k with value 110 (base 2)
//     BigInt k(154,16) <- 154 base 10 to BigInt base 16
//          - Result: BigInt k with value 9A (base 16)
*/
BigInt::BigInt(int input,int setbase){
   if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    } 
    /************* You complete *************/
  base = setbase;
  if (input == 0){
    vec.push_back(0);
  }
  int remainder;
  if (input < 0){
    isPositive = false;
    remainder = -input;
  }
  else{
    isPositive = true;
    remainder = input;
  }
  while (remainder > 0){
    int temp = remainder % base;
    vec.push_back(temp);
    remainder /= base;
  }
}

/*
//  Create a BigInt from another BigInt.
//  This is a copy constructor.
//  Simply call the assignment operator (=) below.
// (You can also think of this function as the same as the assignment operator (=))
// (but without a return statement because you are overriding the current object)
*/
BigInt::BigInt(const BigInt &b){

    /************* You complete *************/
  *this = b;

}

/*
//  Assignment operator. (i.e., BigInt a = b;)
//  OVERRIDING a's data with BigInt b's data
//       - vec
//       - isPositive
//       - base
*/
BigInt & BigInt::operator = (const BigInt &b){

    /************* You complete *************/
  vec = b.vec;
  isPositive = b.isPositive;
  base = b.base;

    return *this; 
}


//******************************************************************
//END OF THE CONSTRUCTORS SECTION
//******************************************************************

//******************************************************************
//START OF THE DISPLAYS SECTION
//******************************************************************

/*
// Convert to string and return the string
// Display it in its corresponding base
//  Note: char '0' = int 48 (see the ASCII table)
//  Note: char 'A' = int 65
*/
string BigInt::to_string(){

    /************* You complete *************/
    int strlen = vec.size();

    string x = ""; 
    if (!isPositive){
      x += '-'; //neg sign 
    }
    for (int i = strlen - 1; i >= 0; i--){
      if (vec[i] < 10){   //0 to 9
        x += (char)(vec[i] + 48);  //vec[i] to char
      }
      else {
        x += (char)(55+vec[i]);  //if letter 
      }
    }

    return x;
}

/*
//  Convert BigInt to integer base 10 and return that int
//    If BigInt >= INT_MAX, return INT_MAX.
//    If BigInt =< INT_MIN, return INT_MIN.
//  Note: 1. INT_MAX and INT_MIN are already defined for you
//           in the 'climits' library.
//        2. INT_MAX = 2147483647, INT_MIN = -2147483648
//           therefore, INT_MIN does not equal to (-INT_MAX)
*/
int BigInt::to_int() const{

    /************* You complete *************/
  double num = 0; int j = 0;
  int len = vec.size();
  for (int i = 0; i < len; i++){
    num += vec[i] * pow(base, j);
    j++;
  }
  if (!isPositive) num *= -1;
  if (num <= INT_MIN) return INT_MIN;
  else if (num >= INT_MAX) return INT_MAX;
  else return num;
  
}

//******************************************************************
//END OF THE DISPLAYS SECTION
//******************************************************************

//******************************************************************
//START OF THE EQUALITY CHECK OPERATORS SECTION
//******************************************************************

/*
//  Compare a and b.
//     If a = b, return 0.
//     If a < b, return -1.
//     If a > b, return 1.
//  See the HINT below
*/
int BigInt::compare(const BigInt &b) const{
    if(base != b.base){
        throw DiffBaseException();
    }


    /************* You complete *************/

    //HINT:
    //1. do NOT call the to_int() or to_string() function
    //2. do NOT convert bigInt to other datatypes first (e.g., long long, int)
    
    //First let's compare the signs
    //    - if the signs aren't the same,
    //              how do you know which one is larger?
    if (isPositive && !b.isPositive) return 1;
    if (!isPositive && b.isPositive) return -1;
    //If they have the same sign, let's compare their vec sizes 
    //    - what if both are positive, but a's vec is larger (a or b is larger?)
    //    - other cases?
    if (isPositive && b.isPositive){
      if (vec.size() > b.vec.size()){
        return 1;
      }
      else if (vec.size() < b.vec.size()){
        return -1;
      }
    }

    if (!isPositive && !b.isPositive){
      if (vec.size() < b.vec.size()){
        return 1;
      }
      else if (vec.size() > b.vec.size()){
        return -1;
      }
    }
    //If they have the same vec size, let's compare their digits one by one
    // Starting from the most-significant digits. --> in what vector position?
    // Remember that the BigInt vectors are in reverse order!
    //    - what if both are positive, but the digit of a is greater than that of b (a or b is larger?)
    //    - other cases?
    if (vec.size() == b.vec.size()){
      if (isPositive && b.isPositive){
        for (int i = vec.size() - 1; i >= 0; i--){
          if (vec[i] > b.vec[i]){
            return 1;
          }
          else if (vec[i] < b.vec[i]){
            return -1;
          }
        }
      }
      else if (!isPositive && !b.isPositive){
        for (int i = vec.size() - 1; i >= 0; i--){
          if (vec[i] > b.vec[i]){
            return -1;
          }
          else if (vec[i] < b.vec[i]){
            return 1;
          }
        }
      }
    }
    //If ALL digits are the same, then they MUST be equal!!
    return 0;
}


//Call the compare function above to check if a == b
bool operator == (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
    if (a.compare(b) == 0){
      return true;
    }
    else return false;
}

//Call the compare function above to check if a != b
bool operator != (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
  if (a.compare(b) != 0){
    return true;
  }
  else return false;
}

//Call the compare function above to check if a <= b
bool operator <= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
  if (a.compare(b) == 0 || a.compare(b) == -1){
    return true;
  }
  else return false;

}

//Call the compare function above to check if a >= b
bool operator >= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
  if (a.compare(b) == 0 || a.compare(b) == 1){
    return true;
  }
  else return false;
  
}

//Call the compare function above to check if a > b
bool operator > (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
  if (a.compare(b) == 1){
    return true;
  }
  else return false;
}

//Call the compare function above to check if a < b
bool operator < (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/
  if (a.compare(b) == -1){
    return true;
  }
  else return false;

}

//******************************************************************
//END OF THE EQUALITY CHECK OPERATORS SECTION
//******************************************************************

//******************************************************************
//START OF THE ARITHMETIC OPERATORS SECTION
//******************************************************************

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call += operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator + (const  BigInt &a, const BigInt & b){

  /************* You complete *************/
  BigInt temp = a;
  temp += b;
  return temp;

}

/*
//==================
// MEMBER function
//==================
//  Addition assignment operator.
//    i.e., a += b
*/
const BigInt & BigInt::operator += (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    int carried = 0;
    int thisNum = 0; int bNum = 0;
    unsigned int n = vec.size(); 
    unsigned int m = b.vec.size();
    if (isPositive != b.isPositive){
      if (isPositive && !b.isPositive){
        BigInt copy = b;
        copy.isPositive = true;
        *this -= copy;
      }
      else if (!isPositive && b.isPositive){
        isPositive = true;
        *this -= b;
        if (vec[0] == 0 && vec.size() == 1){
          isPositive = true;
        }
        else{
          isPositive = !isPositive;
        }
      }
      return *this;
    }
    else if (isPositive == b.isPositive){
      unsigned int len = max(n, m);
      int s = 0;
      for (unsigned int i = 0; i < len; i++){
        if (i < vec.size()){
          thisNum = vec[i];
        }
        else thisNum = 0;
        
        if (i < b.vec.size()){
          bNum = b.vec[i];
        }
        else{
          bNum = 0;
        }
        s = thisNum + bNum + carried;
        if (s >= base){
          carried = s / base;

        }
        else if(s < base){
          carried = 0;
        }
        if (i < vec.size()){
          vec[i] = s %  base;
        }
        else{
          vec.push_back(s % base);
        }
      }
      if (carried != 0){
        vec.push_back(carried);
      }
      return *this;
    }
      
  return *this;
}


//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call -= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code

BigInt operator - (const  BigInt &a, const BigInt & b){

  /************* You complete *************/
  BigInt temp = a;
  temp -= b;
  return temp; 
  
}

/*
//==================
// MEMBER function
//==================
//  Subtraction assignment operator.
//    i.e., a -= b
//  Note: Think of base cases (e.g., subtract by itself)
*/
const BigInt & BigInt::operator -= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    unsigned int n = vec.size();
    unsigned int m = b.vec.size();
    unsigned int len = max(n, m);
    bool pos;
    if (*this >= b){
      pos = true;
    }

    else{
      pos = false;
    }
    BigInt zero(0, base); //0 bigint for comparison
    int carried = 0;

    if (isPositive != b.isPositive){
      if (isPositive && !b.isPositive){
        BigInt copy = b;
        copy.isPositive = true;
        *this += copy;
      }
      else if (!isPositive && b.isPositive){
        isPositive = true;
        *this += b;
        isPositive = false;
      }
    }
    else if (isPositive == b.isPositive){
      int s = 0;
      int thisNum = 0; int bNum = 0;
      if (*this == b){
        *this = zero;
        return *this;
      }
      if (b == zero){
        return *this;
      }
      for (unsigned int i = 0; i < len; i++){
        if (i < n) thisNum = vec[i];
        else thisNum = 0;
        if (i < m) bNum = b.vec[i];
        else bNum = 0;

        if (isPositive){
          if (pos){
            s = thisNum - bNum - carried;
          }
          else{
            s = bNum - thisNum - carried;
          }
        }
        else {
          if (pos){
            s = bNum - thisNum - carried;
          }
          else  s = thisNum - bNum - carried;
        }
        if (s < 0){
          s += base;
          carried = 1;
        }
        else carried = 0;
        if (i < n){
          vec[i] = s;
        }
        else{
          vec.push_back(s);
        }
      }
      if (!pos && isPositive){
        isPositive = !isPositive;
      }
      else if (pos && !isPositive){
        isPositive = !isPositive;
      }
    }
    for (unsigned int i = vec.size()-1; i > 0; i--){
      if (vec[i] == 0){
        vec.pop_back();
      }
      else{
        break;
      }
    }
    
  
  return *this;
}
 
/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call *= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator * (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
    BigInt temp = a;
    temp *= b;
    return temp;
    
}



/*
//==================
// MEMBER function
//==================
//  Multiplication assignment operator.
//    i.e., a *= b
//  Implement Long Multiplication
//  Note: What are the base cases?? (e.g., multiply by 0)
*/
const BigInt & BigInt::operator *= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
    unsigned int n = vec.size(); 
    unsigned int m = b.vec.size();
    BigInt output(base);
    int product = 0; int carried = 0;
    bool positiveResult = ((!isPositive && !b.isPositive) || (isPositive && b.isPositive));
    
    for (unsigned int i = 0; i < n; i++){
      string temp(i, '0');
      BigInt newbig(temp, base);
      for (unsigned int j = 0; j < m; j++){
        product = vec[i] * b.vec[j];
        if (carried > 0){
          product += carried;
        }
        if (carried >= base){
          carried = product/base;
          product -= (base*carried);
        }
        else{
          carried = 0;
        }
        newbig.vec.push_back(product);

        if (carried > 0 && j == n-1){
          if (carried > base){
            newbig.vec.push_back(carried-base+1);
          }
          else{
            newbig.vec.push_back(carried);
          }
          break;
        }
      }
      output += newbig;
      carried = 0;
    }
    output.isPositive = positiveResult;
    if (output.vec.size() == 1 && output.vec[0] == 0){
      output.isPositive = true;

    }
    if ((vec.size() == 1 && vec[0] == 0) || (b.vec.size() == 1 && b.vec[0] == 0)){
      output.isPositive = true;
      while (output.vec.size() != 1){
        output.vec.pop_back();
      }
    }
    *this = output;
    return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call /= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator / (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
    BigInt temp = a;
    temp /= b;
    return temp;

}


/*
//==================
// MEMBER function
//==================
//  Division assignment operator.
//    - Call 'divisionMain' to get the quotient;
*/
const BigInt & BigInt::operator /= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    /************* You complete *************/
    BigInt q(base);
    BigInt r(base);
    divisionMain(b, q, r);

    *this = q;
  
    return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call %= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator % (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
    BigInt temp = a;
    temp %= b;
    return temp;
  
}


/*
//============---===
// MEMBER function
//===-----==========
//  Modulus assignment operator.
//    - Call 'divisionMain' to get the remainder;
//    - Note: remainder takes the sign of the dividend.
*/
const BigInt & BigInt::operator %= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();//divide by zero.
    }
    /************* You complete *************/
    BigInt q(base);
    BigInt r(base);

    divisionMain(b, q, r);
    *this = r;
  
    return *this;
}

/*
//  Main function for the Division (/=) and Modulus (%=) operators.
//     - Compute (q)uotient and (r)emainder
//     - Implement Long Division
//  Note: 1. This should behave like integer division
//        2. What are the base cases?? (e.g., div by itself)
*/
void BigInt::divisionMain(const BigInt &b, BigInt &quotient, BigInt &remainder){

    /************* You complete *************/
    /*unsigned int n = vec.size();
    unsigned int m = b.vec.size(); */
    bool resultingSign;
    if (isPositive == b.isPositive){
        resultingSign = true;  //same sign, positive 
    }
    else {
        resultingSign = false;  //not same sign, negative
    }
    bool thisSign = isPositive;
    isPositive = true;
    BigInt zero(0, base); BigInt one(1, base);
    if (b.vec.size() == 1 && b.vec[0] == 1){
        quotient = *this;   //if divide by 1 
        quotient.isPositive = resultingSign;
        remainder = zero;
        return;
    }
    
    if (*this == zero){  //0 0/something = 0
        quotient = zero;
        remainder = zero;
        remainder.isPositive = thisSign;
        return;
    }
    BigInt copy = b;  //make positive copy of b 
    copy.isPositive = true;
     if (*this == copy){  //divide by itself is one 
        quotient = one;
        quotient.isPositive = resultingSign; //sign depends 
        remainder = zero;
        return;
    }
    
    if (*this < copy){  //integer division 
        quotient = zero;
        remainder = *this;
        remainder.isPositive = thisSign;
        return;
    }
    
    int pos = vec.size() - 1;  //last 
    BigInt k(vec[pos], base); //bigint k with input vec[pos]
    while (k < copy){
        pos--;
        k.vec.insert(k.vec.begin(), vec[pos]); 
    }
    while (pos >= 0){
        int count = 0;
        while (k >= copy){
            k -= copy;
            count++;
        }
        quotient.vec.insert(quotient.vec.begin(), count);
        if (k.vec.size() == 1 && k.vec[0] == 0) {
            k.vec.pop_back(); 
        }
        if (pos - 1 >= 0){
            k.vec.insert(k.vec.begin(), vec[pos -1]);
        }
        pos--;
    }
    if (k.vec.empty()){
        remainder.vec.push_back(0);
        remainder.isPositive = true;
    }
    else{
        remainder = k;
        remainder.isPositive = thisSign;
    }
    quotient.isPositive = resultingSign;  //put on sign at end
}



/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call the 'exponentiation' function on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt pow(const  BigInt &a, const BigInt & b){

    /************* You complete *************/
    BigInt temp = a;
    temp = temp.exponentiation(b);
    return temp;
  
}

/*
//==================
// MEMBER function
//==================
//  Exponentiation assignment function.
//     - i.e., a.exponentiation(b);
// Note: 1. implement Exponentiation by Squaring (see the writeup)
//       2. b should be treated as BigInt, not int or other data type.
*/
const BigInt & BigInt::exponentiation(const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
    BigInt power = b;
    BigInt zero(0, base);
    BigInt one(1, base);  //create bigints to use for comparison
    BigInt two(2, base);

    BigInt output(1, base);
    while (power > zero){
      if (power % two == zero){  //if even 
        *this *= *this;
        power /= two;
      }
      else{
        power -= one;
        output *= *this;
      }

    }
    *this = output;  
  
    return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call the 'modulusExp' function on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt modPow(const BigInt &a, const BigInt &b, const BigInt &m){

    /************* You complete *************/  
  BigInt temp = a;
  temp = temp.modulusExp(b, m);
  return temp;
}


/*
//==================
// MEMBER function
//==================
//  Modulus Exponentiation assignment function.
//     - i.e., a.modulusExp(b)
// Note: 1. implement Modulus Exponentiation (see the writeup)
//       2. b should be treated as BigInt, not int or other data type.
// Hint: same implementation as exponentiation, but take modulus 
//          after every call to the *= operator.
*/
const BigInt & BigInt::modulusExp(const BigInt &b, const BigInt &m){
    if(base != b.base || base != m.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
    BigInt power = b;
    BigInt zero(0, base);  //bigint for 0
    BigInt one(1, base);   //bigint for 1
    BigInt two(2, base);    //bigint for 2

    BigInt output(1, base);   //the output

    while (power > zero){      
      if (power % two == zero){  //if even
        *this *= *this;   
        *this %= m;
        power /= two;
      }
      else{
        power -= one;
        output *= *this;
        output %= m;
      }
    }

    *this = output;
  
    return *this;
}

//******************************************************************
//END OF THE ARITHMETIC OPERATORS SECTION
//******************************************************************

//******************************************************************
//START OF SANITY CHECK FUNCTIONS
//YOU CAN USE THEM, BUT DO NOT CHANGE ANYTHING
//THESE FUNCTIONS ARE COMPLETE.
//******************************************************************
void BigInt::printVecItems(){
  cout<<"[";
  for(size_t i = 0;i<vec.size();i++){
    cout<<vec[i];
    if(i < vec.size()-1){
      cout<<",";
    }
  }
  cout<<"]"<<endl;
}

bool BigInt::getSign(){
	return isPositive;
}

int BigInt::getBase(){
	return base;
}
//******************************************************************
//END OF SANITY CHECKS SECTION
//******************************************************************
