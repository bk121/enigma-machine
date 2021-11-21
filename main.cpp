#include <iostream>
#include "enigma.h"
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"
using namespace std;

int const MAX_NOTCHES = 26;

int main(int argc, char** argv){
  Enigma enigma(argc, argv);
    char ch;
    while (!cin.eof()){
    cin >> ch;
    cin >> ws;
    ch = enigma.encrypt(ch);
    cout << ch;
  }
  //cout << enigma.encrypt('D');
  //cout << enigma.encrypt('O');
  // cout << enigma.encrypt('N');
  
  return 0;
}

