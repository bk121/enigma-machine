#include "rotor.h"
#include "enigma.h"
#include "helper.h"
#include <iostream>
#include <fstream>
using namespace std;

Rotor::Rotor(char* rotor_file, char* rotor_position, int rotor_number, int no_rotors){

  // initialising rotor_number
  rotor_no=rotor_number;

  // initialising twelve_oclock

  ifstream in;
  in.open(rotor_position);
  for (int i=0; i<no_rotors-rotor_number; i++){
    in >> twelve_oclock;
  }
  in.close();
  


  // initialising output_letters and no_notches
  

  int mapping_int;
  in.open(rotor_file);
  for (int i=0; i<26; i++){
    in >> mapping_int;
    output_letters[i]=mapping_int;
  }
 
  for (int i=0; !in.eof(); i++){    
    in >> notches[i];
    in >> ws;
    no_notches++;
  }
  in.close();

 
}

int Rotor::rotorMap1(int input){
  int difference;
  int start;
  start = input+twelve_oclock;
  mod26(start);
  difference = output_letters[start]-start;
  int output = input+difference;
  mod26(output);
  return output;
}
 

int Rotor::rotorMap2(int input){
  int difference;
  int start;
  start = input+twelve_oclock;
  mod26(start);
  int i;
  for (i=0; output_letters[i]!=start; i++){}
  difference = i - start;
  int output = input+difference;
  mod26(output);
  return output;

}

void Rotor::rotate(){
  twelve_oclock+=1;
  mod26(twelve_oclock);
  }

