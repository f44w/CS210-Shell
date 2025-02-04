#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int x = 1; 
    while (x == 1) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd)); // gets working directory 
        printf("%s>$", cwd); // command line 
        char userinput[100]; 
        fgets(userinput, sizeof(userinput), stdin); // getting user input
        
		// Checking for built in shell functions:
		
		// Ctrl+d check
        if (feof(stdin)) { // ctrl+d -> exit program
			printf("\n");
            break;
        }
		// exit check 
        if (strcmp(userinput, "exit\n") == 0) { exit -> exit program 
            break;
        }

        char* tokens[100];
        int token_count = 0;
        char* token = strtok(result, " < \t | > & ;"); // tokens to look for
        while (token != NULL) {
            char *newline = strchr(token, '\n');
            if (newline) {
            *newline = '\0'; // setting NULL position
            }
            tokens[token_count++] = token;
            token = strtok(NULL, " < \t | > & ;");
        }
        
		/*
        for (int i = 0; i < token_count; i++) {
            printf("'%s'\n", tokens[i]); // loop through tokens printing them
        }
		*/
		
		// Else - stage 2:
		
		pid_t = pid;
		pid = fork();
		
		if(pid<0){ // negative pid -> failure
			fprintf(stderr, "Fork failed\n"); // Fork failed
			return 1;
		}
		else if(pid==0){ // signifies child process
			execlp("/bin/ls","ls",NULL); // if fails - not our fault - OS problem
			// only reached if exec fils - exit child process here:
		}
		else{
			wait(NULL); // Parent waiting for child process to complete
		}
		
    }
	
}

/* Notes:
- Dont use any exec() with 'e' in the name -> requires working path


*/
