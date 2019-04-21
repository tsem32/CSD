#include <unistd.h>
#include <stdio.h>
#include <string.h>

void shell_run();

char *read_line();

char **line_parser(char *line);

int shell_exec(char **args);
char *left_pipe_ret(char *line);

int check_test(char *line);
char *right_pipe_ret(char *line);
void pipe_run(char **args1,char **args2);

void change_dir(char **args);
