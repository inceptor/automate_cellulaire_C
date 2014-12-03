#include <stdio.h>
#include <stdlib.h>

#define NOM_FICHIER_M "automate_moore.txt"
#define NOM_FICHIER_V "automate_von-neumann.txt"
#define NOM_FICHIER_M_V2 "automate_moore_V2.txt"

void jeu_M(int **tab1,int n,int m,int B[9],int S[9],int ng)
{
    //le i servira dans une futur boucle
    int i=0;
    //déclaration du futur tableau a 2 dimensions qui servira pour stocké la génération n+1
    int **tab2=NULL;

    //affiche le tableau de la première génération et fait de même dans un fichier
    printf("\nGeneration numero 1 :\n");
    affiche(tab1,n,m);
    affiche_fichier(tab1,n,m,NOM_FICHIER_M);

    //-------ALLOCATION DYNAMIQUE DU DEUXIEME TABLEAU A 2 DIMENSIONS-------------
    //allocation dynamique a 1 dimension
    tab2=malloc(n*sizeof(int *));
    //si cela echoue, on quitte
    if(tab2==NULL)
    {
        exit(0);
    }

    //allocation dynamique a 2 dimensions
    for(i=0;i<n;i++)
    {
       tab2[i]=malloc(m*sizeof(int));
       //si cela echoue, on quitte
       if(tab2[i]==NULL)
       {
           exit(0);
       }
    }
    //-------FIN DE L'ALLOCATION DYNAMIQUE DU DEUXIEME TABLEAU A 2 DIMENSIONS------------


    //calcul en boucle les générations successives
    for(i=1;i<ng;i++)
    {
        duplication(tab1,tab2,n,m);

        generation_suivante_M(tab2,tab1,n,m,B,S);

        printf("Generation numero %d :\n",i+1);
        affiche(tab1,n,m);
        affiche_fichier(tab1,n,m,NOM_FICHIER_M);
    }

    //on libere la mémoire allouer
    for(i=0;i<n;i++)
    {
        free(tab2[i]);
    }
    free(tab2);

}

void jeu_conway(int **tab1,int n, int m, int ng)
{
    //on déclare les tableau de naissance et survie celon le modèle B3/S23
    int B[9]={0,0,0,1},S[9]={0,0,1,1};

    jeu_M(tab1,n,m,B,S,ng);

}

void jeu_fredkin_M(int **tab1,int n, int m, int ng)
{
    //on déclare les tableau de naissance et survie celon le modèle B1357/S1357
    int B[9]={0,1,0,1,0,1,0,1},S[9]={0,1,0,1,0,1,0,1};

    jeu_M(tab1,n,m,B,S,ng);
}

//---------------------PARTIE DES VON NEUMANN-------------------------------

void jeu_V(int **tab1,int n,int m,int BV[5],int SV[5],int ng)
{
    //le i servira dans une futur boucle
    int i=0;
    //déclaration du futur tableau a 2 dimensions qui servira pour stocké la génération n+1
    int **tab2=NULL;

    //affiche le tableau de la première génération et fait de même dans un fichier
    printf("\nGeneration numero 1 :\n");
    affiche(tab1,n,m);
    affiche_fichier(tab1,n,m,NOM_FICHIER_V);

    //-------ALLOCATION DYNAMIQUE DU DEUXIEME TABLEAU A 2 DIMENSIONS-------------
    //allocation dynamique a 1 dimension
    tab2=malloc(n*sizeof(int *));
    //si cela echoue, on quitte
    if(tab2==NULL)
    {
        exit(0);
    }

    //allocation dynamique a 2 dimensions
    for(i=0;i<n;i++)
    {
       tab2[i]=malloc(m*sizeof(int));
       //si cela echoue, on quitte
       if(tab2[i]==NULL)
       {
           exit(0);
       }
    }
    //-------FIN DE L'ALLOCATION DYNAMIQUE DU DEUXIEME TABLEAU A 2 DIMENSIONS------------


    //calcul en boucle les générations successives
    for(i=1;i<ng;i++)
    {
        duplication(tab1,tab2,n,m);

        generation_suivante_V(tab2,tab1,n,m,BV,SV);

        printf("Generation numero %d :\n",i+1);
        affiche(tab1,n,m);
        affiche_fichier(tab1,n,m,NOM_FICHIER_V);
    }

    //on libere la mémoire allouer
    for(i=0;i<n;i++)
    {
        free(tab2[i]);
    }
    free(tab2);
}

void automate_B13_S13_V(int **tab1,int n, int m, int ng)
{
    //on déclare les tableau de naissance et survie celon le modèle B13/S13
    int BV[5]={0,1,0,1},SV[5]={0,1,0,1};

    jeu_V(tab1,n,m,BV,SV,ng);
}

//------------------AUTOMATE DES MOORES DE LA V2 ET JEU_M_V2 QUI GERE LA GESTION DES CELLULES FANTOMES----------------

void jeu_M_V2(int **tab1,int n,int m,int B[9],int S[9],int ng)
{
    //le i servira dans une futur boucle
    int i=0;
    //déclaration du futur tableau a 2 dimensions qui servira pour stocké la génération n+1
    int **tab2=NULL;

    //affiche le tableau de la première génération et fait de même dans un fichier
    printf("\nGeneration numero 1 :\n");
    affiche_V2(tab1,n,m);
    affiche_fichier_V2(tab1,n,m,NOM_FICHIER_M_V2);

    //-------ALLOCATION DYNAMIQUE DU DEUXIEME TABLEAU A 2 DIMENSIONS-------------
    //allocation dynamique a 1 dimension
    tab2=malloc(n*sizeof(int *));
    //si cela echoue, on quitte
    if(tab2==NULL)
    {
        exit(0);
    }

    //allocation dynamique a 2 dimensions
    for(i=0;i<n;i++)
    {
       tab2[i]=malloc(m*sizeof(int));
       //si cela echoue, on quitte
       if(tab2[i]==NULL)
       {
           exit(0);
       }
    }
    //-------FIN DE L'ALLOCATION DYNAMIQUE DU DEUXIEME TABLEAU A 2 DIMENSIONS------------


    //calcul en boucle les générations successives
    for(i=1;i<ng;i++)
    {
        duplication(tab1,tab2,n,m);

        generation_suivante_M_V2(tab2,tab1,n,m,B,S);

        printf("Generation numero %d :\n",i+1);
        affiche_V2(tab1,n,m);
        affiche_fichier_V2(tab1,n,m,NOM_FICHIER_M_V2);
    }

    //on libere la mémoire allouer
    for(i=0;i<n;i++)
    {
        free(tab2[i]);
    }
    free(tab2);

}

void automate_B2_S_M_V2(int **tab1,int n, int m, int ng)
{
    //on déclare les tableau de naissance et survie celon le modèle B2/S
    int B[9]={0,0,1},S[9]={0};

    jeu_M_V2(tab1,n,m,B,S,ng);
}
