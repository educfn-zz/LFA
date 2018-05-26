//Autor: Eduardo Cardoso Fernandes Neto - 5 Semestre - Ciencia da Computacao

#ifndef GLLB_H
#define GLLB_H
#include <iostream>
#include <cstdlib>

typedef struct subconjunto * conj;

typedef struct
{
    int expansoes;//Indica quantas expansoes esta linguagem sofreu.
	conj subconjuntos;// Ira armazenar a lista de subconjuntos.
	int inicializado; //Se o falor for '0' entao a variavel foi inicializada, do contrario
	//o metodo 'inicializar_subcon()' precisa ser executado previamente a qualquer outro
	//metodo que utilize o objeto 'ling_f'

}ling_f;

struct subconjunto
{
    conj prox;//Ira apontar para o proximo subconjunto.
    conj ant;//Ira apontar para o subconjunto anterior.
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

int guardar_subconj(ling_f * l, char * esq, char * dir);
//Descricao: Este metodo ira realizar a adicicao de um novo subconjunto a lista de subconjuntos.
//&ling_f: repassar o objeto 'ling_f' para o metodo para realizar a adiciocao
//Erro: Retorna '-1' caso alguma falha ocorra no processo.
//Sucesso: Se nao ocorrem problema o metodo retorna '0'.

int mostrar_linguagem(ling_f * f);
//Mostra na tela a linguagem e seus subconjuntos.
//Erro: Caso o valor do parametro 'ling_f * f' seja nulo ou a variavel ling_f não tenha sido
//'inicializada', o metodo retornara '-1'.

#endif //GLLB_H_

