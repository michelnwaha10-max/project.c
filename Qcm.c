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

Cours *qcms(Cours *li)
{
if(li == NULL)
    {
        printf(RED"\tAucun cours pour le moment.\n"RESET);
        trace1();
        return li;
    }
  affichertous(li);
   char id[20];
  printf("\t Entrer l'identifiant de la lecon dans le quel vous souhaitais ajouter un qcm :");
  fgets(id,20,stdin);
  id[strcspn(id,"\n")] = 0;

  Lecon *l = li->p_chapitre->p_lecon;
  Lecon *nouv ;

  nouv = trouverlecon(l,id);
  if(nouv == NULL)
  {
    trace1();
    printf(RED"\t La lecon nexiste pas .\n"RESET);
  }else
  {
    nouv->p_qcm = creationQuestion(nouv->p_qcm);
     printf(BOLD CYAN"\tQCM cree avec success."GOOD"\n"RESET);
     trace1();
  }
 return li;
}