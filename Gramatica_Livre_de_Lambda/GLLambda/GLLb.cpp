//Autor: Eduardo Cardoso Fernandes Neto - 5 semestre - Ciencia da Compuacao

#include "GLLb.h"

void inicializar_subcon(ling_f * f)
{
	if(f->inicializado != 0)
	{
		f->quant_sub = 0;
		f->inicializado=0;
	}
	else std::cout << "Linguagem F ja inicializada" << std::endl;
}

void guardar_subconj(ling_f * l, char * esq, char * dir)
{
	if(l != nullptr && esq != nullptr && dir != nullptr && l->inicializado == 0)
	{

	}
	else if(l != nullptr || esq == nullptr || dir == nullptr) std::cout <<
	"Erro: guardar_subconj() - parametro nulo!" << std::endl;
	else if (l->inicializado != 0) std::cout << "Erro: guardar_subconj()" <<
	"- variavel tipo ling_f nao inicializada" << std::endl;
    else std::cout << "Erro: guardar_subconj() - Erro desconhecido" << std::endl;//Por
    //algum motivo algum dos parametros deste metodo, nao contem os valores esperados.
}
