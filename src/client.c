#include "../includes/minitalk.h"

int main(int argc, char *argv[])
{
    int server_pid;

    if (argc != 3)
    {
        ft_printf("Wrong number of arguments.\n");
        ft_printf("Usage: ./client <server PID> <message>\n");
        exit(1);
    }

    server_pid = ft_atoi(argv[1]);
    send_message(server_pid, argv[2]);

    return 0;
}
