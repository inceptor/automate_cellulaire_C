#include <stdio.h>
#include <stdlib.h>

void dimensionnement(int *n,int *m)
{
    //gestion d'une erreur faite dans le code
    int erreur=0;

    do
    {
        //affiche l'erreur si n<1 et m<1
        if (*n<1 && *m<1 && erreur==1 )
        {
            printf("La valeur des lignes et colonnes doit etre au moins egal a 1.\n");
        }
        else
        {
            //affiche l'erreur si n<1
            if(*n<1 && erreur==1)
            {
                printf("La valeur des lignes doit etre au moins egal a 1.\n");
            }
            //affiche l'erreur si m<1
            else if( *m<1 && erreur==1 )
            {
                printf("La valeur des colonnes doit etre au moins egal a 1.\n");
            }
        }

        printf("Saisir votre nombre de lignes : ");
        scanf("%d",n);

        printf("Saisir votre nombre de colonnes : ");
        scanf("%d",m);

        //on active la variable, si une erreur a été fait la obucle recommence et l'erreur s'affichera
        erreur=1;
    }while(*n<1 || *m<1);
        //tant que n ou m est inferieur a 1
}

void initialisation(int **tab,int n,int m)
{
    //les coordonnees sont mit a 1 pour éviter d'afficger une erreur dès le débus de la boucle
    int i=0,j=0,nbCellule=0,coordonne1=1,coordonne2=1,erreur=0;
    const int mort=0,vivant=1;

    //initialisation du tableau
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            tab[i][j]=0;
        }
    }

    //on saisie le nombre de cellule vivante
    printf("Saisir votre nombre de cellule vivante : ");
    scanf("%d",&nbCellule);

    for(i=0;i<nbCellule;i++)
    {
        //saisie des coordonnes pour chaque cellule en verifiant que l'utilisateur ne c'est pas tromper dans la saisie
        do
        {
            do
            {
                //on verifie si l'utilisateur ne c'est pas tromper, si c'est le cas, on le signal
                if( ( (coordonne1>n) || (coordonne2>m)|| (coordonne1<=0) || (coordonne2<=0) ) && (erreur==1) )
                {
                    printf("Erreur de saisie, les coordonnes doivent etre entre 1 et la limite.\n%d pour les lignes et %d pour les collones \n",n,m);
                }
                else if ( (tab[coordonne1-1][coordonne2-1]==vivant) && (erreur==1) )
                {
                        printf("Une cellule est deja placer a cet endroit.\n");
                }

                printf("Saisir les coordonnes de votre cellule numero %d : ",i+1);
                scanf("%d",&coordonne1);
                scanf("%d",&coordonne2);

                //on actionne l'erreur, si elle ne respecte pas les 2 conditions, alors l'erreur sera déclarer
                erreur=1;

            }while((coordonne1>n) || (coordonne2>m) ||(coordonne1<=0) || (coordonne2<=0) );
        }while((tab[coordonne1-1][coordonne2-1]==vivant));

        //Après avoir passer tout les test, il n'y a plus d'erreur
        erreur=0;

        //on attribue les coordonnées
        tab[coordonne1-1][coordonne2-1]=vivant;

    }



}

int nb_generation()
{
    int nbGeneration=0;

    do
    {
        printf("Saisir votre nombre de generations : ");
        scanf("%d",&nbGeneration);
    }while(nbGeneration<=1); // on vérifie que le nombre rentré est égal a 1 ou plus

    return nbGeneration;
}

void affiche(int **tab,int n, int m)
{
    int i=0,j=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(tab[i][j]==0)
            {
                printf(".");
            }
            else if(tab[i][j]==1)
            {
                printf("o");
            }
        }
        printf("\n");
    }
}

void affiche_fichier(int **tab,int n, int m,char *nom)
{
    int i=0,j=0;
    FILE* fichier=NULL;

    //ouverture du fichier
    fichier=fopen(nom,"a");

    //si l'ouverture réussi
    if (fichier != NULL)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(tab[i][j]==0)
                {
                    fputc('.',fichier);
                }
                else if(tab[i][j]==1)
                {
                    fputc('o',fichier);
                }
            }
            fputc('\n',fichier);
        }

        //on saute une ligne pour laisser un blanc pour voir les différentes générations
        fputc('\n',fichier);

        //on ferme le fichier
        fclose(fichier);
    }
    //si l'ouverture échoue
    else
    {
        printf("Erreur ouverture du fichier %s",*nom);
    }
}

