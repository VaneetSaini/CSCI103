#include "bigint.h"
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout<<"\033[1;41m----Missing an argument----\033[0m"<<endl;
	  cout << "Usage: ./decipher <file>"<<endl;
	  cout << "Examples:" << endl;
	  cout << "\t./decipher secret/message1.txt \033[1;90m//to decipher message 1\033[0m" << endl;
	  cout << "\t./decipher secret/message2.txt \033[1;90m//to decipher message 2\033[0m"<<endl;
		return -1;
	}

	/************* You complete *************/
	try{
    int base;
    string decodeThis;
    string d;
    string n;
    BigInt cracked_code;

    ifstream input_file;
    input_file.open(argv[1]);  //open and read file 

    input_file >> base >> d >> n;  //read in base, key, mod
    BigInt privateKey(d, base); //create BigInts for key and mod
    BigInt modulus(n, base);
    while (input_file >> decodeThis){  //read in the messages 
      BigInt secret_code(decodeThis, base);
      cracked_code = modPow(secret_code, privateKey, modulus); //formula 
      cout << (char)cracked_code.to_int();
    }
    cout << endl;

  }
  catch(const exception& e){   //error handling 
    cout << e.what() << endl;
    return -1;
  }
	

  
	return 0;
}
