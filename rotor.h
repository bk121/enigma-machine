#ifndef ROTOR_H
#define ROTOR_H

class Rotor
{
 public:
  int output_letters[26];
  int no_notches;
  int notches[26];
  int starting_position;
 public:
  Rotor(char* rotor_file, char* rotor_position);
  int rotorMap(int post_reflector);
};

#endif