void saisie_B_M(int B[9])
{
    int i=0,nombreSaisie=0;

    //saisie des valeurs pour le tableau
    for(i=0;i<9;i++)
    {
        do
        {
            //Si une mauvaise saisie est faite
            if( (nombreSaisie!=0) && (nombreSaisie!=1) )
            {
                printf("Le nombre doit etre 1 ( pour confirmer ) ou 0 ( pour refuser ).\n");
            }

            printf("Une cellule morte ayant %d voisins sera t-elle morte ou vivante a la generation suivante suivante ? ",i);
            scanf("%d",&nombreSaisie);
        }while( (nombreSaisie!=0) && (nombreSaisie!=1) );

        //saisie de la donnée
        B[i]=nombreSaisie;
    }
}

void saisie_S_M(int S[9])
{
    int i=0,nombreSaisie=0;

    //saisie des valeurs pour le tableau
    for(i=0;i<9;i++)
    {
        do
        {
            //Si une mauvaise saisie est faite
            if( (nombreSaisie!=0) && (nombreSaisie!=1) )
            {
                printf("Le nombre doit etre 1 ( pour confirmer ) ou 0 ( pour refuser ).\n");
            }

            printf("Une cellule vivante ayant %d voisins sera t-elle morte ou vivante a la generation suivante suivante ? ",i);
            scanf("%d",&nombreSaisie);
        }while( (nombreSaisie!=0) && (nombreSaisie!=1) );

        //saisie de la donnée
        S[i]=nombreSaisie;
    }
}

//---------------------PARTIE DES VON NEUMANN-------------------------------

void saisie_B_V(int BV[5])
{
    int i=0,nombreSaisie=0;

    //saisie des valeurs pour le tableau
    for(i=0;i<5;i++)
    {
        do
        {
            //Si une mauvaise saisie est faite
            if( (nombreSaisie!=0) && (nombreSaisie!=1) )
            {
                printf("Le nombre doit etre 1 ( pour confirmer ) ou 0 ( pour refuser ).\n");
            }

            printf("Une cellule morte ayant %d voisins sera t-elle morte ou vivante a la generation suivante suivante ? ",i);
            scanf("%d",&nombreSaisie);
        }while( (nombreSaisie!=0) && (nombreSaisie!=1) );

        //saisie de la donnée
        BV[i]=nombreSaisie;
    }
}

void saisie_S_V(int SV[5])
{
    int i=0,nombreSaisie=0;

    //saisie des valeurs pour le tableau
    for(i=0;i<5;i++)
    {
        do
        {
            //Si une mauvaise saisie est faite
            if( (nombreSaisie!=0) && (nombreSaisie!=1) )
            {
                printf("Le nombre doit etre 1 ( pour confirmer ) ou 0 ( pour refuser ).\n");
            }

            printf("Une cellule vivante ayant %d voisins sera t-elle morte ou vivante a la generation suivante suivante ? ",i);
            scanf("%d",&nombreSaisie);
        }while( (nombreSaisie!=0) && (nombreSaisie!=1) );

        //saisie de la donnée
        SV[i]=nombreSaisie;
    }
}

//---------------------GESTION DE LA FONCTION INITIALISATION_V2 QUI PRENDS EN CHARGE LES CELLULES FANTOMES-----------

