/* 
 * Enunciado: 
 *    Repita o exercício 2, mas agora o seu programa deve implementar um
 *    algoritmo de ordenação para ordenar e exibir a lista de alunos em ordem
 *    crescente de média.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
  char nome[MAX];
  float notas[4];
  float media;
} Aluno;

typedef struct SLista {
  Aluno aluno;
  struct SLista* prox;
} TLista;

/* Funções recomendadas */
Aluno ler_aluno(FILE *file);
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

/* funçoes para o manuseio da lista*/
TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

/* Funções para uso livre */
void exibe_lista(TLista* alunos); // exibe uma lista de alunos
void ler_string(char* s); // le uma string de forma "segura"
void lerLinha(char linha[MAX], FILE *arq);
int bubbleSort(TLista** alunos, int count);
TLista* swap(TLista *a, TLista *b);


int main (int argc, char *argv[])
{
  system("cls");

  TLista *lista_alunos;
  lista_alunos = cria_lista();
  int count = 0;
  Aluno aluno;
  FILE *file;

  file = fopen("../../notas.csv", "r");
  if (file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  do {
  aluno = ler_aluno(file);

  insere_no_fim(lista_alunos, aluno);
  count++;

  } while (!feof(file));

  fclose(file);



  bubbleSort(&lista_alunos, count);
  exibe_lista(lista_alunos);

  lista_alunos = destroi_lista(lista_alunos);
  return EXIT_SUCCESS;
}

Aluno ler_aluno(FILE *file) {
  char token[MAX];
  Aluno aux;
  lerLinha(token, file);
  strcpy(aux.nome, strtok(token, ","));

  for(int i = 0; i < 4; i++) {
    aux.notas[i] = atof(strtok(NULL, ","));
  }

  aux.media = calcula_media(aux.notas);
  return aux;
}

float calcula_media(float* notas) {
  float media = 0;
  for (int i = 0; i < 4; i++) {
    media += notas[i];
  }
  return media/4;
}

TLista* cria_lista() {
  TLista *p;
  p = (TLista*) malloc(sizeof(TLista));
  if (p == NULL) {
    printf("Não pode criar a lista");
    exit(EXIT_FAILURE);
  }

  p->prox = NULL;
  return p;
}

TLista* destroi_lista(TLista* alunos) {
  TLista *aux;
  aux = alunos;
  while(aux->prox != NULL) {
    aux = aux->prox;
    free(alunos);
    alunos = aux;
  }
  free(alunos);
  return NULL;
}

void insere_no_fim(TLista *alunos, Aluno aluno) {
  TLista* novo;
  novo = (TLista*) malloc(sizeof(TLista));
  if (novo == NULL) {
    printf("Nao foi possivel alocar memoria!");
    exit(EXIT_FAILURE);
  }

  novo->aluno = aluno;
  TLista *aux;
  aux = alunos;
  while(aux->prox != NULL)
    aux = aux->prox;

  novo->prox = NULL;
  aux->prox = novo;
}

void exibe_aluno(Aluno a) {
  printf("(%s | %.2f)", a.nome, a.media);
}

void exibe_lista(TLista* alunos) {
  TLista *aux = alunos->prox;
  while(aux != NULL) {
    exibe_aluno(aux->aluno);
    if( aux->prox != NULL ) printf(" -> ");
    aux = aux->prox;
  }
  printf("\n");
}

void ler_string(char* s) {
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if( s[tam-1] == '\n' ) s[tam-1] = '\0';
}

void lerLinha(char linha[MAX], FILE *arq){
fgets(linha, MAX, arq);
if(linha[strlen(linha)-1] == '\n')
linha[strlen(linha)-1] = '\0';
}

/*Function to swap the nodes */
TLista* swap(TLista* ptr1, TLista* ptr2)
{
    TLista* tmp = ptr2->prox;
    ptr2->prox = ptr1;
    ptr1->prox = tmp;
    return ptr2;
}
 
/* Function to sort the list */
int bubbleSort(TLista** alunos, int count)
{
    TLista** h;
    int i, j, swapped;
 
    for (i = 0; i <= count; i++) {
 
        h = alunos;
        swapped = 0;
 
        for (j = 0; j < count - i - 1; j++) {
 
            TLista* p1 = *h;
            TLista* p2 = p1->prox;
 
            if (p1->aluno.media > p2->aluno.media) {
 
                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }
 
            h = &(*h)->prox;
        }
 
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}