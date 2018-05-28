//Eduardo Cardoso Fernandes Neto - 5 Semestre - 9197350.
//Pedro Martins Feliciano - 5 Semestre - 201625910.
//Vinícius Blanco dos Santos - 5 Semestre - 201626928.

//Obs:Devido a complexidade da 'expansao da linguagem', nao foi possivel terminar esta funcao e consequentemente
//a funcao 'uniao' que iria realizar a retirada dos valores lambda.

#include <iostream>
#include "GLLb.h"

int main()
{
    ling_f f;
    int var_controle=0;
    char * esq;
    char * dir;

    while(var_controle != 1)
    {
          //Coleta dos valores dos subconjuntos
        std::cout << "Digite a seguir os valores dos subconjuntos, quando terminar digite somente"
        << " 'y' na coleta dos valores." << std::endl;
        std::cout << "A letra 'Y'(ipsilon maiusculo) indica lambda." << std::endl;

        do
        {
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
            }

        } while(esq[0] != 'y');

        //Mostrar os subconjuntos coletados.

        mostrar_linguagem(&f);

        //Expandir linguagem

        //expandir_linguagem(&f,"BS"); - Nao utiliza esse metodo, pois apresenta erro desconhecido.

        //Desalocar memoria.
        while(f.subconjuntos != nullptr)
        {
            free(f.subconjuntos->esq);
            free(f.subconjuntos->dir);
            conj aux = f.subconjuntos;
            f.subconjuntos = f.subconjuntos->prox;
            free(aux);
        }

        //Pergunta ao usuario se deseja colocar outra linguagem.
        std::cout << "Deseja colocar uma nova linguagem?(Qualquer caracter-sim,N-Nao)"<< std::endl;
        char resposta[1];
        std::cin >> resposta;
        if(resposta[0] == 'N' || resposta[0] == 'n') var_controle = 1;
    }

    return 0;
}

