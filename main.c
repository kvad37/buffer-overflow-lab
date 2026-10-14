#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int var;
    int check = 0x04030201;
    char buf[40];

    fgets(buf, sizeof(buf), stdin);

    printf("\n[buf]: %s\n", buf);
    printf("[check] %p\n", check);

    if ((check != 0x04030201) && (check != 0xdeadbeef))
        printf ("\nTou are on the right way!\n");

    if (check == 0xdeadbeef)
    {
       printf("Yeah dude! You win!\nOpening your shell...\n");
       setreuid(geteuid(), geteuid());
       system("/bin/bash");
       printf("Shell clased! Bye.\n");
    }
    return 0;
}
