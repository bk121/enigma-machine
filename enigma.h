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
  void initialiseEnigma(int argc, char **argv, int& error_code);
  char encode(char ch, int& error_code);
  ~Enigma();
};
#endif
