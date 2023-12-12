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
#define _GNU_SOURCE


/*FUNCTION DECLARATIONS */
extern char **environ;
char *generate_error_message(char *argument, char *shell_name, int line_number);
int print_command_not_found_error(char *argument, char *shell_name, int line_number);
int switch_string(char **dest, char **source);
int free_string_array(char **str_array);
int builtin_checker(char **args, char *shell, int *errcode);
void _perror_exit(char *arg, char *shell, int line);
int env_index(const char *name);
char *_getenv(const char *name);
bool allocate_memory_for_environ(void);
void _handler(int sig);
void execute_command(char *command);
char *_strdup(const char *str);
size_t _numlen(int num);
void free_environ();
int main(int argc, char **argv);
int _printenv(void);
char *str_concat(char *, char *);
size_t _strlen(const char *s);
int custom_strncmp(const char *s1, const char *s2, size_t n);
int _printenv(void);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void *_reallocf(void *ptr, size_t old_size, size_t new_size);
char **malloc_array(char **arr);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);
char *_strcpy(char *dest, const char *src);
int empty_path(char *path);
int slash_sps(char *str);
char *cmd_path(char *cmd, char *path);
char *cmd_cwd(char *cmd);
int _getline(char *shell);
char **strtok_array(const char *str, const char *del);
int word_counter(const char *str, const char *del);
int parents_forking(char **args, char *shell, int line);
void path_checker(char **args);
void free_array(char **arr);
int string_switch(char  **prev, char **tmp);
void perror_notfound(const char *command, const char *shell, int line);
#endif /* SHELL_H */
