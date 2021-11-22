#include <iostream>
#include "enigma.h"
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"
#include "helper.h"
using namespace std;


int main(int argc, char** argv){

  //Error codes:

  int error_code=0;

  if (argc<4){
    print_error(1);
    return 1;
  }
  
  
  
  Enigma enigma;
  enigma.initialiseEnigma(argc, argv, error_code);
  if (error_code!=0){
    print_error(error_code);
    return error_code;
  }
  
  char ch;
  while (!cin.eof()){
    cin >> ch;
    cin >> ws;
    if (ch > 64 && ch < 91){
      ch = enigma.encode(ch, error_code);
      if (error_code!=0){
	print_error(error_code);
	return error_code;
      }
      cout << ch;
    }
    else {
      print_error(2);
      return 2;
    }
  }
  
  //   ch = enigma.encode('D', error_code);
  //  cout << ch;
  return 0;
}


