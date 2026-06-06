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

Cours *lireCours(Cours *li)
{
    if(li == NULL)
    {
        printf("Aucune cours\n");
        return li;
    }
    Cours *tmp = li;
    char nom[50];
    printf("Quel cours voulez vous lire :");
    fgets(nom,50,stdin);
    nom[strcspn(nom,"\n")] = 0;

    tmp = trouverCours(p,nom);
    if(tmp == NULL)
    {
        printf("aucune cours trouver\n");
        return li;
    }else
    {
     printf("Chapitre : %s",)
    }
}