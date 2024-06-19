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

void backdoor() {
   system("cat flag.txt");
   exit(0);
}

void logo()
{
        printf("--------------------------------------------------------------------------------\n");
	printf("                                                                                \n");
	printf("    cOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOc    \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNKKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKd;'';dKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo,:dkkd:,oXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMO;,xkc''ckx,;0MMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMK;'kx.    .xO';XMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMO.c0:      :0c'OMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMK,,Od.    .dO,,KMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMKl:cllll,.:Od.  .d0:.,llllc:lKMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMO''dxoool:;oXOllOXo;:looodd''OMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMK,,0k,',coOXWx,,xWXOoc,',k0,,KMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMX:.d0;    .lKx''xKl.    ;0d.:XMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMO'.lXXx:'. .co''oc  .':xXXl.'OMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMM0';K0xxkOOOk0o''o0kOOkkxx0K;'0MMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMX:'Ox.  .'l0Wx''xW0l'.  .xO':XMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMK, c0x'    .kd''dk.    'x0c ,KMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMO..xXWXkoc;,oo''oo,;cokXWXx..OMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMK,,Kk;;:lxKNWd''dWNKxl:;;kK,,KMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMX:.xO,    .oXx''xXo.    ,Ox.:XMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMO'.cKKd;.   lo''ol   .;dKKc.'OMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMM0',0KkOOOkxdOo''oOdxkOOOkK0,'0MMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMX;'Ox. ..;dKWx''xWKd;.. .xO';XMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMK; c0o.    'Od''dO'    .o0c ;KMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMO..dXWKxl;''ll''ll'';lxKWXd..OMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMK,,KOc:cdkKXNd''dNXKkdc:cOK,,KMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMNc.xO'    'dNx''xNd'    'Ox.cNMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMK:'dkl'.   oo''oo   .'lkd':KMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMXd;;lddoolko''oklooddl;;dXMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMNkoc::;lKx,,xKl;::cokNMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKl.l0kkOl.lKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd;:cc;;dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0kkOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd.   \n");
	printf("   .dWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd.   \n");
	printf("    .::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.    \n");
	printf("                                                                                \n");
        printf("--------------------------------------------------------------------------------\n");
        printf("                     MiniPlenty Grain Reporting v2.2.5                          \n");
        printf("--------------------------------------------------------------------------------\n");

}

void chal()
{
    int value1, value2, value3, value4, value5;
        slow_printf("Enter grain productions split by commas (e.g. 1,2,3,4,5) >>> ");
        scanf("%d,%x,%d,%x,%x", &value1, &value2, &value3, &value4, &value5);
        if (value1 == 2 && value2 == 0x31337 && value3 == 2 && value4 == 0x5 && value5 == 0x1337) {
           backdoor();;
        }
}

int main()
{
   logo();
   chal();
   slow_printf("<<< Parade through the streets voicing your gratitude to Big Brother!");
}
