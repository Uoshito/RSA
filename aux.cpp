#include <iostream>
#include "aux.hpp"


void showHelp() {
    std::cout << "Usage:\n";
    std::cout << "  -c <input_data_file> <e> <n> To encrypt a file.\n";
    std::cout << "  -d <input_data_file> <d> <n> To decrypt a file.\n";    
}



long mdc(long a,long b) {
    while(b !=0) {
        long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long mod(long base, long exp, long mod) {
    long result = 1;
    base = base % mod;
    
    while(exp > 0) {
        if(exp % 2 == 1){
            result = (result * base) % mod;
        }
        
        exp = exp / 2;
        base = (base * base) % mod;
    }
    
    return result;
}

void criptIn(std::ifstream &entry, long e, long n) {
    std::ofstream saida("encrypted.txt");
    char c;

     if(!entry.is_open() || !saida.is_open()) {
        std::cerr << "Erro ao abrir arquivos.\n";
        exit(EXIT_FAILURE);
    }

    if(mdc(e,n) != 1) {
        std::cerr << "Chave publica invalida!\n";
        exit(EXIT_FAILURE);
    }

    while(entry.get(c)) {
        long  m = (unsigned char)c;
        long cript = mod(m, e, n);
        saida << cript << " "; 
    }

    saida.close();
}

void criptOut(std::ifstream &entry, long d, long n) {
    std::ofstream saida("decrypted.txt");
    long c;

    if (!entry.is_open() || !saida.is_open()) {
        std::cerr << "Erro ao abrir arquivos.\n";
        exit(EXIT_FAILURE);
    }

    while(entry >> c) {
        long m = mod(c, d, n);
        saida.put((char)m);
    }

    saida.close();
}