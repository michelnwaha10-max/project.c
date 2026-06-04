#ifndef SYLABUS_H
#define SULABUS_H


//structure qcm
typedef struct QCM
{
  char question[500];
  char rep1[100];
  char rep2[100];
  char rep3[100];
  char rep4[100];
  int b_rep;
  struct QCM *suiv;
}Qcm;

//structure lecon
typedef struct Lecon
{
  char id[20];
  char titre[100];
  char contenu[1000];
  int terminee;
  Qcm *p_qcm;
  struct Lecon *suiv;
}Lecon;

//structure chapitre
typedef struct Chapitre
{
 char titre[50];
 struct Lecon *p_lecon;
 struct Chapitre *suiv;
}Chapitre;

//structure cours
typedef struct Cours
{
 char nom[30];
 char nom_e[50];
 Chapitre *p_chapitre;
 struct Cours *suiv;
}Cours;

Cours *creationcours(Cours *l);
Cours *creationchapitre(Cours *li);
Cours *creationlecon(Cours *li);
Qcm *creationQuestion(Qcm *li);

Chapitre *trouverchapitre(Chapitre *c,char *nom);
Cours *trouvercours(Cours *li,char *nom);
Lecon *trouverlecon(Lecon *l,char *id);

void affichercours(Cours *li);
void afficherchapitre(Cours *li);
void afficherlecon(Cours *li);
void affichertous(Cours *li);

Cours *afficherCoursPasserQcm(Cours *li,char nom[50]);

void progression(Cours *li);

void trace2();
void trace1();

Cours *qcms(Cours *li);

Cours *rennomerCours(Cours *li);
Cours *rennomerChapitre(Cours *li);
Cours *rennomerLecon(Cours *li);

Cours *supprimerCours(Cours *li);
Cours *supprimerChapitre(Cours *li);
Cours *supprimerLecon(Cours *li);

Qcm *repondreQcm(Qcm *li);

Cours *menuEnseignant(Cours *li);
Cours *menuEtudiant(Cours *li);
#endif