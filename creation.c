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
#define GREEN "\033[0;32m"
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

//Creation cours
Cours *creationcours(Cours *l)
{
trace1();
  Cours *nouv = (Cours*)malloc (sizeof(Cours)) ;
  if(nouv == NULL)
  {
    printf("\tL'allocation a echouer.\n");
    free(nouv);
    trace1();
    return l;
  }
  printf("\tEntrer le nom de l'UE :");
  fgets(nouv->nom,30,stdin);
  nouv->nom[strcspn(nouv->nom,"\n")] = 0;

  printf("\tEntrer le nom de l'enseignant :");
  fgets(nouv->nom_e,50,stdin);
  nouv->nom_e[strcspn(nouv->nom_e,"\n")] = 0;

  nouv->p_chapitre = NULL;
  nouv->suiv = NULL;

  if(l == NULL)
   {
     l = nouv;
      printf(BOLD CYAN"\tUE cree avec success."GOOD"\n"RESET);
      trace1();
   }else
   {
      Cours *tmp = l;
      while(tmp->suiv != NULL)
      {
         tmp = tmp->suiv;
      }
        tmp->suiv = nouv;
        printf(BOLD CYAN"\tUE cree avec success."GOOD"\n"RESET);
       trace1();
    }
return l;
}

//Creation chapitre
Cours *creationchapitre(Cours *li)
{
  trace1();
   Cours *tmp = li;
   if(tmp == NULL)
   {
    printf(RED"\tCree d'abord une UE.\n"RESET);
    return li;
   }
   affichercours(li);
  char chap[50];
  printf("\tEntrer l'UE a la quelle vous voulez ajouter un chapitre :");
  fgets(chap,50,stdin);
  chap[strcspn(chap,"\n")] = 0;

   tmp =   trouvercours(li,chap);
  if(tmp == NULL)
  {
    printf(RED"\tUE introuvable\n"RESET);
    trace1();
   return li;
  }
  else
  {
    Chapitre *c = (Chapitre*)malloc(sizeof(Chapitre));
    printf("\tEntrer le nom du chapitre : ");
    fgets(c->titre,50,stdin);
    c->titre[strcspn(c->titre,"\n")] = 0;

    c->p_lecon = NULL;
    c->suiv = NULL;
    
    if(tmp->p_chapitre == NULL)
    {
      tmp->p_chapitre = c;
      printf(BOLD CYAN"\tChapitre cree avec success."GOOD"\n"RESET);
      trace1();
      return li;
    }
      Chapitre *p = tmp->p_chapitre;
      while(p->suiv != NULL)
      {
        p = p->suiv;
      }
      p->suiv = c;
      printf(BOLD CYAN"\tChapitre cree avec success."GOOD"\n"RESET);
      trace1();
  }
  return li;
}


