#include <iostream>
#include "plugboard.h"
#include "reflector.h"
#include "enigma.h"
#include "rotor.h"
#include "helper.h"
#include <cstring>
using namespace std;

Enigma::Enigma(int argc, char** argv){

  //initialising no_rotors
  int no_arguments = noArguments(argv);
  no_rotors = no_arguments-8;
  
  //extracting strings from command line
  char* plugboard_string=argv[1];
  char* reflector_string=argv[2];
  char* rotor_strings[no_rotors];
  char* rotor_position_string=argv[no_arguments-5];
  for (int i=0; i<no_rotors; i++){
    rotor_strings[i]=argv[2+no_rotors-i];
  }

  //initialising plugboard, reflector and rotors
  plugboard = new Plugboard(plugboard_string);
  reflector = new Reflector(reflector_string);
  rotor = new Rotor*[no_rotors];
  for (int i=0; i<no_rotors; i++){
    rotor[i] = new Rotor(rotor_strings[i], rotor_position_string, i, no_rotors);    
  }


  
} 

char Enigma::encrypt(char ch){
  
    int digit = ch-65;
    digit = plugboard->output_letters[digit];
    //cout << digit << " after plugboard ";

    for (int i=0; i<no_rotors; i++){
      if (i==0){
	rotor[0]->rotate();
      }
      else
	for (int j=0; j<rotor[i-1]->no_notches; j++){	  
	  if (rotor[i-1]->twelve_oclock == rotor[i-1]->notches[j]){
	    rotor[i]->rotate();
	       }
	}
      digit = rotor[i]->rotorMap1(digit);
    }
    //cout << digit << " after rotors1 ";

    digit = reflector->output_letters[digit];
    //cout << digit << " after reflector ";

    for (int i=no_rotors-1; i>-1; i--){
      digit = rotor[i]->rotorMap2(digit);
    }
    // cout << digit << " after rotors2 ";
    
    digit = plugboard->output_letters[digit];
    //cout << digit << " after plugboard2 ";
    return static_cast<char>(digit)+65;
  
}







