#ifndef PLUGBOARD_H
#define PLUGBOARD_H

class Plugboard
{
 public:
  int output_letters[26];

 public:
  void initialisePlugboard(char* plug_file, int& error_code);
};

#endif