//creation d'une lecon
Cours *creationlecon(Cours *li)
{
  trace1();
  Cours * pi = li;
  if(pi == NULL)
  {
    printf(RED"\tAucune UE pour le moment .\n"RESET);
    trace1();
    return li;
  }

  char nom1[50];
  Cours *l ;
  printf("\tEntrer le nom de l'UE :");
  fgets(nom1,50,stdin);
  nom1[strcspn(nom1,"\n")] = 0;
  l=trouvercours(pi,nom1);
  if(l == NULL)
  {
    trace1();
    return li;
  }else
  {

  }

   char nom[50];
   if(pi->p_chapitre == NULL)
   {
    printf(RED"\tAucun chapitre pour l'instant"RESET);
    trace1();
    return li;
   }
  Chapitre *cp ,*b = pi->p_chapitre;
  printf("\tEntrer le titre du chapitre auquel vous voulez mettre une lecon :");
  fgets(nom,50,stdin);
  nom[strcspn(nom,"\n")] = 0;
  cp = trouverchapitre(b,nom);
  if(cp == NULL)
  {
    trace1();
   return li;
  }else
  {

    Lecon *l = (Lecon*)malloc(sizeof(Lecon));
    printf("\tEntrer l'identifiant de la lecon :");
    fgets(l->id,20,stdin);
    l->id[strcspn(l->id,"\n")] = 0;

    printf("\tEntrer le titre de la lecon : ");
    fgets(l->titre,50,stdin);
    l->titre[strcspn(l->titre,"\n")] = 0;

    printf("\tEntrer le contenu de la lecon : ");
    fgets(l->contenu,1000,stdin);
    l->contenu[strcspn(l->contenu,"\n")] = 0;

    l->terminee = 0;
    l->suiv = NULL;
    if(cp->p_lecon == NULL)
    {
      cp->p_lecon = l;
      printf(GREEN BOLD"\tLecon cree avec success."GOOD"\n"RESET);
    }else
    {
      Lecon *p = cp->p_lecon;
      while(p->suiv != NULL)
      {
        p = p->suiv;
      }
      p->suiv = l;
      printf(CYAN BOLD"\tLecon cree avec success."GOOD"\n"RESET);
    }
  }
  trace1();
  return li;
}

  //creer questions
  Qcm *creationQuestion(Qcm *li)
  {
    int t;
    printf("\tCombien de question voulez vous enregistre :");
    scanf("%d",&t);
    getchar();
  
    for(int i = 0; i < t ; i++)
    {
      Qcm *q = (Qcm*)malloc(sizeof(Qcm));
      if (q == NULL) {
      printf(RED"\tErreur d'allocation mémoire\n"RESET);
      return li;
      }
          
    q->suiv = NULL;

      printf("\t---------"BOLD"Question %d"RESET"----------\n",i+1);
      printf("\tEntrer la question :");
      fgets(q->question,500,stdin);
      q->question[strcspn(q->question,"\n")] = 0;

      printf("\tEntrer la reponse 1 :");
      fgets(q->rep1,100,stdin);
      q->rep1[strcspn(q->rep1,"\n")] = 0;

      printf("\tEntrer la reponse 2 :");
      fgets(q->rep2,100,stdin);
      q->rep2[strcspn(q->rep2,"\n")] = 0;

      printf("\tEntrer la reponse 3 :");
      fgets(q->rep3,100,stdin);
      q->rep3[strcspn(q->rep3,"\n")] = 0;

      printf("\tEntrer la reponse 4 :");
      fgets(q->rep4,100,stdin);
      q->rep4[strcspn(q->rep4,"\n")] = 0;

      do
      {
        printf("\tEntrer le chiffre de la bonne reponse :");
        scanf("%d",&q->b_rep);
        getchar();
      }while(q->b_rep < 1 || q->b_rep > 4);

    if(li == NULL)
    {
      li = q;
    }else
    {
      Qcm *p = li;
      while(p->suiv != NULL)
      {
        p = p->suiv;
      }
      p->suiv = q;
    }
    printf(BOLD GREEN"\tQuestion cree avec success."GOOD"\n"RESET);
  }
  return li;
}

//repondre au qcm
Qcm *repondreQcm(Qcm *li)
{
 if(li == NULL)
 {
  printf(RED"Aucune question.\n"RESET);
  return li;
 }
 int br,p=1;
 Qcm *tmp = li;
 printf("----------"BOLD"section quetion reponse"RESET"-----------\n");
 while(tmp != NULL)
  {
    printf("question %d\n",p);
    printf("%s\n",tmp->question);
    printf("1-%s\n",tmp->rep1);
    printf("2-%s\n",tmp->rep2);
    printf("3-%s\n",tmp->rep3);
    printf("4-%s\n",tmp->rep4);
    printf("\tEntrer votre reponse :");
    scanf("%d",&br);
    getchar();
    if(br == tmp->b_rep)
    {
      printf(GREEN"\tBonne reponse"GOOD"\n"RESET);
    }else
    {
      printf(RED"\tMauvaise reponse."WRONG"\n"RESET);
    }
    p++;
    tmp = tmp->suiv;
  }
  printf(GREEN"\tLecon terminer."SOURIRE"\n"RESET);
  return li;
}