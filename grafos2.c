#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int menu();
void adicionaPeso(int grafo[20][20], int numVertices);
void listaGrafo(int grafo[20][20], int numVertices);

int main()
{
  int grafo[MAX][MAX];
  int numVertices = 0;

  do {
    int op = menu();
    switch (op)
    {
    case 1:
      adicionaPeso(grafo, numVertices);
      numVertices++;
      break;
    case 2:
      listaGrafo(grafo, numVertices);
      break;
    case 3:
      printf("Saindo...\n");
      exit(0);
      break;
    default:
      printf("Opção Inválida!\n");
      break;
    }
  } while (1);

  return 0;
}

int menu(){
  int op;
 
  printf("MENU:\n");
  printf("1) Adicionar Aresta:\n");
  printf("2) Listar Grafo:\n");
  printf("3) Sair...:\n");
  scanf("%d", &op);
  return op;
}

void adicionaPeso(int grafo[20][20], int numVertices){
  int peso = 0;
  int index = 0;
  if (numVertices == 0){
    grafo[0][0] = 0;
    printf("Primeiro vertice adicionado no grafo!\n");
  } 
  else{
    printf("Adicione o peso das arestas do vertice: ");
    printf("(Caso nao possua aresta, peso = 0)");
    while (index < numVertices){
      printf("\nAresta com o %d vertice:", index + 1);
      scanf("%d", &peso);

      while (peso < 0){
        printf("Peso de aresta inválido!\n");
        printf("Adicione o peso das arestas do vertice: ");
        printf("(Caso nao possua aresta, peso = 0)");
        scanf("%d", &peso);
      }

      grafo[index][numVertices] = peso;
      grafo[numVertices][index] = peso;
      index++;
    }
    grafo[numVertices][numVertices] = 0;
  }
  return;
}

void listaGrafo(int grafo[20][20], int numVertices)
{ 
  if (numVertices == 0){
    printf("Não foi adicionado nenhum vértice ao grafo!\n");
  }
  
  printf("   ");
  
  for (int i = 0; i < numVertices; i++){
    printf(" V%d", i + 1);
  }
  
  printf("\n");
  
  for (int i = 0; i < numVertices; i++){
    for (int j = 0; j < numVertices; j++){
      if (j == 0){
        printf(" V%d", i + 1);
      }
      printf(" %d ", grafo[i][j]);
    }
    printf ("\n");
  } 
} 