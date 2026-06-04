#include <stdio.h>
#include <string.h>
#include "sylabus.h"

#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define BLACK "\033[0;30m"
#define BOLD "\033[1m"
#define BROWN "\033[0;33m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define SOURIRE "\U0001F600"
#define SAD "\U0001F641"
#define GOOD "\U0001F44D"
#define WRONG "\U0001F44E"
#define GOODBYE "\U0001F44B"
#define UNDERLINE "\033[4m"
#define RESET "\033[0m"

Cours *rennomerCours(Cours *li)
{
     char nom[50];
    char nom1[50];
    Cours *po = li;
    if(li == NULL)
    {
        printf(RED"Aucun cours enregistre .\n"RESET);
        return li;
    }
    printf("\tEntrer le nom du cours que vous voulez modifier : ");
    fgets(nom,50,stdin);
    nom[strcspn(nom,"\n")] =0;

    Cours *v = trouvercours(po,nom);
    if(v == NULL)
    {
        printf(RED"\tAucun cours avec ce nom.\n"RESET);
        return li;
    }
    printf("\tEntrer le nouveau titre :");
    fgets(nom1,50,stdin);
    nom1[strcspn(nom1,"\n")] = 0;
    strcpy(v->nom,nom1);
    printf(GREEN "\tModification effectuer avec succes.\n" RESET);
    return li;
}

//renomer chapitre
Cours *rennomerChapitre(Cours *li)
{
     char nom[50];
    char nom1[50],nom2[50];
    if(li == NULL)
    {
        printf(RED"\tAucun cours enregistre .\n"RESET);
        return li;
    }
    printf("\tEntrer le nom du cours contenant le chapitre :");
    fgets(nom2,50,stdin);
    nom2[strcspn(nom2,"\n")] = 0;
        Cours *po = trouvercours(li,nom2);
        if(po == NULL)
        {
            printf(RED"\tAucun cours avec ce nom.\n"RESET);
            return li;
        }
      Chapitre *n = po->p_chapitre;
    if(n == NULL)
    {
        printf("Aucune chapitre enregistre.\n");
        return li;
    }
    printf("\tEntrer le titre du chapitre que vous voulez modifier :");
    fgets(nom,50,stdin);
    nom[strcspn(nom,"\n")] =0;

    Chapitre *v = trouverchapitre(n,nom);
    if(v == NULL)
    {
        printf(RED"\tAucun chapitre avec ce nom.\n"RESET);
        return li;
    }
    printf("\tEntrer le nouveau titre :");
    fgets(nom1,50,stdin);
    nom1[strcspn(nom1,"\n")] = 0;
    strcpy(v->titre,nom1);
    return li;
}

//renomer lecon
Cours *rennomerLecon(Cours *li)
{
    if(li == NULL)
    {
        printf(RED"\tAucun cours enregistre .\n"RESET);
        return li;
    }
    printf("\tEntrer le nom du cours contenant la lecon :");
    char nom2[50];
    fgets(nom2,50,stdin);
    nom2[strcspn(nom2,"\n")] = 0;

    Cours *po = trouvercours(li,nom2);
    if(po == NULL)
    printf("Cours indisponible.\n");
    else
    {
        if(po->p_chapitre == NULL)
        {
            printf(RED"\tAucun chapitre pour ce cours.\n"RESET);
            return li;
        }
    }
        printf("\tEntrer le titre du chapitre contenant la lecon :");
        char nom3[50];
        fgets(nom3,50,stdin);
        nom3[strcspn(nom3,"\n")] = 0;

        Chapitre *cp = trouverchapitre(po->p_chapitre,nom3);
        if(cp == NULL)
        {
            printf(RED"\tAucun chapitre avec ce nom.\n"RESET);
            return li;
        }else
        {
            if(cp->p_lecon == NULL)
            {
                printf(RED"\tAucune lecon pour ce chapitre.\n"RESET);
                return li;
            }
        }
            char nom[50];
            printf("\tEntrer l'identifiant de la lecon que vous voulez modifier :");
            fgets(nom,50,stdin);
             nom[strcspn(nom,"\n")] =0;
              Lecon *d = cp->p_lecon;    
              Lecon *v = trouverlecon(d,nom);
               if(v == NULL)
                {
                  printf(RED"\tAucune lecon trouver .\n"RESET);
                  return li;
                }
                   char nom1[50];
                    printf("\tEntrer le nouveau titre :");
                     fgets(nom1,50,stdin);
                     nom1[strcspn(nom1,"\n")] = 0;
    
                      strcpy(v->titre,nom1);

                      printf(GREEN "Modification effectuer avec succes.\n" RESET);
    return li;
}