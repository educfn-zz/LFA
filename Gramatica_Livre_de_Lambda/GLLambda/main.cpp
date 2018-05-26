//Eduardo Cardoso Fernandes Neto - 5 Semestre - 9197350

#include <iostream>
#include "GLLb.h"

int main()
{
    ling_f f;
    char esq[10];
    char dir[10];

    //Coleta dos valores dos subconjuntos
    std::cout << "Digite a seguir os valores dos subconjuntos, quando terminar digite somente"
    << " 'y' na coleta dos valores." << std::endl;
    std::cout << "A letra 'Y'(ipsilon maiusculo) indica lambda." << std::endl;

    while(esq[0] != 'y')
    {
        //Coleta dos valores
        std::cout << "Digite as letra a esquerda do subconjunto(limite 10 letras): ";

        std::cin >> esq;

        std::cout << std::endl; //Pular uma linha.

        std::cout << "Digite as letras a direita do subconjunto(limite 10 letras): ";

        std::cin >> dir;

        std::cout << std::endl;//Pular uma linha.

        //Mostrar os valores e perguntar se necessita escrever mais subconjuntos.
        if(esq[0] != 'y')
        {
            std::cout << "Suconjunto (" << esq <<","<< dir << ") coletado!" << std::endl;

            std::cout << "Quando terminar digite somente 'y' na coleta dos valores" << std::endl;
             std::cout << "A letra 'Y'(ipsilon maiusculo) indica lambda." << std::endl;
        }

    }

    return 0;
}

