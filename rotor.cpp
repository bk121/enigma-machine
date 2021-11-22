#include "rotor.h"
#include "enigma.h"
#include "helper.h"
#include <iostream>
#include <fstream>
using namespace std;

void Rotor::initialiseRotor(char* rotor_file, char* rotor_position, int rotor_number,
			    int no_rotors, int& error_code){

  // initialising rotor_number
  rotor_no=2;//rotor_number;

  // initialising twelve_oclock

  ifstream in;
  in.open(rotor_position);

  if (in.fail()){
    in.close();
    error_code=11;
    return;
  }

  /* int rotor_position_length=fileLength(rotor_position);
  int rotor_position_file_array[rotor_position_length];

   for (int i=0; i<rotor_position_length && !in.eof(); i++){
    in >> _file_array[i];


    if (in.fail() && !in.eof()){
      error_code=4;
      return;
    }

    if (outsideBounds(plugboard_file_array[i])){
	error_code=3;
	return;
      }

    for (int j=0; j<i; j++){
      if (plugboard_file_array[i]==plugboard_file_array[j]){
	error_code=5;
	return;
      }
    }
  }

  */
  
  for (int i=0; i<no_rotors-rotor_number; i++){
    in >> twelve_oclock;
  }
  in.close();
  


  // initialising output_letters and no_notches
  

  int mapping_int;
  in.open(rotor_file);
  if (in.fail()){
    in.close();
    error_code=11;
    return;
  }
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

