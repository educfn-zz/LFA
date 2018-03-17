//Exercicio 2:
//-Desenvolver codigo que converta numeros inteiros(decimais) em binarios.
//-Decompor um inteiro n em algarismo (ex: 516 = 5 , 1, 6).
//Autor:Eduardo Cardoso Fernandes Neto - 5º Semestre - (1º semestre - 2018)

#include <stdio.h>
#include <stdlib.h>

class Conversor
{
    public:
        int numero_c, //NUMERO a ser Convertido.
                      resto;//variavel resto para conter os valores.

        long long int conv_dec_bi(long long int);//Conversor de decimal para binario.
};


long long int Conversor :: conv_dec_bi(long long int x)
{
  long long int resultado = -1;



  return resultado;
};

int main()
{
    Conversor conv;

    printf("\nDigite o numero a ser convertido: ");

    scanf("%d",&conv.numero_c); //Descobrir se eh possivel

    return 0;
}
