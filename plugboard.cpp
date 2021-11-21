#include "plugboard.h"
#include "helper.h"
#include <iostream>
#include <fstream>
using namespace std;

void Plugboard::initialisePlugboard(char* plug_file, int& error_code){
  for (int i=0; i<26; i++){
    output_letters[i]=i;
  }
  ifstream in;
  int letter_a;
  int letter_b;
  in.open(plug_file);
  if (in.fail()){
    in.close();
    error_code=11;
    return;
  }
  //char test[10];
  while (!in.eof()){
    /*  in >> test;
    if (nonnumericCharacter(test)){
      error_code=4;
      return;
    }
    if (outsideBounds(test)){
      error_code=3;
      return;
    }
    
    letter_a = makeInt(test);
  
    in >> test;
    
      if (nonnumericCharacter(test)){
      error_code=4;
      return;
    }
    if (outsideBounds(test)){
      error_code=3;
      return;
    }
    
    letter_b = makeInt(test);
  */
    in >> letter_a;
    in >> letter_b;
    if (letter_a < 26 && letter_a >=0 && letter_b < 26 && letter_b >=0){
      output_letters[letter_a]=letter_b;
      output_letters[letter_b]=letter_a;
    }
    else {
      error_code=4;
      return;
    }
  }
  in.close();
}

