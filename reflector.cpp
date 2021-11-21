#include "reflector.h"
#include "helper.h"
#include <iostream>
#include <fstream>
using namespace std;

void Reflector::initialiseReflector(char* reflect_file, int error_code){
  ifstream in;
  int letter_a;
  int letter_b;
  in.open(reflect_file);
  while (!in.eof()){
    in >> letter_a;
    in >> letter_b;
    if (letter_a < 26 && letter_a >=0 && letter_b < 26 && letter_b >=0){
      output_letters[letter_a]=letter_b;
      output_letters[letter_b]=letter_a;
    }
  }
  in.close();
}
