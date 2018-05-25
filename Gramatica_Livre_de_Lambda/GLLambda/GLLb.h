//Autor: Eduardo Cardoso Fernandes Neto - 5 Semestre - Ciencia da Computacao

#ifndef GLLB_H_
#define GLLB_H_
#include <iostream>
#include <cstdlib>

typedef struct subconjunto conj;

typedef struct
{
	conj * subconj;// Ira armazenar a lista de subconjuntos
	int quant_sub;//Quantidade de subconjuntos presentes no 'subconj'.
	int inicializado; //Se o falor for '0' entao a variavel foi inicializada, do contrario
	//o metodo 'inicializar_subcon()' precisa ser executado previamente a qualquer outro
	//metodo que utilize o objeto 'ling_f'

}ling_f;

struct subconjunto
{
    conj * prox;//Ira apontar para o proximo subconjunto.
    conj * ant;//Ira apontar para o subconjunto anterior.
	char * esq; //Ira conter os caracteres a esquerda de um subconjunto.
	char * dir; //Ira conter os caracteres a direita de um subconjunto.
};
//F(ling_f) =
//{
//('esq','dir')  <-subconjunto
//('esq','dir')  <-subconjunto
//('esq','dir')  <-subconjunto
//('esq','dir')  <-subconjunto
//('esq','dir')  <-subconjunto
//}

void inicializar_subcon(ling_f * f);
//Inicializa as variaveis do tipo 'ling_f'(linguagem f)

void guardar_subconj(ling_f * l, char * esq, char * dir);
//Descricao: Este metodo ira realizar a adicicao de um novo subconjunto a lista de subconjuntos.
//&ling_f: repassar o objeto 'ling_f' para o metodo para realizar a adiciocao

#endif //GLLB_H_
