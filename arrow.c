#include <stdio.h>
#include <unistd.h>
#include <termios.h>

void emptyBuffer() {
    char c;
    while (((c = getchar()) != '\n') && (c != EOF));
}
int differentMove() {
    struct termios tty_opts_backup, tty_opts_raw;
    char c;
    int pastermine = 1; 
    tcgetattr(STDIN_FILENO, &tty_opts_backup);
    cfmakeraw(&tty_opts_raw);

    tcsetattr(STDIN_FILENO, TCSANOW, &tty_opts_raw);
    printf("Appuyez sur 'a' pour quitter le programme et les touches 'z', 'q', 's', 'd' pour vous déplacer\n");
    while (pastermine) {
        // ZQSD
        c = getchar();
        switch (c) {
            case 'z': // haut
                printf("vous avez écrit %c => haut\n\n", c);
                break;
            case 'q': // gauche
                printf("vous avez écrit %c => gauche\n", c);
                break;
            case 'd': // droite
                printf("vous avez écrit %c => droite\n", c);
                break;
            case 's': // bas
                printf("vous avez écrit %c => bas\n", c);
                break;
            case 'a':
                printf("vous avez tapé la lettre %c pour quitter le programme!\n", c);
                pastermine = 0;
                break;
            default:
                printf("touche clavier %c NON prise en compte\n", c);
        }

      usleep(100000); 
    }


    tcsetattr(STDIN_FILENO, TCSANOW, &tty_opts_backup);

    printf("\n");
    return 0;
}