void initialisation_V2(int **tab,int n,int m)
{
    //les coordonnees sont mit a 1 pour éviter d'afficger une erreur dès le débus de la boucle
    int i=0,j=0,nbCellule=0,coordonne1=1,coordonne2=1,erreur=0;
    const int mort=0,vivant=1,fantome=2;

    //initialisation du tableau
    for (i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            tab[i][j]=0;
        }
    }

    //----------------GESTION DES CELLULES VIVANTE------------

    //on saisie le nombre de cellule vivante
    printf("Saisir votre nombre de cellule vivante : ");
    scanf("%d",&nbCellule);

    for(i=0;i<nbCellule;i++)
    {
        //saisie des coordonnes pour chaque cellule en verifiant que l'utilisateur ne c'est pas tromper dans la saisie
        do
        {
            do
            {
                //on verifie si l'utilisateur ne c'est pas tromper, si c'est le cas, on le signal
                if( ( (coordonne1>n) || (coordonne2>m)|| (coordonne1<=0) || (coordonne2<=0) ) && (erreur==1) )
                {
                    printf("Erreur de saisie, les coordonnes doivent etre entre 1 et la limite.\n%d pour les lignes et %m pour les collones \n",n,m);
                }
                else if ( (tab[coordonne1-1][coordonne2-1]==vivant) && (erreur==1) )
                {
                        printf("Une cellule est deja placer a cet endroit.\n");
                }

                printf("Saisir les coordonnes de votre cellule numero %d : ",i+1);
                scanf("%d",&coordonne1);
                scanf("%d",&coordonne2);

                //on actionne l'erreur, si elle ne respecte pas les 2 conditions, alors l'erreur sera déclarer
                erreur=1;

            }while((coordonne1>n) || (coordonne2>m) ||(coordonne1<=0) || (coordonne2<=0) );
        }while((tab[coordonne1-1][coordonne2-1]==vivant));

        //Après avoir passer tout les test, il n'y a plus d'erreur
        erreur=0;

        //on attribue les coordonnées
        tab[coordonne1-1][coordonne2-1]=vivant;

    }

    //------------Gestion des coordonnées des cellules fantomes------------

    //on saisie le nombre de cellule vivante
    printf("Saisir votre nombre de cellule fantome : ");
    scanf("%d",&nbCellule);

    for(i=0;i<nbCellule;i++)
    {
        //saisie des coordonnes pour chaque cellule en verifiant que l'utilisateur ne c'est pas tromper dans la saisie
        do
        {
            do
            {
                //on verifie si l'utilisateur ne c'est pas tromper, si c'est le cas, on le signal
                if( ( (coordonne1>n) || (coordonne2>m)|| (coordonne1<=0) || (coordonne2<=0) ) && (erreur==1) )
                {
                    printf("Erreur de saisie, les coordonnes doivent etre entre 1 et la limite.\n%d pour les lignes et %m pour les collones \n",n,m);
                }
                else if ( ( (tab[coordonne1-1][coordonne2-1]==vivant) || (tab[coordonne1-1][coordonne2-1]==fantome) ) && (erreur==1) )
                {
                        printf("Une cellule est deja placer a cet endroit.\n");
                }

                printf("Saisir les coordonnes de votre cellule numero %d : ",i+1);
                scanf("%d",&coordonne1);
                scanf("%d",&coordonne2);

                //on actionne l'erreur, si elle ne respecte pas les 2 conditions, alors l'erreur sera déclarer
                erreur=1;

            }while((coordonne1>n) || (coordonne2>m) ||(coordonne1<=0) || (coordonne2<=0) );
        }while((tab[coordonne1-1][coordonne2-1]==vivant) || (tab[coordonne1-1][coordonne2-1]==fantome) );

        //Après avoir passer tout les test, il n'y a plus d'erreur
        erreur=0;

        //on attribue les coordonnées
        tab[coordonne1-1][coordonne2-1]=fantome;

    }

}

void affiche_V2(int **tab,int n, int m)
{
    int i=0,j=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(tab[i][j]==0)
            {
                printf(".");
            }
            else if(tab[i][j]==1)
            {
                printf("o");
            }
            else if(tab[i][j]==2)
            {
                printf("x");
            }
        }
        printf("\n");
    }
}

void affiche_fichier_V2(int **tab,int n, int m,char *nom)
{
    int i=0,j=0;
    FILE* fichier=NULL;

    //ouverture du fichier
    fichier=fopen(nom,"a");

    //si l'ouverture réussi
    if (fichier != NULL)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(tab[i][j]==0)
                {
                    fputc('.',fichier);
                }
                else if(tab[i][j]==1)
                {
                    fputc('o',fichier);
                }
                else if(tab[i][j]==2)
                {
                    fputc('x',fichier);
                }
            }
            fputc('\n',fichier);
        }

        //on saute une ligne pour laisser un blanc pour voir les différentes générations
        fputc('\n',fichier);

        //on ferme le fichier
        fclose(fichier);
    }
    //si l'ouverture échoue
    else
    {
        printf("Erreur ouverture du fichier %s",*nom);
    }
}
