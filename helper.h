#ifndef HELPER_H
#define HELPER_H
using namespace std;

//
void mod26(int& premod);
int charToInt(char input);
void print_error(int error_code);
bool nonnumericCharacter(char str[]);
bool outsideBounds(char str[]);
int makeInt(char str[]);

#endif
