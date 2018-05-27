//Eduardo Cardoso Fernandes Neto - 5 Semestre - 9197350

#include <iostream>
#include "GLLb.h"

int main()
{
    ling_f f;
    int var_controle=0;

    //Coleta dos valores dos subconjuntos
    std::cout << "Digite a seguir os valores dos subconjuntos, quando terminar digite somente"
    << " 'y' na coleta dos valores." << std::endl;
    std::cout << "A letra 'Y'(ipsilon maiusculo) indica lambda." << std::endl;

    do
    {
        char * esq;
        char * dir;

        //Alocacao dinamica das variaveis
        if((esq = (char *) malloc(sizeof(char)*10))==nullptr)
        {
            std::cerr << "Main - esq: Erro de alocacao dinamica!" << std::endl;
        }

        if((dir = (char *) malloc(sizeof(char)*10))==nullptr)
        {
            std::cerr << "Main - esq: Erro de alocacao dinamica!" << std::endl;
        }

        //Coleta dos valores
        std::cout << "Digite as letra a esquerda do subconjunto(limite 10 letras): ";

        std::cin >> esq;

        std::cout << std::endl; //Pular uma linha.

        std::cout << "Digite as letras a direita do subconjunto(limite 10 letras): ";

        std::cin >> dir;

        std::cout << std::endl;//Pular uma linha.

        //Coletar e mostrar os valores e perguntar se necessita escrever mais subconjuntos.
        inicializar_subcon(&f);

        if(esq[0] != 'y' && guardar_subconj(&f,esq,dir) == 0)
        {
            std::cout << "Subconjunto (" << esq <<","<< dir << ") coletado!" << std::endl;
            std::cout << "Quando terminar digite somente 'y' na coleta dos valores" << std::endl;
            std::cout << "A letra 'Y'(ipsilon maiusculo) indica lambda." << std::endl;
        }else if(esq[0] == 'y') var_controle = 1;

    } while(var_controle != 1);

    //Mostrar os valores coletados

    mostrar_linguagem(&f);

    return 0;
}

