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

void progression(Cours *li)
{
  Cours *c = li;
  int total = 0;
  int term = 0;
  if(c == NULL)
  {
    printf(RED"\tAucun cours.\n"RESET);
    return ;
  }
  while(c != NULL)
  {
    Chapitre *cp = c->p_chapitre;
    if(cp == NULL)
    {
        printf(RED"\tAucun chapitre.\n"RESET);

        return;
    }
      while(cp != NULL)
      {
        Lecon *lc = cp->p_lecon;
        if(lc == NULL)
        {
            printf(RED"\tAucune lecon.\n"RESET);
          return;
        }
        while(lc != NULL)
        {
            total ++;
            if(lc->terminee == 1)
            {
                term +=1;
            }
            lc = lc->suiv;
        }
        cp = cp->suiv;
      }
      c = c->suiv;
  }
  printf(BOLD"Nombre total de lecon : %d\n" RESET,total);
  printf(BOLD"Nombre total des lecon terminer : %d\n" RESET,term);
  float finie ;
  if(term > 0)
  {
   finie = ((float)term / total)*100;
  }else
  {
    printf(BOLD"Vous avez terminer aucune lecon.\n"RESET);
    return;
  }
  printf(BOLD"Votre pourcentage est de %.2f\n"RESET,finie);
  if(finie < 50)
  {
  printf("Appreciation : "RED"MAUVAIS\n"RESET);
  }else if(finie == 50)
  {
    printf("Appreciation : "GREEN"BIEN\n"RESET);
  }else 
  {
    printf("Appreciation : "CYAN"EXCELLENT\n"RESET);
  }
}