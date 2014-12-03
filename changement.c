#include <stdio.h>
#include <stdlib.h>

int nb_voisins_M(int **tab, int i, int j, int n, int m)
{
    int nbVoisins=0,x=0,y=0;
    const int vivant=1,mort=0;

    //On parcour tout ce qui entoure la cellule
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            //on vérifie qu'on ne sort pas du tableau et qu'on accede pas a la cellule ciblé
            if( ((i+x-1)>=0) && ((j+y-1)>=0) && ((j+y-1)<m) && ((i+x-1)<n) && ( (i+x!=i+1) || (j+y!=j+1) ) )
            {
                //Si la cellule autour est vivante, on augmente de 1 le nombre de voisin
                if( (tab[i+x-1][j+y-1]==vivant) )
                {
                    nbVoisins++;
                }
            }
        }
    }

    return nbVoisins;
}

void duplication(int** tab1,int** tab2,int n, int m)
{
    int i=0,j=0;

    //on parcour chaque case du tab2 et on attribue la valeur de la case correspondante du tab1
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            tab2[i][j]=tab1[i][j];
        }
    }
}

void generation_suivante_M(int** tab1,int** tab2,int n, int m, int B[9],int S[9])
{
    int i=0,j=0,nbVoisins=0;
    const int vivant=1,mort=0;

    //On regarde en premier lieu si les cellules survives ou meurs
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //si elle est vivante, alors on regard le nombre de voisin.
            if(tab1[i][j]==vivant)
            {
                nbVoisins=nb_voisins_M(tab1,i,j,n,m);

                //si le nombre de voisin ne permet pas a la cellule de vivre, elle devient morte a la prochaine génération
                if(S[nbVoisins]==mort)
                {
                    tab2[i][j]=mort;
                }
            }
            else
            {

                nbVoisins=nb_voisins_M(tab1,i,j,n,m);

                //Si le nombre de voisin lui permet de vivre, alors elle sera vivante a la prochaine génération
                if(B[nbVoisins]==vivant)
                {
                    tab2[i][j]=vivant;
                }
            }
        }
    }

}

//---------------------------PARTIE DES VON NEUMANN-------------------------------

int nb_voisins_V(int **tab, int i, int j, int n, int m)
{
    int nbVoisins=0,x=0,y=0;
    const int vivant=1,mort=0;

    //On parcour tout ce qui entoure la cellule
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            //on vérifie qu'on ne sort pas du tableau et que c'est bien le voisinage des Moores (en enlevant les cases paire)
            if( ((i+x-1)>=0) && ((j+y-1)>=0) && ((j+y-1)<m) && ((i+x-1)<n) && (x+y!=2) && (x+y!=0) && (x+y!=4) )
            {
                    //Si la cellule autour est vivante, on augmente de 1 le nombre de voisin
                    if( (tab[i+x-1][j+y-1]==vivant) )
                    {
                        nbVoisins++;
                    }
            }
        }
    }

    return nbVoisins;
}

void generation_suivante_V(int** tab1,int** tab2,int n, int m, int BV[5],int SV[5])
{
    int i=0,j=0,nbVoisins=0;
    const int vivant=1,mort=0;

    //On regarde en premier lieu si les cellules survives ou meurs
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //si elle est vivante, alors on regard le nombre de voisin.
            if(tab1[i][j]==vivant)
            {
                nbVoisins=nb_voisins_V(tab1,i,j,n,m);

                //si le nombre de voisin ne permet pas a la cellule de vivre, elle devient morte a la prochaine génération
                if(SV[nbVoisins]==mort)
                {
                    tab2[i][j]=mort;
                }
            }
            else
            {

                nbVoisins=nb_voisins_V(tab1,i,j,n,m);

                //Si le nombre de voisin lui permet de vivre, alors elle sera vivante a la prochaine génération
                if(BV[nbVoisins]==vivant)
                {
                    tab2[i][j]=vivant;
                }
            }
        }
    }
}

//---------------------GESTION DE LA FONCTION GENERATION SUIVANTE DES MOORES QUI PRENDS EN CHARGE LES CELLULES FANTOMES-----------

void generation_suivante_M_V2(int** tab1,int** tab2,int n, int m, int B[9],int S[9])
{
    int i=0,j=0,nbVoisins=0;
    const int vivant=1,mort=0,fantome=2;

    //On regarde en premier lieu si les cellules survives ou meurs
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //si elle est vivante, alors on regard le nombre de voisin.
            if(tab1[i][j]==vivant)
            {
                nbVoisins=nb_voisins_M(tab1,i,j,n,m);

                //si le nombre de voisin ne permet pas a la cellule de vivre, elle devient morte a la prochaine génération
                if(S[nbVoisins]==mort)
                {
                    tab2[i][j]=fantome;
                }
            }
            else if(tab1[i][j]==fantome)
            {
                tab2[i][j]=mort;
            }
            else
            {

                nbVoisins=nb_voisins_M(tab1,i,j,n,m);

                //Si le nombre de voisin lui permet de vivre, alors elle sera vivante a la prochaine génération
                if(B[nbVoisins]==vivant)
                {
                    tab2[i][j]=vivant;
                }
            }
        }
    }

}
