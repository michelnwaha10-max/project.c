//menu enseignant
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

Cours *menuEnseignant(Cours *li)
{
    int choix1,choix2,choix3;
    do
            {
                trace2();
              printf(YELLOW BOLD"\t\tEspace Enseignant\n"RESET);
              trace2();
              printf(BOLD"\t1-Creer/Ajouter un cours\n"RESET);
              printf(BOLD"\t2-Cree/Ajouter un chapitre a un cours\n"RESET);
              printf(BOLD"\t3-Creer/Ajouter une lecon dans un chapitre\n"RESET);
              printf(BOLD"\t4-Creer/Ajouter un QCMs a une lecon\n"RESET);
              printf(BOLD"\t5-Visualiser la structure complet\n"RESET);
              printf(BOLD"\t6-Modifier\n"RESET);
              printf(BOLD"\t7-Supprimer\n"RESET);
              printf(BOLD"\t0-Retour au menu principale\n"RESET);
              trace2();
              printf(BOLD"\tEntrer votre choix : "RESET);
              scanf("%d",&choix1);
               getchar();
              switch(choix1)
                {
                  case 0:
                       printf(CYAN BOLD"\tRetour au menu principal.\n"RESET);
                       break;
                   case 1:
                       li=creationcours(li); 
                       break;
                    case 2:
                       li = creationchapitre(li);
                       break;
                    case 3:
                       li = creationlecon(li);
                       break;
                    case 4:
                      li = qcms(li);
                      break;
                    case 5:
                       affichertous(li);
                          break;
                    case 6:
                          do
                          {
                            trace1();
                            printf(BOLD"\t\t"YELLOW"Modifier"RESET"\n");
                            trace1();
                            printf(BOLD"\t1-Modifier le nom d'un cours\n"RESET);
                            printf(BOLD"\t2-Modifier le nom d'un chapitre\n"RESET);
                            printf(BOLD"\t3-Modifier le titre d'une lecon\n"RESET);
                            printf(BOLD"\t0-Retour\n"RESET);
                            trace1();
                            printf(BOLD"\tEntrer votre choix : "RESET);
                            scanf("%d",&choix2);
                            getchar();
                            switch(choix2)
                            {
                              case 0:
                                printf(CYAN BOLD"\tRetour.\n"RESET);
                              break;
                              case 1:
                                li = rennomerCours(li);
                                   break;
                              case 2:
                                li = rennomerChapitre(li);
                                    break;
                              case 3:
                                li = rennomerLecon(li);
                                    break;
                            default:
                              printf(RED"\tChoix invalide.\n"RESET);
                              break;
                            }
                          }while(choix2 != 0);
                       break;
                       case 7:
                          do
                          {
                            trace1();
                            printf(BOLD"\t\t"YELLOW"Suppresion"RESET"\n");
                            trace1();
                            printf(BOLD"\t1-Supprimer un cours\n"RESET);
                            printf(BOLD"\t2-Supprimer un chapitre\n"RESET);
                            printf(BOLD"\t3-Supprimer une lecon\n"RESET);
                            printf(BOLD"\t0-Retour\n"RESET);
                            trace1();
                            printf(BOLD"\tEntrer votre choix : "RESET);
                            scanf("%d",&choix3);
                            getchar();
                            switch(choix3)
                            {
                              case 0:
                                printf(CYAN BOLD"\tRetour.\n"RESET);
                              break;
                              case 1:
                                li = supprimerCours(li);
                              break;
                              case 2:
                                li = supprimerChapitre(li);
                              break;
                              case 3:
                                li = supprimerLecon(li);
                              break;
                            default:
                              printf(RED"\tChoix invalide.\n"RESET);
                              break;
                            }
                          }while(choix3 != 0);
                      default :
                      printf(RED"\tchoix invallide.\n"RESET);
                         break;
                }
              }while(choix1 != 0);
    return li;
}

//menu Etudiant
Cours *menuEtudiant(Cours *li)
{
    int choix2;
    do
                {
                    trace2();
                    printf(YELLOW BOLD"\t\tEspace Etudiant\n"RESET);
                    trace2();
                    printf(BOLD"\t1-Voir tous les cours disponible\n"RESET);
                    printf(BOLD"\t2-Lire une un cours et passer un Qcm si present \n"RESET);
                    printf(BOLD"\t3-Voir sa progreession\n"RESET);
                    printf(BOLD"\t0-Retour au menu principale.\n"RESET);
                    trace2();
                    printf(BOLD"\tEntrer votre choix : "RESET);
                    scanf("%d",&choix2);
                    getchar();
                    switch(choix2)
                    {
                      case 0:
                        printf(CYAN BOLD"\tRetour au menu principale.\n"RESET);
                        break;
                      case 1:
                      affichertous(li);
                      break;
                      case 2:
                          affichertous(li);
                           printf("\tEntrer le nom du cours que vous voulez lire :");
                            char nom3[50];
                            fgets(nom3,50,stdin);
                           nom3[strcspn(nom3,"\n")] = 0;
                              afficherCoursPasserQcm(li,nom3);
                              break;
                      case 3:
                          progression(li);  
                          break;
                      default:
                      printf(RED"\tChoix invalide.\n"RESET);
                        break;
                    }
                }while(choix2 != 0);
 return li;
}