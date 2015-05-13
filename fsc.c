#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <assert.h>


void tokenize(char* input, char** tolkien);

int main(void){
 
 char* prompt = "COMP3430 Shell $ ";
 char* input;
 char** tolkien; // = malloc(sizeof(char*) * 100);
 int i = 0;

 input = readline(prompt);
 tokenize(input, tolkien);

 // while(tolkien[i]){
	//  printf("%s\n", tolkien[i]);
	//  i++;
 // }

}


void tokenize(char* input, char** tokens){
	assert(NULL != input);

	char* token = strtok(input, " \t");
	// int index = 0;

	// // while(token != NULL){
	// // 	tokens[index] = token;
	// // 	token = strtok(NULL, " \t");
	// // 	index++;
	// // }

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " \t");
	}


}