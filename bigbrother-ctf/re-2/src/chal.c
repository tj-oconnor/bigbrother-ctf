#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
  char passwd[11];
  char buf[12];
  char flag[50];

	printf("MMMMMMMMMMMMMMMMMMMWXO0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0KNMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMX: .;kNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKl. .:0MMMMMM\n");
	printf("MMMMMMMMMMMMMMWXKXWWO;   ,xNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'     ;0MMMMM\n");
	printf("MMMMMMMMMMMMMM0;..lKWNk,   ,xNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKc.       cNMMMM\n");
	printf("MMMMMMMMMMWNWMXl.  .oXWNx,   ,xXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx'         .OMMMM\n");
	printf("MMMMMMMMM0:':kWWO:   'dNMXd'   ,xXMMMMMMMMMMMMMMMMMMMMMMMMMMW0:.           dWMMM\n");
	printf("MMMMMMWMM0,  .cKWNx'   ,kNMXd'   'dXMMMMMMMMMMMMMMMMMMMMMMMNd.             oWMMM\n");
	printf("MMMM0l:dXWXl.  .dNMXo.  .:OWMXo.   'xNMMMMMMMMMMMMMMMMMMMW0;              .dWMMM\n");
	printf("MMMMk.  ,OWWO,   ;OWW0c.  .c0WMKl.   ;0MMMMMMMMMMMMMMMMMXo.               'OMMMM\n");
	printf("MMMMWO,  .oXMXo.  .lKWWk;   .l0Xx.    ,0WMMMMMMMMMMMMMWk,                 lNMMMM\n");
	printf("MMMMMMKc   ;0WWO;   'xNMNd'   ..       :OXMMMMMMMMMMWKc.                 :XMMMMM\n");
	printf("MMMMMMMNd.  .dNMXd.   ;OWWO'           .;kMMMMMMMMMNd.                  cKMMMMMM\n");
	printf("MMMMMMMMWO,   :0WW0;   .:l;.           .'dMMMMMMMWO;                  .oNMMMMMMM\n");
	printf("MMMMMMMMMMKc.  .xNMNd.                 .;kMMMMMWKl.                  .xWMMMMMMMM\n");
	printf("MMMMMMMMMMMNd.  .c0Xk'                 :OXMMMMNd.                   ,OWMMMMMMMMM\n");
	printf("MMMMMMMMMMMMWO,   ...                .dXMMMMWk,                    :KMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMXl.                  .lKWMMMW0:.                   .lXMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMWO:.              .c0WMMWWKl.                    .dNMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMWKd:'.        .:OWMMMXd:.        .'.          'OWMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMWNKOxdddxk0XWMMMNx'          'kXO;        :KMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNk,          .cKMMMNx'    .lXMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO;           .xNMMMMMMXxold0WMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0:.           :0WMMWKXWMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMW0c.           .oNMMMXl.'oXMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMMMWKl.            ,OWMMW0;    'dXMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMMWKl.           ..cKMMMNd.       'xNMMMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMMMXd.            .xXNMMMKc.          ,kNMMMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMMMNx'             :0WMMMMMO'             :OWMMMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMMMWk;             .dNMMMMMMMW0:             .lKWMMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMMW0c.             :0WMMMMMMMMMMNd.             .dXMMMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMMMXd.             .dNMMMMMMMMMMMMMW0:              ;OWMMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMMWO;             .c0WMMMMMMMMMMMMMMMMNx'             .oXMMMMMMMMMMM\n");
	printf("MMMMMMMMMMMMMNd.             ,kNMMMMMMMMMMMMMMMMMMMMKl.             ;0WMMMMMMMMM\n");
	printf("MMMMMMMMMMMMXl.            .oXMMMMMMMMMMMMMMMMMMMMMMMWO;             'kWMMMMMMMM\n");
	printf("MMMMMMMMMMMXc            .c0WMMMMMMMMMMMMMMMMMMMMMMMMMMNx'            .kWMMMMMMM\n");
	printf("MMMMMMMMMMNo           .:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXd'           'OMMMMMMM\n");
	printf("MMMMMMMMMMK,         .:ONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXd,          oWMMMMMM\n");
	printf("MMMMMMMMMMNl       'o0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNk:.      .kMMMMMMM\n");
	printf("MMMMMMMMMMMNkc;;coONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKxl:;:o0WMMMMMMM\n");
	printf("MMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMMMMMMMMMM\n");
        printf("MMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMMMMMMMMMM\n");
        printf("MMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMMMMMMMMMM\n");
        printf("M                   MiniPlenty Food Rationing Terminal v2.2.5                  M\n");
        printf("MMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMMMMMMMMMM\n");

        printf("<<< Unauthorized use of this information system is prohibited and subject to    \n");
        printf("<<< criminal and civil penalties. Except as expressly authorized by the Ministry\n");
        printf(" Please login >>> ");
  fflush(0);
  read(0, buf, 10);
  passwd[0]='B';
  passwd[1]='1';
  passwd[2]='g';
  passwd[3]='B';
  passwd[4]='r';
  passwd[5]='0';
  passwd[6]='t';
  passwd[7]='h';
  passwd[8]='3';
  passwd[9]='R';
  passwd[10]='\0';

  flag[0] = 'b';
  flag[1] = 'b';
  flag[2] = 'c';
  flag[3] = 't';
  flag[4] = 'f';
  flag[5] = '{';
  flag[6] = 'h';
  flag[7] = '1';
  flag[8] = 'S';
  flag[9] = '_';
  flag[10] = 'W';
  flag[11] = '1';
  flag[12] = 's';
  flag[13] = '3';
  flag[14] = '_';
  flag[15] = 'l';
  flag[16] = '3';
  flag[17] = 'a';
  flag[18] = 'd';
  flag[19] = '3';
  flag[20] = 'r';
  flag[21] = 's';
  flag[22] = 'h';
  flag[23] = '1';
  flag[24] = 'p';
  flag[25] = '}';
  flag[26] = '\0';

  if (strncmp(buf, passwd,9) == 0)
  {
    printf("<<< We have won the battle for production! : %s\n", flag);
  }
  else
  {
    printf("<<< Voice your gratitude to Big Brother for this new, happy life.");
  }
}
