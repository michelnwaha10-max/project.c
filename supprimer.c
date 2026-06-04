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
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define SOURIRE "\U0001F600"
#define SAD "\U0001F641"
#define GOOD "\U0001F44D"
#define WRONG "\U0001F44E"
#define GOODBYE "\U0001F44B"
#define UNDERLINE "\033[4m"
#define RESET "\033[0m"

//supprimer un cours
Cours *supprimerCours(Cours *li)
{
     char nom[50];
    if(li == NULL)
    {
        printf(RED"\tLa liste des cours est vide.\n"RESET);
    }else
    {
      affichertous(li);
        printf("\tEntrer le nom du cours que vous voulez supprimer :");
        fgets(nom,50,stdin);
        nom[strcspn(nom,"\n")] = 0;

        Cours *tmp = li;
        Cours *prev = NULL;
        while(tmp != NULL && strcmp(nom,tmp->nom) != 0)
        {
            prev = tmp;
            tmp = tmp->suiv;
        }
        if(tmp == NULL)
        {
            printf(RED"\tAucun cours avec ce nom.\n"RESET);
        }else
        {
            if(prev == NULL)
            {
                li = tmp->suiv;
            }else
            {
                prev->suiv = tmp->suiv;
            }
            free(tmp);
            printf(GREEN"\tCours supprimer avec success."GOOD"\n"RESET);
        }
    }
    return li;
}

//supprimer un chapitre
Cours *supprimerChapitre(Cours *li)
{
    char nom[50];
    if(li == NULL)
    {
        printf(RED"\tLa liste est vide .\n"RESET);
        return li;
    }else
    {
        affichertous(li);
        printf("\tEntrer le nom du chaitre que vous voulez supprimer :");
        fgets(nom,50,stdin);
        nom[strcspn(nom,"\n")] = 0;
        
        Chapitre *tmp = li->p_chapitre;
        Chapitre *prev = NULL;
        while(tmp != NULL && strcmp(nom,tmp->titre) != 0)
        {
            prev = tmp;
            tmp = tmp->suiv;
        }
        if(tmp == NULL)
        {
            printf(RED"\tAucun chapitre avec ce nom.\n"RESET);
        }else
        {
            if(prev == NULL)
            {
                li->p_chapitre = tmp->suiv;
            }else
            {
                prev->suiv = tmp->suiv;
            }
            free(tmp);
            printf(GREEN"\tChapitre supprimer avec success.\n"GOOD RESET);
        }
    }
 return li;
}

//supprimer une lecon
Cours *supprimerLecon(Cours *li)
{
    char nom[50],nom1[50];
    if(li == NULL || li->p_chapitre == NULL)
    {
        printf(RED"\tLa liste est vide .\n"RESET);
        return li;
    }
    affichertous(li);
    printf("\tEntrer le nom du chapitre auquel appartient la lecon que vous voulez supprimer :");
    fgets(nom,50,stdin);
    nom[strcspn(nom,"\n")] = 0;

        Chapitre *c = trouverchapitre(li->p_chapitre,nom);
        if(c == NULL)
        {
            printf(RED"\tAucun chapitre avec ce nom.\n"RESET);
            return li;
        }

    printf("\tEntrer l'identifiant de la lecon que vous voulez supprimer :");
    fgets(nom1,50,stdin);
    nom1[strcspn(nom1,"\n")] = 0;
    Lecon *tmp = c->p_lecon;
    Lecon *prev = NULL;
    while (tmp != NULL && strcmp(tmp->id,nom1))
    {
        prev = tmp;
        tmp = tmp->suiv;
    }
    if(tmp == NULL)
    {
        printf(RED"\tAucune lecon avec cet identifiant.\n"RESET);
    }
    else
    {
        if(prev == NULL)
        {
            c->p_lecon = tmp->suiv;
        }
        else
        {
            prev->suiv = tmp->suiv;
        }
        free(tmp);
        printf(GREEN"\tLecon supprimer avec success."GOOD"\n"RESET);
    }
    return li;
}