#include "rotor.h"
#include <iostream>
#include <fstream>
using namespace std;

Rotor::Rotor(char* rotor_file, char* rotor_position){
  ifstream in;
  int mapping_int;
  in.open(rotor_file);
  for (int i=0; i<26; i++){
    in >> mapping_int;
    output_letters[i]=mapping_int;
  }
 
  for (int i=0; !in.eof(); i++){    
    in >> notches[i];
    no_notches++;
  }
  in.close();
  
  in.open(rotor_position);
  in >> starting_position;
  in.close();
}

int Rotor::rotorMap(int post_reflector){
  int output;
  for (int i=0; output_letters[i]!=post_reflector; i++){
    output=i;
  }    
  return output+1;
}
