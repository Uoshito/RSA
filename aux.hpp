#ifndef AUX_HPP
#define AUX_HPP
#include <iostream>
#include <fstream>

void showHelp();

void criptIn(std::ifstream &entry, long e, long n);

void criptOut(std::ifstream &entry, long d, long n);

long mdc(long a, long b);

long mod(long base, long exp, long mod);


#endif