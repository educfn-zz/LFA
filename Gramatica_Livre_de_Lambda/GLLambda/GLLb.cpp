//Autor: Eduardo Cardoso Fernandes Neto - 5 semestre - Ciencia da Compuacao

#include "GLLb.h"

void inicializar_subcon(ling_f * f)
{
	if(f->inicializado != 0)
	{
		f->inicializado = 0;
		f->subconjuntos = nullptr;
	}
	else std::cout << "Linguagem F ja inicializada" << std::endl;
}

int guardar_subconj(ling_f * l, char * esq, char * dir)
{
    int indicador_erro= -1;

	if(l != nullptr && esq != nullptr && dir != nullptr && l->inicializado == 0)
	{
	    conj * ptr_aux = l->subconjuntos,//Ponteiro auxiliar que ira procurar o final da lista de subconjuntos.
	    * ptr_ant;//Outro ponteiro auxiliar que aponta para o subconjunto anterior do ptr_aux.

        while(ptr_aux != nullptr)//Buscar o final da lista de subconjuntos.
        {
            ptr_ant = ptr_aux;
            ptr_aux = ptr_aux->prox;
        }

        //Quando chegar no final da lista apontar para o ultimo subconjunto e depois apontar para nulo
        //indicando o novo fim da lista.
        ptr_aux->ant = ptr_ant;
        ptr_aux->prox = nullptr;
        //repassar a posição das variaveis.
        ptr_aux->dir = dir;
        ptr_aux->esq = esq;

        indicador_erro = 0;
	}
	else if(l != nullptr || esq == nullptr || dir == nullptr)
        std::cout << "Erro: guardar_subconj() - parametro nulo!" << std::endl;
	else if (l->inicializado != 0)
        std::cout << "Erro: guardar_subconj()" <<
        "- variavel tipo ling_f nao inicializada" << std::endl;
    else std::cout << "Erro: guardar_subconj() - Erro desconhecido" << std::endl;
    //Erro: guardar_subconj() - Erro desconhecido: Por algum motivo algum dos
    //parametros deste metodo, nao contem os valores esperados.

    return indicador_erro;
}

