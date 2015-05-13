#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void){
 
 char* prompt = "COMP3430 Shell $ ";
 char* input;
 char* tolkien;

 input = readline(prompt);
 tolkien = strtok(input, " \t");

 printf("%s\n", input);


}