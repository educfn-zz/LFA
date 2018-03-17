/*
+----ooooo-----ooooo-------+
|                          |
| Jefferson Perez R. Costa |
| 03/2017                  |
+--------------------------+
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define N   10           // quantidade máxima de vértices
#define SIM 1
#define NAO !SIM

/*
+-----------------------------------------------------------------------------+
|                                                                             |
+-----------------------------------------------------------------------------+
*/
class Grafo {
   private:
      int v[N],         // conjunto V de vértices
	      e[N][N],      // conjunto E de arestas
		  n;            // |v| total de vertices.
   public:
      Grafo();
	  Grafo(int);
	  int  DefMatrizAdj();    // define conj E
	  int  Mostrar();         // apresenta G(V,E)
	  int  Reset();           // zera G(V,E)
	  int  Visitado(int);     // retorna SIM ou NAO se vertice foi visitado
	  void Visita(int);       // marca visitação
	  int  Profundidade(int); // percurso em profunidade (recursivo)
};
/*---------------------------------------------------------------------------*/
Grafo :: Grafo()
{
   n = -1;        // sem nenhum vertice
};
/*---------------------------------------------------------------------------*/
Grafo :: Grafo(int n)
{
   this->n = n;
   Reset();
};
/*---------------------------------------------------------------------------*/
int Grafo ::  DefMatrizAdj()
{
   char snx;
   int i, j, k=0;
   if (n == -1) {
      printf("\nConjunto E não definido\n");
      return (-1);
   }
   printf("\nDefinir a matriz de adjacencia E de %d x %d", n, n);
   while (k++ < n*n) {
      printf("informe o par <vi, vj> : <-1> sair ");
	  scanf("%d", &i);
	  if (i == -1) break;
	  scanf("%d", &j);
	  if (j == -1) break;
	  printf(" definida aresta do vertice %d para %d", i, j);
	  e[i][j] = 1;
   }
   printf("\nDefinicao da matriz concluida. Total de arestas: %d", k);
   return (0);
};
/*---------------------------------------------------------------------------*/
int Grafo :: Mostrar()
{
   int i, j;
   if (n <= -1) {
      printf("\nGrafo G(V,E) não definido\n");
      return (-1);
   }
   printf("\nGrafo G(V,E)");
   printf("\nV = { ");
   for (i = 0 ; i < n ; i++)
      printf("%d ", v[i]);
   printf("}\n");

   printf("\nE = { \n");
   for (i = 0 ; i < n ; i++) {
      printf("\t");
      for(j = 0 ; j < n ; j++)
         printf("%d ", e[i][j]);
	  printf("\n");
   }
   printf("    }\n");
   return (0);
};
/*---------------------------------------------------------------------------*/
int Grafo :: Reset()
{
   int i, j;
   for (i = 0 ; i < n ; i++) {
      v[i] = 0;
      for (j = 0 ; j < n ; j++)
	     e[i][j] = 0;
   }
   printf("\nGrafo inicializado\n");
};
/*---------------------------------------------------------------------------*/
int Grafo :: Visitado(int i)
{
   if (v[i] == 1) return SIM;
   return NAO;
};
/*---------------------------------------------------------------------------*/
void Grafo :: Visita(int i)
{
   printf("-> v%d ", i);  // operação da visita (ex. exibir vertice)
   v[i] = 1;              // marca visitado
};
/*---------------------------------------------------------------------------*/
int Grafo :: Profundidade(int i)
{
   int j;
   if (!Visitado(i)) {
      Visita(i);
	  for( j = 0 ; j < n ; j++)
	     if (e[i][j] == 1) {
		    Profundidade(j);
		 }
   }
   return (0);
};
/*---------------------------------------------------------------------------*/
int main()
{
   int v;
   Grafo g(5);
   g.Mostrar();
   g.DefMatrizAdj();
   g.Mostrar();
   v = 0;             // vertice origem
   g.Profundidade(v);
   return (0);
}
