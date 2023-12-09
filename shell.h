#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdbool.h>


#define END_OF_FILE 0
#define EXIT_COMMAND 1
#define MAX_CONVERSION_BUFFER 20
#define BUFFER_SIZE 128


/*FUNCTION DECLARATIONS */
extern char **environ;
char *generate_error_message(char *argument, char *shell_name, int line_number);
int print_command_not_found_error(char *argument, char *shell_name, int line_number);
int switch_string(char **dest, char **source);
int free_string_array(char **str_array);
int check_custom_builtin(char **args, char *shell_name, int command_line, int *error_code);
void custom_perror_exit(char *arg, char *shell, int line);
int env_index(const char *name);
char *_getenv(const char *name);
bool allocate_memory_for_environ(void);
void _handler(int sig);
void execute_command(char *command);
char *_strdup(const char *str);
int _numlen(int n);
void free_environ();
int main(int argc, char *argv[]);
int custom_setenv(const char *name, const char *value);
int custom_unsetenv(const char *name);
int custom_printenv(void);
char *str_concat(char *, char *);
char *_itoa(int, char*, int);
size_t _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
int _printenv(void);

#endif /* SHELL_H */
