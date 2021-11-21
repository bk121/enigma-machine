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
  Rotor(char* rotor_file, char* rotor_position, int rotor_number, int no_rotors);
  int rotorMap1(int input);
  int rotorMap2(int input);
  void rotate();
};

#endif
