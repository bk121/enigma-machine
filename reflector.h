#ifndef REFLECTOR_H
#define REFLECTOR_H

class Reflector
{
 public:
  int output_letters[26];

 public:
  void initialiseReflector(char * reflect_file, int error_code);
};

#endif
