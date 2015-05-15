#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <assert.h>
#include <errno.h>


void tokenize(char* input, char** tolkien);
void start_shell();
void execute(char** strArray);

int main(void){
    start_shell();
}

void start_shell()
{
    char* prompt = "COMP3430 Shell $ ";
    char* input;
    char* strArray[40];
    //char* exitCommand;
    int i = 0;
    
    while(1)
    {
    	input = readline(prompt);
    	tokenize(input, strArray);
    	execute(strArray);	
    }
    
    
    while(strArray[i]){
     printf("%s\n", strArray[i]);
     i++;
    }
}

// executes the command using the given arguments 
// we expect that index 0 will be the command 
// and any succeeding values will be arguments
void execute(char** strArray)
{
	char* command = strArray[0];
	int exitValue = 1;
	char cwd[1024];
	if(strcmp(command, "cd") == 0)
	{
		if(chdir(strArray[1]) == -1)
		{
			perror("cd");
		}

	}
	else if(strcmp(command, "exit") == 0)
	{
		//im not sure what I should be doing if exit has an argument.
		exit(exitValue);
	}
	else if(strcmp(command, "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
            fprintf(stdout, "Current working dir: %s\n", cwd);
        else
            perror("getcwd() error");
	}
	else
	{
		printf("%s: command not found\n", command);
	}

}
void tokenize(char* input, char** tokens){
	assert(NULL != input);

	char* token = strtok(input, " \t");
	int index = 0;

	while (token != NULL)
	{	
		//printf("%s\n", token);
		tokens[index] = malloc(strlen(token)+1);
		strcpy(tokens[index], token);
		token = strtok(NULL, " \t");
		index++;
	}
}