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

/* Funções recomendadas (não precisa implementar nenhuma delas se não quiser)
 */
Aluno ler_aluno(char linha[MAX]);
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

int ler_alunos(TLista* alunos);

TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

void ordena_lista(TLista* alunos);
void troca_alunos(Aluno* a, Aluno* b);

/* Funções para uso livre */
void exibe_lista(TLista* alunos); // exibe uma lista de alunos
void ler_string(char* s); // le uma string de forma "segura"

int main (int argc, char *argv[])
{

  return EXIT_SUCCESS;
}

void troca_alunos(Aluno *a, Aluno *b) {
}

void ordena_lista(TLista* alunos) {
}

int ler_alunos(TLista *alunos) {
}

void insere_no_fim(TLista *alunos, Aluno aluno) {
}

TLista* cria_lista() {
}

TLista* destroi_lista(TLista* alunos) {
}

float calcula_media(float* notas) {
}

Aluno ler_aluno(char entrada[MAX]) {
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
