#include "reflector.h"
#include "helper.h"
#include <iostream>
#include <fstream>
using namespace std;

void Reflector::initialiseReflector(char * reflect_file, int error_code){
  ifstream in;
  in.open(reflect_file);

  if (in.fail()){
    in.close();
    error_code=11;
    return;
  }

  int reflector_file_length=fileLength(reflect_file);

  int reflector_file_array[reflector_file_length];

  for (int i=0; i<reflector_file_length; i++){
    in >> reflector_file_array[i];

    if (in.eof()){
      return;
    }
   
    if (in.fail()){
      error_code=4;
      return;
    }

    if (outsideBounds(reflector_file_array[i])){
	error_code=3;
	return;
      }

    for (int j=0; j<i; j++){
      if (reflector_file_array[i]==reflector_file_array[j]){
	error_code=9;
	return;
      }

    }
  }

  in.close();

  if (reflector_file_length!=26){
    error_code=10;
    return;
  }


  for (int i=0; i<reflector_file_length-1; i+=2){
    int letter_a = reflector_file_array[i];
    int letter_b = reflector_file_array[i+1];
    output_letters[letter_a]=letter_b;
    output_letters[letter_b]=letter_a;
  }

}
