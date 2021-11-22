#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector
{
 public:
  int output_letters[26];

  // function that takes in reflector file name and error code, and then initialises a reflector
  // based on these parameters.The function will also return an appropriate error code if one
  // is found.
  void initialiseReflector(char * reflect_file, int& error_code);
};

#endif
