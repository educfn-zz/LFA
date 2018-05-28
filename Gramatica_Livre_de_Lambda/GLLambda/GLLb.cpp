//Autor: Eduardo Cardoso Fernandes Neto - 5 semestre - Ciencia da Computacao

#include "GLLb.h"
#define LIMITE_STRING 10

void inicializar_subcon(ling_f * f)
{
	if(f->inicializado != 0)
	{
		f->inicializado = 0;
		f->subconjuntos = nullptr;
		f->expansoes=0;
	}
}

int guardar_subconj(ling_f * l, char * esq, char * dir)
{
    int indicador_erro= -1;

	if(esq != nullptr && dir != nullptr && l->inicializado == 0)
	{
	    conj ptr_aux = l->subconjuntos,//Ponteiro auxiliar que ira procurar o final da lista de subconjuntos.
	    ptr_ant = ptr_aux;//Outro ponteiro auxiliar que aponta para o subconjunto anterior do ptr_aux.

        while(ptr_aux != nullptr)//Buscar o final da lista de subconjuntos.
        {
            ptr_ant = ptr_aux;
            ptr_aux = ptr_aux->prox;
        }

        //Alocando memoria para ser entregue a variavel 'subconjunto' no final.
        if((ptr_aux = (conj) malloc(sizeof(subconjunto))) == nullptr)
        {
            std::cerr << "guardar_subconj: Erro de alocacao dinamica!" << std::endl;
        }
        //Quando chegar no final da lista apontar para o ultimo subconjunto e depois apontar para nulo
        //indicando o novo fim da lista.
        ptr_aux->ant = ptr_ant;
        if(ptr_ant != nullptr) ptr_ant->prox = ptr_aux;//Caso seja o primeiro subconjunto a ser guardado
        //este 'if' sera ativado.
        ptr_aux->prox = nullptr;
        if(l->subconjuntos == nullptr) l->subconjuntos = ptr_aux;//Caso seja o primeiro subconjunto a
        //ser guardado este 'if' sera ativado.

        //repassar a posiчуo das variaveis.
        ptr_aux->dir = dir;
        ptr_aux->esq = esq;

        indicador_erro = 0;
	}
	else if(esq == nullptr || dir == nullptr)
        std::cout << "Erro: guardar_subconj() - parametro nulo!" << std::endl;
	else if (l->inicializado != 0)
        std::cout << "Erro: guardar_subconj()" <<
        "- variavel tipo ling_f nao inicializada" << std::endl;
    else std::cout << "Erro: guardar_subconj() - Erro desconhecido" << std::endl;
    //Erro: guardar_subconj() - Erro desconhecido: Por algum motivo algum dos
    //parametros deste metodo, nao contem os valores esperados.

    return indicador_erro;
}

int mostrar_linguagem(ling_f * f)
{
    int indicador_erro = -1;

    if(f != nullptr && f->inicializado == 0)//Verificar se o parametro nao esta vazio(nulo)
    //e se o tipo ling_f foi 'inicializado'.
    {
      std::cout << "Linguagem F("<< f->expansoes << "): {" << std::endl;

      conj ptr_aux = f->subconjuntos;

      while(ptr_aux != nullptr)
      {
          //Imprime um subconjunto na tela.
          std::cout << "("<<ptr_aux->esq << ","
          << ptr_aux->dir << ")" << std::endl;
          //Ir para o proximo subconjunto.
          ptr_aux=ptr_aux->prox;
      }

      std::cout << "}" << std:: endl << std::endl;//Pular duas linhas para melhor visualizacao.

      indicador_erro=0;//Indica que o processo foi feito da forma correta.
    }

    return indicador_erro;
}

void expandir_linguagem(ling_f * l, char * l_exp)

{
    conj ptr_aux = l->subconjuntos;
    int contador=0;//Ira contar a quantidade de subconjuntos.

    while(ptr_aux != nullptr)//Ira contar quantidade de subconjuntos.
    {
        ptr_aux = ptr_aux->prox;
        contador++;
    }

    for(int z=0;z<contador;z++)//1 - For (Ira contar os subconjuntos).
	{
	    for(int i=0;i<((int)strlen(l_exp));i++)//2 - For (Ira alternar entre as letras a serem procuradas).
        {
            int contador_letra=0;//Armazena quantas vezes uma letra repete.

            for(int j=0;j<((int)strlen(ptr_aux->dir));j++)//3 - For (Ira contar cada letra da parte direita do subconjunto).
            {
                if(ptr_aux->dir[j] ==  l_exp[i]) contador_letra++; //Conta a quantidade de letras que aparecem
            }

            if(contador_letra > 0)//Se não tiver letra iguala procurada pula essa parte.
            {
                int contador1=0;//Ira contar quantas letras devem ser tiradas ao fim de um 'for' completo.
                int contador2=0;//Ira contar quantas letras foram tiradas ao
                //longo das interacoes do 'for' abaixo.

                char * ptr_c = ptr_aux->dir;//Auxiliara na leitura da variavel 'dir' abaixo.

                while(contador1<contador_letra)//Somente ira terminar quando todas as variacoes
                //possiveis forem feitas.
                {
                    for(int p=0;p<(int)strlen(ptr_c);p++)//Contador de letras.
                    {
                        if(ptr_c[p] != l_exp[i]) continue;
                        contador2=0;//Reset do contador2.

                        char * cpy;

                        if((cpy = (char *) malloc(1 + sizeof(char) * strlen(ptr_c)))==nullptr)
                        {
                            std::cerr << "Erro: GLLb - expandir linguagem: erro de alocacao de memoria!"
                            << std::endl;
                        }

                        strcpy(cpy,ptr_c);

                        for(int n=p+1;n<(int)strlen(ptr_c);n++)
                        {
                            contador2=0;//Rm cada interacao reseta o contador2.

                            cpy[p] = ' ';

                            contador2++;
                            for(int yz=n;yz<(int)strlen(ptr_c) && contador2 < contador1+1;yz++)
                            {
                                if(ptr_c[yz] == l_exp[i])
                                {
                                    cpy[yz] == ' ';
                                    contador2++;
                                    n=yz+1;//indica para 'n' que na proxima interacao seguir apartir deste valor.
                                }
                            }

                        }

                        if(contador2 == contador1+1) guardar_subconj(l,ptr_aux->esq,cpy);
                    }
                    contador1++;
                }

            }

        }//Fim do 2 - For
	}//Fim do 1 - For
}//Fim do metodo: expandir_linguagem



