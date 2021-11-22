#include "plugboard.h"
#include "helper.h"
#include <iostream>
#include <fstream>
using namespace std;

void Plugboard::initialisePlugboard(char* plug_file, int& error_code){
  

  for (int i=0; i<26; i++){
  output_letters[i]=i;
  }

 
  ifstream in;
  in.open(plug_file);

  if (in.fail()){
    in.close();
    error_code=11;
    return;
  }

  int plug_file_length=fileLength(plug_file);
  int plugboard_file_array[plug_file_length];


  for (int i=0; i<plug_file_length && in.good(); i++){
    in >> plugboard_file_array[i];

    if (i<26){

      if (in.fail() && !in.eof()){
	error_code=4;
	return;
      }

      if (outsideBounds(plugboard_file_array[i])){
	error_code=3;
	return;
      }

      for (int j=0; j<i; j++){ 
	if (plugboard_file_array[i]==plugboard_file_array[j]){
	  error_code=5;
	  return;
	}
      }
    }
  }

  
  in.close();
  if (plug_file_length%2==1){
    error_code=6;
    return;
  }

  for (int i=0; i<plug_file_length-1; i+=2){
    int letter_a = plugboard_file_array[i];
    int letter_b = plugboard_file_array[i+1];
    output_letters[letter_a]=letter_b;
    output_letters[letter_b]=letter_a;    
  }

}

