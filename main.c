#include <stdio.h>
#include <string.h>

#include "interpret.h"
#include "stack.h"

static void repl() {
  // Recebendo entrada dos usuários 
  char line[1024];
  for (;;) {
    //Demostraçao de operaçoes 
    comandos("\n");
    printf("> ");

    if (!fgets(line, sizeof(line), stdin)) {
      printf("\n");
      break;
    }
    interpret(line);
  }
}

int main () {
  interpreter_init();
  repl();
  
  Stack* s = new_stack(10);
  stack_push(s, 20); 
  printf("%d\n", stack_pop(s));
  return 0; 
}