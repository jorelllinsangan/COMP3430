#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <assert.h>
#include <errno.h>

void tokenize(char* input, char** tolkien);
int readFile(char* filename, int lastVal);
void flushBuffer(char** strArray);
int start_shell();
int execute(char** strArray, int* loop);
int isNumber(char* word);

int main(void){
	int exitVal = start_shell();
	return exitVal;
}

int start_shell()
{
    char* prompt = "COMP3430 Shell $ ";
    char* input;
    char* strArray[40];
    //char* exitCommand;
    //int i = 0;
    // Value returned by last executed function.
    int lastVal = 0;
    int loop = 1;
    
    while(loop)
    {
    	input = readline(prompt);
    	tokenize(input, strArray);

		lastVal = execute(strArray, &loop);	
    }
      
    // while(strArray[i]){
    //  printf("%s\n", strArray[i]);
    //  i++;
    // }

    return lastVal;
}

// executes the command using the given arguments 
// we expect that index 0 will be the command 
// and any succeeding values will be arguments
int execute(char** strArray, int* loop)
{
	char* command = strArray[0];
	char* directoryStr;
	int exitValue = 0;
	char cwd[1024];
	int index;

	if(strcmp(command, "cd") == 0)
	{
		
		if(NULL == strArray[1])
		{
			// If no parameter given, return to home directory.
			exitValue = chdir(getenv("HOME"));
		}
		else
		{
			// Handles directories with filenames that contain spaces.
			index = 2;
			directoryStr = strArray[1];
			while(NULL != strArray[index]){
				directoryStr = strcat(directoryStr, " ");
				directoryStr = strcat(directoryStr, strArray[index]);
				index++;
			}

			exitValue = chdir(directoryStr);

			if(exitValue == -1){
				printf("%s: No such file or directory.\n", directoryStr);
			}
		}


	}
	else if(strcmp(command, "exit") == 0)
	{
		//Check if valid exit values have been passed.
		if(NULL != strArray[1]){
			if(NULL != strArray[2]){
				printf("Invalid number of arguments.\n");

			}else{
				if(isNumber(strArray[1])){
					exitValue = strtol(strArray[1],(char**)NULL,10);
					*loop = 0;

				}else{
					printf("%s: Invalid parameter.\n",strArray[1]);

				}
			}
		}else{
			*loop = 0;
		}
	}
	else if(strcmp(command, "pwd") == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
            fprintf(stdout, "Current working dir: %s\n", cwd);
        else
            perror("getcwd() error");
	}
	else if(strcmp(command, ".") == 0)
	{
		if((NULL == strArray[2]) && (NULL != strArray[1])){
			exitValue = readFile(strArray[1], exitValue);

		}else{
			printf("Invalid number of arguments.\n");

		}
	}
	else
	{
		printf("%s: Command not found.\n", command);
	}

	return exitValue;
}

int readFile(char* filename, int lastVal){
	FILE *file;
	char* strArray[40];

	if((file = fopen(filename, "r"))){
		// Get command
		// While commands remain:
			// Parse command
			// execute command
			// get command
		printf("file opened!\n");


		fclose(file);
	}else{
		printf("No such file or directory.\n");
	}

	return lastVal;
}

// Converts user input into an array of string tokens to be parsed.
void tokenize(char* input, char** tokens){
	assert(NULL != input);

	char* token = strtok(input, " \t");
	int index = 0;

	flushBuffer(tokens);

	while (token != NULL)
	{	
		//printf("%s\n", token);
		tokens[index] = malloc(strlen(token)+1);
		strcpy(tokens[index], token);
		token = strtok(NULL, " \t");
		index++;
	}
}

/* Initializes all values in the buffer to NULL before tokenizing
 * a command string.
 */
void flushBuffer(char** strArray){
	for(int i = 0; i < 40; i++){
		strArray[i] = NULL;
	}
}

// Checks if a string is a number
int isNumber(char* word){
	int result = 1;

 	for(int i = 0; i < strlen(word) && result; i++){
  		if(!isdigit(word[i])){
 			result = 0;
  		}
  	}

	return result;
}