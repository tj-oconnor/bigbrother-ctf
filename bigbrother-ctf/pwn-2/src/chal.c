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
   putchar('\n');
}

void logo()
{
   printf("--------------------------------------------------------------------------------\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMM                                      MMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMM          Flag Shredder v2.2          MMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMM     Licensed to Ministry of Truth    MMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMM                                      MMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNNNN0ONMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKkoc;'..',..OMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMXdokXWMMMMMMMMWX0kxl,.          .kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMO.  .,coddddoc;..               .kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMk.                              .kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMk.                              .kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMk.                              .kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMk.                              .kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMk.                              .kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMk.                              .kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMO.                    .,coxkkx:..kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMXo,.            ...;okKWMMMMMM0,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMNKkoc:;,,;:cox0KXWMMMMMMMMMMK,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWMMMMMMMMMMMMMMMMMMK,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0,.kMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXocKMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMM\n");
   printf("--------------------------------------------------------------------------------\n");

   char *text = "So many thought criminal flags to shred, will you help >>>  \n";
   slow_printf(text);
}

void sigsegv_handler(int signal)
{
   printf("<<< The thought police saw your progrm crash. Its possible you don't have a \n");
   printf("<<< flag.txt in your directory for testing. Or its possible you caused the  \n");
   printf("<<< crash. We saw. We know. Do you? \n");
   exit(0);
}

void vuln()
{
   signal(SIGSEGV, sigsegv_handler);
   char buf[32];
   int l33t = 0x1337;
   char flag[l33t];

   FILE *file = fopen("flag.txt", "r");
   fread(flag, 1, l33t, file);

   scanf("%s", buf);
   if (strcmp(buf, "Y") == 0)
   {
      slow_printf("<<< Thank you. But we knew you would say that. Weve been watching you.\n");
   }
   else if (strcmp(buf, "N") == 0)
   {
      slow_printf("<<< You are a thought criminal. We will begin watching you.\n");
   }
   else
   {
      slow_printf("<<< Response not understood. Thought police heard you say: ");
      printf(buf);
      printf("\n");
   }

   if (2 + 2 == 5)
   {
      printf("<<< Flag survived. Please reshred so nobody sees: %s", flag);
   }
}

int main()
{
   logo();
   vuln();
}
