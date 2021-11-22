#include <iostream>
#include "helper.h"
#include <sstream>
#include <fstream>
using namespace std;


void mod26(int& premod){
  premod=(premod+26)%26;
}

int charToInt(char input){
  return input-65;
}

bool nonnumericCharacter(char str[]){
  for (int i=0; str[i]!='\0'; i++){
    if (str[i]<48 || str[i]>57){
      return true;
    }
  }
  return false;
}
bool outsideBounds(int test){
  if (test>25 || test<0){
    return true;
  }
  return false;
}


int fileLength(char* file){
  string string;
  int count = 0;
  ifstream in;
  in.open(file);
  while(!in.eof()){
    in >> string >> ws;
    count++;
  }
  return count;
}
  
  

int makeInt(char str[]){
  stringstream intValue(str);
  int x;
  intValue >> x;
  return x;
}


void print_error(int error_code){
  switch(error_code){
  case 1:
    cerr << "Insufficient number of parameters\n";
    break;
  case 2:
    cerr << "Character input is invalid\n";
    break;
  case 3:
    cerr << "Invalid alphabetic index\n";
    break;
  case 4:
    cerr << "A non-numeric character was entered\n";
    break;
  case 5:
    cerr << "Plugboard configuration incorrect\n";
    break;
  case 6:
    cerr << "Incorrect number of plugboard parameters\n";
    break;
  case 7:
    cerr << "Rotor mapping invalid\n";
    break;
  case 8:
    cerr << "Rotor starting position not specified\n";
    break;
  case 9:
    cerr << "Reflector mapping invalid\n";
    break;
  case 10:
    cerr << "Incorrect number of reflector parameters\n";
    break;
  case 11:
    cerr << "Error opening configuration file\n";
    break;
  }    
}
