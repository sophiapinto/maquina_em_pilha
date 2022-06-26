#include "stack.h"
#include "stdlib.h"
#include "stdio.h"


struct stack{
  int  *values; //posiçao 
  int top; // qual posiçao vai ser adicionado o elemento 
};

/*Aloca espaço para um bloco de bytes consecutivos na memória RAM
size=Tamanho 
new_stack = nova pilha*/

Stack* new_stack(int size){
  //alocar uma pilha 
  Stack* s = (Stack*) malloc (sizeof(struct stack));
  //alocar o espaço do vetor 
  s->values = (int*) malloc(sizeof(int) * size);
  s->top=0;
  return s;
}

// stack_push-> empilhar_empurrar, colocar elemento na pilha 
void stack_push(Stack* s, int value) {
  //top= armazena o elemento
  s->values[s->top++] = value;
}

//stack_pop -> pilha_pop

int stack_pop (Stack* s) {
  
  if (s->top == 0){
    printf("Stack Empty = Pilha Vazia\n");
    exit(1);
  }
  return s->values[--s->top];
  
}
//stack_print-> impressão da pilha
void stack_print(Stack* s) {
  
  printf("\n\n:-------Stack-------\n\n");
  
  printf("ELEMENTOS DA PILHA: \n");
  
  for(int i=0; i< s->top; i++){
    printf("%d\n", s->values[i]);
  }
  
  printf(".:.-------Stack-------.:.\n\n");
}
