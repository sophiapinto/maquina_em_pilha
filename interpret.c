#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "interpret.h"
#include "stack.h"
#include "list.h"

Stack *s = NULL;
List *l = NULL;

void interpreter_init(){
  s = new_stack(100);
  l = new_list(100);
}

void interpret (const char *source) {
  char op[10]; // op- operaçao 
  char arg[10]; //arg- argumentos 

  sscanf (source, "%s%s", op, arg);
  printf("\t\t\t________________________________\n");
  printf("\t\t\t| Operação: %s\n", op);
  printf("\t\t\t| Argumento: %s\n",  arg);
  printf("\t\t\t________________________________\n");


  //Comparar string 
  if (strcmp(op, "push") == 0){  
    int value;
    if(sscanf (arg,"%d", &value)==0) {
      value = list_get(l,arg);
    }
    stack_push(s,value);
  }
  else if (strcmp (op, "add") == 0){
    //Operação de SOMA  strncpy
    int arg1 = stack_pop(s);
    int arg2 = stack_pop(s);
    stack_push(s, arg1 + arg2);    
  } 
  else if (strcmp (op, "div") == 0){
    //Operação de DIVISÃO 
    int arg1 = stack_pop(s);
    int arg2 = stack_pop(s);
    
    if (arg1 == 0){
      printf("DIVISÃO COM ZERO");
    } 
    stack_push(s, arg1 / arg2);    
  }
  else if (strcmp (op, "mul") == 0){
    //Operação de multiplicaçao 
    int arg1 = stack_pop(s);
    int arg2 = stack_pop(s);
    stack_push(s, arg1*arg2);
  } 
  else if (strcmp (op, "sub") == 0){
    //Operação de subtraçao 
    int arg1 = stack_pop(s);
    int arg2 = stack_pop(s);
    stack_push(s, (arg1-arg2));
  } 
  else if (strcmp (op, "print") == 0){
    printf("Resultado: %d\n", stack_pop(s));
  }
  else if (strcmp(op, "pop") == 0){
      int arg1 = stack_pop(s);
    
      if (list_exist(l,arg)){
        list_set(l,arg,arg1);
      }else{
        list_append(l,arg,arg1);
      }
    }
  }

void comandos(){
  printf("\n--------------------------------------------\n\n");
  printf("\t\t\t\tCOMANDOS\n");
  printf("EMPILHAR      ------>  push\n");
  printf("SOMA          ------>  add\n");
  printf("SUBTRAÇÃO     ------>  sub\n");
  printf("MULTIPLICAÇÃO ------>  mul\n");
  printf("DIVISÃO       ------>  div\n");
  printf("DEMONSTRAÇÃO  ------>  print\n");
  printf("VARIAVEL LIST ------>  pop\n");
  printf("\n--------------------------------------------\n\n");
}