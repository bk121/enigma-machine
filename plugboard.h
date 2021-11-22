#ifndef PLUGBOARD_H
#define PLUGBOARD_H

class Plugboard
{
 public:
  int output_letters[26];
  
  // function that takes in plug file name and error code, and then initialises a plugboard
  // based on these parameters.The function will also return an appropriate error code if one
  // is found.
  void initialisePlugboard(char* plug_file, int& error_code);
};

#endif
