//Aluno: Eduardo Cardoso Fernandes Neto - 5º - Semestre - Ciencia da Computacao
//Nº de matricula:9197350

#include <iostream>
#include "bin.h"
#define LOOP_LIMIT 1000

int main(int argc, char * argv[])
{
    //VARIAVEIS
    int debug = 0;//Variavel responsavel por ativar o modo debug(1) e desativa-lo(0).
    int num=-1;//variavel que era conter o numero que sera convertido para
    //virar binario; a variavel eh inicializada em com '-1' para indicar erro
    //caso o valor  da mesma nao seja preenchido com o valor do numero digitado
    //pelo usuario.
    int num_aux=-1;
    ptr_bin bin;//ponteiro que aponta para o ultimo binario.
    ptr_bin bin_aux;//ponteiro que ao fim da conversao apontara para o primeiro binario.

while(num != -100)
{
    //1-COLETA DO NUMERO.
    do
    {
        std::cout << "Digite o numero a ser convertido em binario" << std::endl
        << "Digite '-113' para ativar/desativar o debug" << std::endl
        << "ou digite '-100' para sair." << std::endl;
        std::cin >> num;
        std::cout << "O numero digitado foi " << num << std::endl;
        if(num == -100) exit(0);
        else if(num == -113)
        {
            debug = ((debug + 1) % 2);
            if(debug==0) std::cout << std::endl << "debug desativado" << std::endl << std::endl;
            else if(debug==1) std::cout << std::endl << "debug ativado" << std::endl << std::endl;
        }
        else if(num < 0) std::cout << "Por favor digite um numero maior ou igual a 0." << std::endl;
    }
    while (num < 0);

    //FIM: 1- COLETA DO NUMERO.

    //2-CONVERSAO DO NUMERO INTEIRO EM BINARIO.
    int loop_limit = LOOP_LIMIT;//Evita loop infinito.
    num_aux= num;

    //alocacao dinamica do primeiro valor
    if((bin = (ptr_bin) malloc(sizeof(no_bin)))== NULL)
    {
        std::cerr << "Erro na alocao dinamica!" << std::endl;
    }

    bin_aux = bin;//Passando para o ponteiro auxiliar a posicao do primeiro ponteiro.
    if(debug == 1)
    {
        std::cout << num_aux << "/2"<< "\t" << (bin_aux->valor=(num_aux % 2));//Guardando o valor da primeira divisao fora do loop while
    //caso haja somente uma(1) interacao.
        std::cout << "\t" <<(num_aux /= 2) << std::endl;
    }else
    {
        bin_aux->valor=(num_aux % 2);//Guardando o valor da primeira divisao fora do loop while
    //caso haja somente uma(1) interacao.
        num_aux /= 2;
    }

    bin_aux->ant = nullptr;//Indica que este eh o primeiro ponteiro, pois seu 'ant' aponta
    //para um valor NULO.
    bin_aux->prox = nullptr;//Indica o fim do array de numeros binarios.

    if(debug == 1)
    {
      while(num_aux >= 1 && (loop_limit--)>=0)
        {
            ptr_bin aux;//Esse ponteiro ira apontar para a area de memoria
            //recem alocada.
            if((aux = (ptr_bin) malloc(sizeof(no_bin)))== NULL)
            {
                std::cerr << "Erro na alocao dinamica!" << std::endl;
            }
            aux->ant = bin_aux;
            bin_aux->prox = aux;
            bin_aux = aux;
            bin_aux->prox = nullptr;//Indica o fim do array de numeros binarios.
            std::cout << num_aux << "/2"<< "\t" << (bin_aux->valor=(num_aux % 2));
            std::cout << "\t" <<(num_aux /= 2) << std::endl;
        }

    }else
    {
        while(num_aux >= 1 && (loop_limit--)>=0)
        {
            ptr_bin aux;//Esse ponteiro ira apontar para a area de memoria
            //recem alocada.
            if((aux = (ptr_bin) malloc(sizeof(no_bin)))== NULL)
            {
                std::cerr << "Erro na alocao dinamica!" << std::endl;
            }
            aux->ant = bin_aux;
            bin_aux->prox = aux;
            bin_aux = aux;
            bin_aux->prox = nullptr;//Indica o fim do array de numeros binarios.
            bin_aux->valor=(num_aux % 2);
            num_aux /= 2;
        }
    }
        if(loop_limit < 0)
        //No caso de o limite de loops ser atingido verificar se ocorreu algum erro,
        //do contrario aumentar o valor na variavel.
        {
            std::cout << "Foi atingido o limite de loops" <<std::endl;
            exit(-1);
        }

    //FIM: 2-CONVERSAO DO NUMERO INTEIRO EM BINARIO.

    //3-MOSTRAR O RESULTADO.
    loop_limit = LOOP_LIMIT;

    std::cout << "O valor em binario de "<< num << " eh: ";
    while(bin_aux!=nullptr && (loop_limit--)>=0)
    {
        std::cout << bin_aux->valor;
        bin_aux=bin_aux->ant;
    }

    std::cout << std::endl;


}//Fim do while.
    return 0;
}
