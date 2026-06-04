#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//trouve chapitre
Chapitre *trouverchapitre(Chapitre *c,char *nom)
{
  Chapitre *nouv = c;
  if(nouv == NULL)
  {
    return NULL;
  }
  while(nouv != NULL && strcmp(nom,nouv->titre) != 0)
  {
    nouv = nouv->suiv;
  }
  if(nouv == NULL)
  {
    return NULL;
  }
  return nouv;
}

//trouver cours
Cours *trouvercours(Cours *li,char *nom)
{
  Cours *nouv = li;
  if(nouv == NULL)
  {
    return NULL;
  }
  while(nouv != NULL && strcmp(nom,nouv->nom) != 0)
  {
    nouv = nouv->suiv;
  }
  if(nouv == NULL)
  {
    return NULL;
  }
  return nouv;
}

//trouver lecon
Lecon *trouverlecon(Lecon *l,char *id)
{
  Lecon *nouv = l;
  if(nouv == NULL)
  {
    return NULL;
  }
  while(nouv != NULL && strcmp(id,nouv->id) != 0)
  {
    nouv = nouv->suiv;
  }
  if(nouv == NULL)
  {
    return NULL;
  }
  return nouv;
}