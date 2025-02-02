#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    int x = 1; 
    while (x == 1) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd)); // gets working directory 
        printf("%s>$", cwd); // command line 
        char userinput[100]; 
        fgets(userinput, sizeof(userinput), stdin); // getting user input
        
        if (feof(stdin)) { // ctrl+d -> exit program
            break;
        }
        if (strcmp(userinput, "exit\n") == 0) { exit -> exit program 
            break;
        }

        char* tokens[100];
        int token_count = 0;
        char* token = strtok(result, " < \t | > & ;"); // tokens 
        while (token != NULL) {
            char *newline = strchr(token, '\n');
            if (newline) {
            *newline = '\0'; // setting NULL position
            }
            tokens[token_count++] = token;
            token = strtok(NULL, " < \t | > & ;");
        }
        
        for (int i = 0; i < token_count; i++) {
            printf("'%s'\n", tokens[i]); // loop through tokens printing them
        }
    }
	
}