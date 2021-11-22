#ifndef HELPER_H
#define HELPER_H
using namespace std;

//
void mod26(int& premod);
int charToInt(char input);
void print_error(int error_code);
bool nonnumericCharacter(char str[]);
bool outsideBounds(int test);
int makeInt(char str[]);
int fileLength(char* file);
#endif
