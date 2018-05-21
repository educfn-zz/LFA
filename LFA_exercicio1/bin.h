#ifndef BIN_H_
#define BIN_H_

typedef struct no_bin * ptr_bin;

struct no_bin
{
    int valor;//Ira conter o valor binario.
    ptr_bin ant;//aponta para o proximo binario.
    ptr_bin prox;//aponta para o binario anterior.
};

#endif // BIN_H_
