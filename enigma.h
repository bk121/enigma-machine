#ifndef ENIGMA_H
#define ENIGMA_H
#include "plugboard.h"
#include "rotor.h"
#include "reflector.h"
using namespace std;

class Enigma
{
  Plugboard* plugboard;
  Rotor** rotor;
  Reflector* reflector;
public:
  int no_rotors;
  Enigma(int argc, char **argv);
  char encrypt(char ch);
};
#endif
