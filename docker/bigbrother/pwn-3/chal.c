#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdint.h>

__attribute__((constructor)) void ignore_me()
{
        setbuf(stdin, NULL);
        setbuf(stdout, NULL);
        setbuf(stderr, NULL);
}

void slow_printf(char *text)
{
        for (int i = 0; text[i] != '\0'; i++)
        {
                putchar(text[i]);
                fflush(stdout);
                usleep(5000);
        }
}

void logo()
{
        printf("-------------------------------------------------------------------------------------\n");
        printf("██▓  ▄████  ███▄    █  ▒█████   ██▀███   ▄▄▄       ███▄    █  ▄████▄  ▓█████         \n");
        printf("▓██▒ ██▒ ▀█▒ ██ ▀█   █ ▒██▒  ██▒▓██ ▒ ██▒▒████▄     ██ ▀█   █ ▒██▀ ▀█  ▓█   ▀         \n");
        printf("▒██▒▒██░▄▄▄░▓██  ▀█ ██▒▒██░  ██▒▓██ ░▄█ ▒▒██  ▀█▄  ▓██  ▀█ ██▒▒▓█    ▄ ▒███           \n");
        printf("░██░░▓█  ██▓▓██▒  ▐▌██▒▒██   ██░▒██▀▀█▄  ░██▄▄▄▄██ ▓██▒  ▐▌██▒▒▓▓▄ ▄██▒▒▓█  ▄         \n");
        printf("░██░░▒▓███▀▒▒██░   ▓██░░ ████▓▒░░██▓ ▒██▒ ▓█   ▓██▒▒██░   ▓██░▒ ▓███▀ ░░▒████▒        \n");
        printf("░▓   ░▒   ▒ ░ ▒░   ▒ ▒ ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ▒░   ▒ ▒ ░ ░▒ ▒  ░░░ ▒░ ░        \n");
        printf(" ▒ ░  ░   ░ ░ ░░   ░ ▒░  ░ ▒ ▒░   ░▒ ░ ▒░  ▒   ▒▒ ░░ ░░   ░ ▒░  ░  ▒    ░ ░  ░        \n");
        printf(" ▒ ░░ ░   ░    ░   ░ ░ ░ ░ ░ ▒    ░░   ░   ░   ▒      ░   ░ ░ ░           ░           \n");
        printf(" ░        ░          ░     ░ ░     ░           ░  ░         ░ ░ ░         ░  ░        \n");
        printf("                                                              ░                       \n");
        printf(" ██▓  ██████      ██████ ▄▄▄█████▓ ██▀███  ▓█████  ███▄    █   ▄████ ▄▄▄█████▓ ██░ ██ \n");
        printf("▓██▒▒██    ▒    ▒██    ▒ ▓  ██▒ ▓▒▓██ ▒ ██▒▓█   ▀  ██ ▀█   █  ██▒ ▀█▒▓  ██▒ ▓▒▓██░ ██▒\n");
        printf("▒██▒░ ▓██▄      ░ ▓██▄   ▒ ▓██░ ▒░▓██ ░▄█ ▒▒███   ▓██  ▀█ ██▒▒██░▄▄▄░▒ ▓██░ ▒░▒██▀▀██░\n");
        printf("░██░  ▒   ██▒     ▒   ██▒░ ▓██▓ ░ ▒██▀▀█▄  ▒▓█  ▄ ▓██▒  ▐▌██▒░▓█  ██▓░ ▓██▓ ░ ░▓█ ░██ \n");
        printf("░██░▒██████▒▒   ▒██████▒▒  ▒██▒ ░ ░██▓ ▒██▒░▒████▒▒██░   ▓██░░▒▓███▀▒  ▒██▒ ░ ░▓█▒░██▓\n");
        printf("░▓  ▒ ▒▓▒ ▒ ░   ▒ ▒▓▒ ▒ ░  ▒ ░░   ░ ▒▓ ░▒▓░░░ ▒░ ░░ ▒░   ▒ ▒  ░▒   ▒   ▒ ░░    ▒ ░░▒░▒\n");
        printf(" ▒ ░░ ░▒  ░ ░   ░ ░▒  ░ ░    ░      ░▒ ░ ▒░ ░ ░  ░░ ░░   ░ ▒░  ░   ░     ░     ▒ ░▒░ ░\n");
        printf(" ▒ ░░  ░  ░     ░  ░  ░    ░        ░░   ░    ░      ░   ░ ░ ░ ░   ░   ░       ░  ░░ ░\n");
        printf(" ░        ░           ░              ░        ░  ░         ░       ░           ░  ░  ░\n");
        printf("                                                                                      \n");
        printf("--------------------------------------------------------------------------------------\n");
        printf(" (C) Ministry of Truth all rights reserved.                                           \n");
        printf("--------------------------------------------------------------------------------------\n");
}

void sigsegv_handler(int signal)
{
        slow_printf("The Ministry of Truth observed RIP is no longer true. \n");
        exit(0);
}

void freedom()
{
        system("cat flag.txt");
}

void vuln()
{
        signal(SIGSEGV, sigsegv_handler);
        char buf[8];
        slow_printf("We are always on the lookout for a new motto. Suggest one  >>> ");
        asm("nop");
        read(0, &buf, 256);
}

int main()
{
        logo();
        vuln();
        slow_printf("<<< Thank you. Your input has been recorded with the RECDEP\n");
}
