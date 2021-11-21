#include <iostream>
#include "plugboard.h"
#include "reflector.h"
#include "enigma.h"
#include "rotor.h"
#include "helper.h"
#include <cstring>
using namespace std;

void Enigma::initialiseEnigma(int argc, char** argv, int& error_code){

  //initialising no_rotors
  no_rotors = argc-4;
  
  
  //extracting strings from command line
  char* plugboard_string=argv[1];
  char* reflector_string=argv[2];
  char* rotor_strings[no_rotors];
  char* rotor_position_string=argv[argc-1];
  for (int i=0; i<no_rotors; i++){
    rotor_strings[i]=argv[2+no_rotors-i];
  }

  //initialising plugboard, reflector and rotors
  plugboard.initialisePlugboard(plugboard_string, error_code);
  if (error_code!=0){
    return;
  }
  reflector.initialiseReflector(reflector_string, error_code);
  rotor = new Rotor[no_rotors];
  for (int i=0; i<no_rotors; i++){
    rotor[i].initialiseRotor(rotor_strings[i], rotor_position_string, i, no_rotors);    
  }
}

Enigma::~Enigma(){
  delete [] rotor;
}

char Enigma::encode (char ch, int& error_code){
  

    int digit = makeInteger(ch);
    digit = plugboard.output_letters[digit];


    for (int i=0; i<no_rotors; i++){
      if (i==0){
	rotor[0].rotate();
      }
      else
	for (int j=0; j<rotor[i-1].no_notches; j++){	  
	  if (rotor[i-1].twelve_oclock == rotor[i-1].notches[j]){
	    rotor[i].rotate();
	       }
	}
      digit = rotor[i].rotorMap1(digit);
    }

    digit = reflector.output_letters[digit];

    for (int i=no_rotors-1; i>-1; i--){
      digit = rotor[i].rotorMap2(digit);
    }
    
    digit = plugboard.output_letters[digit];

    return static_cast<char>(digit)+65;
  
}







