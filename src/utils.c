#include "../includes/minitalk.h"

void send_message(int pid, char *message)
{
    int i = 0;
    unsigned long j;

    while (message[i])
    {
        j = 0;
        while (j < 8)
        {
            if ((message[i] >> (7 - j)) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);

            j++;
            usleep(500);
        }
        i++;
    }
    j = 0;
    while (j < 8)
    {
        kill(pid, SIGUSR2); // '\0' is 00000000, so always send SIGUSR2
        j++;
        usleep(500);
    }
}
char handle_bit(char c, int signum, int counter)
{
    if (signum == SIGUSR1)
        c |= (1 << (7 - counter));
    return c;
}
char *mt_strjoin(char *s, char c)
{
    char *res;
    int i;

    i = 0;
    res = (char *)malloc((ft_strlen(s) + 2 * sizeof(char)));
    if (!res)
        return (NULL);
    while (s[i])
    {
        res[i] = s[i];
        i++;
    }
    res[i] = c;
    res[i + 1] = 0;
    return (res);
}