#include <iostream>
#include <string>
#include <cstdlib>
#include "aux.hpp"
#include "aux.cpp"

int main(int argc, char *argv[]){
    if(argc != 5) {
        showHelp();
        exit(EXIT_FAILURE);
    }

    std::string func = argv[1];
    std::ifstream entrada(argv[2]);
    long k = std::stol(argv[3]);
    long n = std::stol(argv[4]);

    if(func == "-c" || func == "-C") {
        criptIn(entrada, k, n);
    } else if(func == "-d" || func == "-D") {
        criptOut(entrada, k, n);
    }

    return EXIT_SUCCESS;
}
