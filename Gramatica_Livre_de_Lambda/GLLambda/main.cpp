//Eduardo Cardoso Fernandes Neto - 5 Semestre - 9197350

#include <iostream>
#include "GLLb.h"

int main()
{
    ling_f f;
    char esq;
    char dir[100];

    //Coleta dos valores dos subconjuntos
    std::cout << "Digite a seguir os valores dos subconjuntos, quando terminar digite somente"
    << " 'y' na coleta dos valores" << std::endl;

    while(esq != 'y')
    {
        //Coleta dos valores
        std::cout << "Digite as letra a esquerda do subconjunto: ";

        std::cin >> esq;

        while ( !cin )
        {
            cin.clear ();

        }

        std::cout << std::endl;

        std::cout << "Digite as letras a direita do subconjunto: ";

        std::cin >> dir;

        std::cout << std::endl;

        if(esq != 'y')
        {
            std::cout << "Suconjunto (" << esq <<","<< dir << ") coletado!" << std::endl;

            std::cout << "Quando terminar digite somente 'y' na coleta dos valores" << std::endl;
        }

    }

    return 0;
}

