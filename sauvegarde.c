#include <stdio.h>
#include <conio.h>
#include "sylabus.h"
#include <string.h>
#include <stdlib.h>
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

void sauvegardeListe(Cours *li)
{
    FILE *fichier = fopen("Liste_Des_Cours.json", "wt");
    if (fichier == NULL) 
    {
        printf(BOLD RED "Erreur d'ouverture du fichier.\n" RESET);
        return;
    }

    if (li == NULL)
    {
        fprintf(fichier, "{\n  \"Cours\": []\n}\n"); 
        fclose(fichier);
        printf("La liste de cours est vide. Fichier JSON initialise vide.\n");
        return;
    }

    fprintf(fichier, "{\n  \"Cours\": [\n");

    int t = 1; 
    int p = 1; 
    int l = 1; 

    Cours *tmp = li;
    while (tmp != NULL)
    {
        fprintf(fichier, "    {\n");
        fprintf(fichier, "      \"id_cours\": %d,\n", t);
        fprintf(fichier, "      \"nom\": \"%s\",\n", tmp->nom);
        fprintf(fichier, "      \"enseignant\": \"%s\",\n", tmp->nom_e);
        fprintf(fichier, "      \"chapitres\": [\n");

        Chapitre *cp = tmp->p_chapitre;
        if (cp == NULL)
        {
            fprintf(fichier, "      ]\n"); 
        }
        else
        {
            while (cp != NULL)
            {
                fprintf(fichier, "        {\n");
                fprintf(fichier, "          \"id_chapitre\": %d,\n", p);
                fprintf(fichier, "          \"titre\": \"%s\",\n", cp->titre);
                fprintf(fichier, "          \"lecons\": [\n");

                Lecon *lc = cp->p_lecon;
                if (lc == NULL)
                {
                    fprintf(fichier, "          ]\n");
                }
                else
                {
                    while (lc != NULL)
                    {
                        fprintf(fichier, "            {\n");
                        fprintf(fichier, "              \"id_lecon\": %d,\n", l);
                        fprintf(fichier, "              \"code\": \"%s\",\n", lc->id);
                        fprintf(fichier, "              \"titre\": \"%s\",\n", lc->titre);
                        fprintf(fichier, "              \"contenu\": \"%s\"\n", lc->contenu);
                        
                        if (lc->suiv != NULL) {
                            fprintf(fichier, "            },\n");
                        } else {
                            fprintf(fichier, "            }\n");
                        }
                        l++;
                        lc = lc->suiv;
                    }
                    fprintf(fichier, "          ]\n"); 
                }

                if (cp->suiv != NULL) {
                    fprintf(fichier, "        },\n");
                } else {
                    fprintf(fichier, "        }\n");
                }
                p++;
                cp = cp->suiv;
            }
            fprintf(fichier, "      ]\n"); 
        }

        if (tmp->suiv != NULL) {
            fprintf(fichier, "    },\n");
        } else {
            fprintf(fichier, "    }\n");
        }            
        t++;
        tmp = tmp->suiv;
    }

    fprintf(fichier, "  ]\n}\n"); 
    fclose(fichier);
    printf(BOLD GREEN "\tDonnees sauvegardees avec succes. " GOOD "\n" RESET);
}