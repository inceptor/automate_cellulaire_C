#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "initilisation.h"
#include "changement.h"
#include "evolution.h"

int main()
{
    //-------------DECLARATION VARIABLE-----------------
    //n et m sont des dimension tableau, i l'iteration et B et S des tableaux statiques
    int n=0,m=0,i=0,ng=0;
    /*B est le tableau binaire de naissance des Moores, S est le tableau binaire de
    survie des Moores. Même logique avec BV et SV mais pour les Von Neumann*/
    int B[9],S[9],BV[5],SV[5];
    //futur tableau dynamique 2D
    int **tab=NULL,**tab2=NULL;
    //------------FIN DECLARATION VARIABLE--------------

    dimensionnement(&n,&m);

    //-------------------ALLOCATION TABLEAU DYNAMIQUE 2D--------------

    //allocation dynamique a 1 dimension
    tab=malloc(n*sizeof(int *));
    //si cela echoue, on quitte
    if(tab==NULL)
    {
        exit(0);
    }

    //allocation dynamique a 2 dimensions
    for(i=0;i<n;i++)
    {
       tab[i]=malloc(m*sizeof(int));
       //si cela echoue, on quitte
       if(tab[i]==NULL)
       {
           exit(0);
       }
    }

    //---------------------FIN ALLOCATION TABLEAU DYNAMIQUE 2D-----------

    //------------------------------SELECTION DU MODE D EMPLOIS-----------------------

    //ici, i fera office de choix pour l'utilisateur
    i=0;

    printf("-----------SELECTION DU MODE---------------\n");
    printf("1=Jeu de vie des Moore V1\n");
    printf("2=Jeu de vie des Moore V2\n");
    printf("3=Jeu de vie des Von Neumann\n");
    printf("4=Jeu de Conway ( Moore V1 )\n");
    printf("5=Jeu de Fredkin( Moore V1 )\n");
    printf("6=Jeu d'automateB13/S13 ( Von Neumann )\n");
    printf("7=Jeu d'automateB2/S ( Moore V2 )\n");
    printf("0=Sortir du programme.\n");
    printf("-------------------------------------------\n");

    do
    {
        printf("Mode selectionner : ");
        scanf("%d",&i);
        switch(i)
        {
            case 1 :
                initialisation(tab,n,m);
                ng=nb_generation();
                saisie_B_M(B);
                saisie_S_M(S);
                jeu_M(tab,n,m,B,S,ng);
                break;

            case 2 :
                initialisation_V2(tab,n,m);
                ng=nb_generation();
                saisie_B_M(B);
                saisie_S_M(S);
                jeu_M_V2(tab,n,m,B,S,ng);
                break;

            case 3 :
                initialisation(tab,n,m);
                ng=nb_generation();
                saisie_B_V(BV);
                saisie_S_V(SV);
                jeu_V(tab,n,m,BV,SV,ng);
                break;

            case 4 :
                initialisation(tab,n,m);
                ng=nb_generation();
                jeu_conway(tab,n,m,ng);
                break;

            case 5 :
                initialisation(tab,n,m);
                ng=nb_generation();
                jeu_fredkin_M(tab,n,m,ng);
                break;

            case 6 :
                initialisation(tab,n,m);
                ng=nb_generation();
                automate_B13_S13_V(tab,n,m,ng);
                break;

            case 7 :
                initialisation_V2(tab,n,m);
                ng=nb_generation();
                automate_B2_S_M_V2(tab,n,m,ng);
                break;

            case 0 :
                break;

            default :
                printf("Erreur dans la saisie. Rentrer un nombre valide.\n");
        }
    }while(i<0 || i>7);

    //------------------------------FIN DE LA SELECTION DU MODE D EMPLOIS---------------------


    //on libere la mémoire allouer
    for(i=0;i<n;i++)
    {
        free(tab[i]);
    }
    free(tab);

    system("PAUSE");

    return 0;
}
