#include <iostream>
#include "helper.h"
using namespace std;

int noArguments(char** argv){
  char ch1;
  char ch2;
  int i;
  for (i=1; !(ch1=='p' && ch2=='o'); i++){
    file_suffix(argv[i], ch1, ch2);
  }
  return i+4;
}
  
void file_suffix(char* filename, char& ch1, char& ch2){
  int i;
  for (i=0; filename[i]!='.'; i++){
    if (filename[i]=='\n')
      exit(1);
  }
  ch1=filename[i+1];
  ch2=filename[i+2];
}
    
void mod26(int& premod){
  premod=(premod+26)%26;
}
