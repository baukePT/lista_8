/* 
 * Enunciado: 
 *    Crie uma lista ligada de alunos, em que cada aluno deve consistir de um
 *    struct contendo o seu RA, 4 notas e a média do aluno. O programa
 *    principal deve pedir para que o usuário digite o RA e as 4 notas de 
 *    3 alunos, para a seguir exibir a lista ligada completa (use exibe_lista).
*
 * Exemplos:
 * 
 *    Aluno: Rodrigo 2 3 4 5
 *    Aluno: Alexandre 10 10 8 9
 *    Aluno: Diego 7 8 10 10 
 *    (Rodrigo | 3.50) -> (Alexandre | 9.25) -> (Diego | 8.75)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_ALUNOS 3

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
Aluno ler_aluno();
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

/* Funções para uso livre */
void exibe_lista(TLista* alunos); // exibe uma lista de alunos
void ler_string(char* s); // le uma string de forma "segura"

int main (int argc, char *argv[])
{
  int i = 0;
  TLista *lista_alunos;
  Aluno aluno;

  lista_alunos = cria_lista();

  do {
  aluno = ler_aluno();
  exibe_aluno(aluno);
  printf("\n");
  insere_no_fim(lista_alunos, aluno);
  i++;
  } while (i < MAX_ALUNOS);

  exibe_lista(lista_alunos);
  system("pause");
  lista_alunos = destroi_lista(lista_alunos);

  return EXIT_SUCCESS;
}

Aluno ler_aluno() {
  Aluno aux;
  printf("Nome: ");
  ler_string(aux.nome);
  printf("Notas: ");
  for (int i = 0; i < 4; i++) {
    scanf("%f, ", &aux.notas[i]);
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
