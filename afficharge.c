#include <stdio.h>
#include <conio.h>
#include "sylabus.h"

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

//Affichage cours
void affichercours(Cours *li)
{
    trace1();
    Cours *tmp = li;
    if(tmp == NULL)
    {
        printf(RED"\tAucune cours exist.\n"RESET);
        trace1();
        return;
    }
    printf("\t----------"BROWN"LISTE DES COURS"RESET"--------------\n");
    int p = 1;
    while(tmp != NULL)
    {
        printf("Cours %d\n", p);
        printf("\tNom du cours :" BOLD"%s\n" RESET,tmp->nom);
        printf("\tNom de l'enseignant : "BOLD"%s\n\n"RESET,tmp->nom_e);
        p++;
        tmp = tmp->suiv;
    }
    trace1();
}

//Affichage chapitre
void afficherchapitre(Cours *li)
{
    trace1();
    if(li == NULL)
    {
        printf(RED"Aucun chaptre n'a ete cree.\n"RESET);
        return ;
    }
    int p = 1;
    Chapitre *tmp = li->p_chapitre;
    if(tmp == NULL)
    {
        printf( RED"\tAucun chapitre exist.\n"RESET);
        trace1();
        return ;
    }
    printf("\t----------"BROWN"LISTE DES CHAPITRE"RESET"------------\n");
    while(tmp != NULL)
    {
        printf("\tChapitre %d :\n",p);
        printf("\tTitre :%s\n",tmp->titre);
        p++;
        if(tmp->suiv != NULL)
        {
            trace2();
        }
        tmp = tmp->suiv;
    }
    trace1();
}

//afficher lecon
void afficherlecon(Cours *li)
{
    trace1();
    if(li == NULL || li->p_chapitre == NULL)
    {
        printf(RED"\tERROR : soit le cours ou le chapitre n'existe pas .\n"RESET);
        trace1();
        return; 

    }
    Lecon *l = li->p_chapitre->p_lecon;
    if(l == NULL)
    {
        printf(RED"\tAucune lecon pour le moment.\n"RESET);
        trace1();
        return ;
    }

    printf("--------"BOLD"LISTE DES LECON"RESET"---------\n");

    int p = 1;
    while(l != NULL)
    {
        printf("\tLecon %d :\n",p);
        printf("\tIdentifiant : %s\n",l->id);
        printf("\t\tTitre:"UNDERLINE" %s\n"RESET ,l->titre);
        printf("\t\t%s\n",l->contenu);
        if(l->suiv != NULL)
        {
            printf("\n");
        }
        p++;
        l = l->suiv;
    }
    trace1();
}


//afficher cours / chapitre / lecon
void affichertous(Cours *li)
{
    trace1();
    Cours *c = li;
    if(c == NULL)
    {
      printf(RED"\tAucun cours pour le moment.\n"RESET);
      trace1();
       return;
    }else
    {
    printf("\t----------"BROWN"LISTE COMPLETE DES COURS"RESET"--------------\n");       
      while(c != NULL)
       {
          printf("\t  Cours :"BOLD" %s\n"RESET,c->nom);        
          printf("\tEnseignant : "BOLD"%s\n"RESET,c->nom_e);
          Chapitre *r = c->p_chapitre;
           if(r == NULL)
             {
              printf(RED"\tAucune chapitre pour le cours %s\n"RESET,c->nom);
             }else
             {
               int p = 1;
                while(r != NULL)
                {
                  printf("\t\tCHAPITRE %d : "BOLD"%s\n"RESET,p,r->titre);
                   Lecon *f = r->p_lecon;
                  if(f == NULL)
                   {
                       printf(RED"\t\tAucune lecon pour le chapitre %s\n"RESET,r->titre);
                   }else
                   {
                         while(f != NULL)
                          {
                          printf("\t Titre :" BOLD UNDERLINE" %s\n"RESET,f->titre);
                          printf("\t Identifiant : %s\n",f->id);
                          printf("\t%s\n",f->contenu);

                          f = f->suiv;
                          }
                    }
                    p++;
                r = r->suiv;
                }
             }
             printf("\n");
             c=c->suiv;
        }
    }
    return ;
}

//afficher un cours et passer un qcm
Cours *afficherCoursPasserQcm(Cours *li,char nom[50])
{
    if(li == NULL)
    {
        printf(RED"\tAucun cours \n"RESET);
        return li;
    }
    Cours *p = li;
    Cours *t ;
    t = trouvercours(p,nom);
    if(t == NULL)
    {
        printf(RED"\tCe cours n'existe pas."RESET);
        return li;
    }
     printf("Cours : "BOLD"%s\n"RESET,t->nom);
     printf("Enseignat :"BOLD" %s\n"RESET,t->nom_e);
     if(t->p_chapitre == NULL)
     {
        printf(RED"\tChapitre indisponible.\n"RESET);
        return li;
     }
     Chapitre *cp = t->p_chapitre;
     while(cp != NULL)
     {
      printf("\tChapitre :"BOLD" %s\n"RESET,cp->titre);

      Lecon *lc = cp->p_lecon ;
     if(lc == NULL)
     {
        printf(RED"\tAucune lecon trouver pour ce chapitre\n"RESET);
     } else
     {     
      while(lc != NULL)
      {
       printf("\tLecon : "UNDERLINE"%s\n"RESET,lc->titre);
       printf("\tIdentifiant : %s\n",lc->id);
       printf("%s\n",lc->contenu);

    char reponse;
    Qcm *qcm= lc->p_qcm;


    printf("\tVoulez vous faire les Qcm pour terminer le lecon (o/n):");
    scanf("%c",&reponse);
    getchar();
    if(reponse == 'o' || reponse == 'O')
    {
     if(qcm != NULL)
     {
            repondreQcm(qcm);
            printf(GREEN"Lecon terminer.\n"RESET);
            lc->terminee = 1;
     }else
     {
        printf(RED"\tAucun qcm enregistre pour cette lecon.\n"RESET);
     }    
    }else
    {
        printf(RED"\tLa lecon n'est pas terminer.\n"RESET);
    }
    
       lc = lc->suiv;
      }
     }

     cp = cp->suiv;
    }
return li;
}
