//Eduardo Cardoso Fernandes Neto - 5 Semestre - 9197350

#include <iostream>
#include "GLLb.h"

int main()
{
    ling_f f;
    if(char * texto = (char *) malloc(sizeof(char)))==nullptr)
    {
        std::cout << "Erro de alocacao de memoria!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cin >> texto;
    std::cout << texto << std::endl;
    std::cout << "Hello world!" << std::endl;
    return 0;
}
