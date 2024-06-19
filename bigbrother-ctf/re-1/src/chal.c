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
        printf("--------------------------------------------------------------------------------\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOkdollccccccllodkOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMWKkoc,..                  ..;cdkKWMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMWXkl,.                              .,lkXWMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMWXx:.            ...',,,,,,'...            .:xXWMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMNOc.         .':oxO0XNNWWWWWWNNXKOxoc,.         .l0WMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMNk;.       .,lxKNWWX0kdolcccccclodk0XWWWKkl,.       .:ONMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMWO;.       ,o0NWNOdc,.                .,cdONWWKd;.      .:OWMMMMMMMMMM\n");
	printf("MMMMMMMMMXl.      .:kNWXkc'                          'ckXWNOc.      .oXMMMMMMMMM\n");
	printf("MMMMMMMWO,      .:OWW0o'              .,,.              'l0WWKl.      ,OWMMMMMMM\n");
	printf("MMMMMMWx.      'kWW0l.              ,kNWWNk,              .c0WWO;      .xWMMMMMM\n");
	printf("MMMMMWd.     .cKMNd.               .xMMMMMMx.               .dXMNo.     .dWMMMMM\n");
	printf("MMMMWx.     .oNMK:                 .kMMMMMMO'..               :0MWk.     .kMMMMM\n");
	printf("MMMMO'     .oNM0,               .;oONMMMMMMNK000x;             ,0MWk'    .xMMMMM\n");
	printf("MMMX:      cNM0,              .:0WMMMMMMMMMMMMMMMX:             ,0MW0o::lONMMMMM\n");
	printf("MMMk.     ,0MXc              .oNMMMMMMMMMMMMMMMMNk'              :XMMMMWMMMMMMMM\n");
	printf("MMNc      oWWx.              :XMMMMWOlccccccccc:,.               .xWMMMMMMMMMMMM\n");
	printf("MMK,     .xX0:               cNMMMMNl.....                        :0XXXXXXNWMMMM\n");
	printf("MMO.      ...                '0MMMMMNK00000Oko;.                   .......';kNMM\n");
	printf("MMk.                          ;0WMMMMMMMMMMMMMW0c.                          .OMM\n");
	printf("MMk.                           .ckXWMMMMMMMMMMMMNd.                         .kMM\n");
	printf("MM0'     .:ol.                    .,:ccccclOWMMMMX:               .lo:.     '0MM\n");
	printf("MMX;     .kMWo                   ..........lNMMMMNc               lNMk.     ;XMM\n");
	printf("MMWo      cNM0'               ;x0000000000KNMMMMM0'              .OMNc      oWMM\n");
	printf("MMM0'     .xWWx.             :XMMMMMMMMMMMMMMMMWO,               oNWx.     '0MMM\n");
	printf("MMMWd.     '0MNo.            'kNMMMMMMMMMMMMWXkc.               cXM0'     .dWMMM\n");
	printf("MMMMXc      ,0MNd.            .,:ccoKMMMMMMKc.                .cXW0,      cXMMMM\n");
	printf("MMMMMK;      ,OWWO,                .kMMMMMMk.                .dNWO,      ;KMMMMM\n");
	printf("MMMMMMK:      .dNMXo.               oNMMMMNo               .:0WNd.      :KMMMMMM\n");
	printf("MMMMMMMXc       ;OWWKl.             .;dxxd;.             .:ONWO;       cXMMMMMMM\n");
	printf("MMMMMMMMNd.      .:OWWXx;.                             'o0WWO:.      .dNMMMMMMMM\n");
	printf("MMMMMMMMMW0:.      .;xXWWKxc'.                     .;oONWXx;.      .:0WMMMMMMMMM\n");
	printf("MMMMMMMMMMMNk;.       .cxKWWN0xoc;'..........',:lxOXWWKxc.        ;kNMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMNk:.        .,lx0XNWWNXKK0000KKXNWWNX0xl,.        .:kNMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMW0o,.          .,:clodxxkkxxdolc:,.          .,o0WMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMNOo;.                                  .;oONMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMWKxl;..                        ..;lxKWMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMWN0kdl:,'............',:lok0XWMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXXKK0000KKXXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("                  MiniPlenty Lottery Software Terminal \n");
        printf("--------------------------------------------------------------------------------\n");

}

void chal()
{
  srand(time(NULL));
  int random_num = rand() % (0x31338/2);
  slow_printf("<<< Attention Comrades! We have glorious news, here is a random integer: ");
  printf("%i\n", random_num);
  int user_num;
  slow_printf("What number will you guess for a happy new life >>> ");
  scanf("%d", &user_num);

  if (user_num + random_num == 0x31337) {
     system("cat flag.txt");
  }

}

int main()
{
   logo();
   chal();
   slow_printf("<<< Parade through the streets voicing your gratitude to Big Brother!");
}
