#include <stdio.h>
#include <conio.h>
#include "sylabus.h"
#include <string.h>
#include <windows.h>

#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define BLACK "\033[0;30m"
#define BOLD "\033[1m"
#define BROWN "\033[0;33m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define SOURIRE "\U0001F600"
#define SAD "\U0001F641"
#define GOOD "\U0001F44D"
#define WRONG "\U0001F44E"
#define GOODBYE "\U0001F44B"
#define UNDERLINE "\033[4m"
#define RESET "\033[0m"

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int choix;
    Cours *li = NULL;
    printf(BOLD CYAN"\n\t\tBIENVENUE(WELCOME)"SOURIRE"\n"RESET);
    do
    {
    trace2();
    printf(BOLD MAGENTA"\t\tMENU PRINCIPAL\n"RESET);
    printf(YELLOW BOLD"     \t PLATFORM PEDAGOGIQUE C-LMS\n"RESET);
    trace2();
    printf(BOLD"1-Espace enseignant\n"RESET);
    printf(BOLD"2-Espace etudiant\n"RESET);
    printf(BOLD"0-Quitter\n"RESET);
    trace2();
    printf("Entrer votre choix :");
    scanf("%d",&choix);
         switch(choix)
         {
          case 0:
             printf(BOLD CYAN"\tMerci(Thanks)"RESET);
             break;
          case 1:
             li = menuEnseignant(li);
               break;
          case 2:
              li = menuEtudiant(li);
              break;
            default :
            printf("Choix invallide.\n");
              break;
         }
    }while(choix != 0);
    return 0;
}