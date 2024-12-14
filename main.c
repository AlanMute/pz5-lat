#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int var;
  int check = 0x04030201;
  char buf[40];

  // fgets(buf,45,stdin);
  memset(buf, 'q', 40);

  buf[44] = '\xef';
  buf[45] = '\xbe';
  buf[46] = '\xad';
  buf[47] = '\xde';
  buf[48] = '\0';

  printf("\n[buf]: %s\n", buf);
  printf("[check] %p\n", check);

  if ((check != 0x04030201) && (check != 0xdeadbeef))
    printf ("\nYou are on the right way!\n");

  if (check == 0xdeadbeef)
   {
     printf("Yeah dude! You win!\nOpening your shell...\n");
     setreuid(geteuid(), geteuid());
     system("gnome-terminal");
     printf("Shell closed! Bye.\n");
   }
   return 0;
}