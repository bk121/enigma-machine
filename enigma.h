#ifndef ENIGMA_H
#define ENIGMA_H
#include "plugboard.h"
#include "rotor.h"
#include "reflector.h"
using namespace std;

class Enigma
{
  Plugboard plugboard;
  Rotor* rotor;
  Reflector reflector;
public:
  int no_rotors;
  // method that takes in argc and argv, and then initialises an enigma machine based
  // on the argument line parameters.The function will also return an appropriate error code if one
  // is found.
  void initialiseEnigma(int argc, char **argv, int& error_code);

   
  char encode(char ch, int& error_code);

};
#endif
