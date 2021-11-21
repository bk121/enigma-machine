#ifndef ROTOR_H
#define ROTOR_H

class Rotor
{
 public:
  int rotor_no;
  int output_letters[26];
  int no_notches;
  int notches[26];
  int twelve_oclock;
 public:
  void initialiseRotor(char* rotor_file, char* rotor_position, int rotor_number,

		       int no_rotors, int& error_code);
  
  // function which takes in 0-based alphabet index as input and outputs
  // 0-based alphabet index for a mapping from right to left (pre-reflector) 
  int rotorMap1(int input);

  // function which takes in 0-based alphabet index as input and outputs
  // 0-based alphabet index for a mapping from left to right (post-reflector)
  int rotorMap2(int input);

  // function which adds one to member twelve_oclock to imitate a rotation
  void rotate();
};

#endif
