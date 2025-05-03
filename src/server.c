#include "../includes/minitalk.h"

void signal_handler(int signum)
{
    // static char *message;
    // static int counter = 0;
    // static char c;

    if (!g_mini.message)
        g_mini.message = ft_strdup("");
    g_mini.c = handle_bit(g_mini.c, signum, g_mini.counter);
    g_mini.counter++;
    if (g_mini.counter == 8)
    {
        g_mini.message = mt_strjoin(g_mini.message, g_mini.c);
        if (g_mini.c == '\0')
        {
            ft_printf("%s\n", g_mini.message);
            free(g_mini.message);
            g_mini.message = NULL;
        }
        g_mini.counter = 0;
        g_mini.c = 0;
    }
}
int main(void)
{
    struct sigaction server_action;
    int pid;

    server_action.sa_handler = signal_handler;
    server_action.sa_flags = 0;
    ft_bzero(&g_mini, sizeof(t_mini));
    sigemptyset(&server_action.sa_mask);
    pid = getpid();
    ft_printf("The Server PID is: %d\n", pid);

    sigaction(SIGUSR1, &server_action, NULL);
    sigaction(SIGUSR2, &server_action, NULL);

    while (1)
        pause();
}
