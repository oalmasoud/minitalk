#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"

typedef struct s_mini
{
    char *message;
    int counter;
    char c;

} t_mini;

t_mini g_mini;

void send_message(int pid, char *message);
char handle_bit(char c, int signum, int counter);
char *mt_strjoin(char *s, char c);

#endif