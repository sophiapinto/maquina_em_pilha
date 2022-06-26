#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/*
key -  chave 
value - valor 
node - nó*/

// Definindo a estrutura de um nó (Lista Encadeada) 
struct node {
  char key[15];
  int value;
  struct node *prox;
};

//
struct list{
  struct node* primeiro;
};

static struct node* list_find(List* l, char* key){
  struct node* prox = l -> primeiro;
  while (prox) {
    if(strcmp(prox->key, key) == 0)
      return prox;
    prox = prox -> prox;
    
  }
  return NULL;
}

//Nova lista, inicial nulo.

List* new_list (){
  List* l = calloc(1, sizeof(List));
  l->primeiro=NULL;
  return l;
}

//Acrescentar
void list_append(List* l, char* key, int value) {
  struct node* node = calloc (1, sizeof(struct node));
  strcpy(node->key, key);
  node->value = value;
  node->prox = l->primeiro;
  l->primeiro = node;
}

//Obter
int list_get (List* l, char* key) {
  struct node* n;
  if ((n = list_find(l, key)) != NULL) {
    return n->value;
  }
  return -1;
}

//Configurar
void list_set (List* l, char* key, int value) {
  struct node* n;
  if ((n = list_find(l, key)) != NULL){
    n->value = value;
  }
}

int list_exist (List* l, char* key) {
  return list_find(l, key) != NULL;
}

void list_print(List* l){
  struct node* prox = l->primeiro;
  while(prox){
    printf("%s-> %d\n", prox->key,prox->value);
    prox=prox->prox;
  }
}