#ifndef CHANGEMENT_H_INCLUDED
#define CHANGEMENT_H_INCLUDED

int nb_voisins_M(int **tab, int i, int j, int n, int m);
void duplication(int** tab1,int** tab2,int n, int m);
void generation_suivante_M(int** tab1,int** tab2,int n, int m, int B[9],int S[9]);

//---------Partie des Von Neumann--------
int nb_voisins_V(int **tab, int i, int j, int n, int m);
void generation_suivante_V(int** tab1,int** tab2,int n, int m, int BV[5],int SV[5]);

//----------Partie de la V2 qui gérre la gestion des cellules fantomes chez les Moores-----
void generation_suivante_M_V2(int** tab1,int** tab2,int n, int m, int B[9],int S[9]);

#endif // CHANGEMENT_H_INCLUDED
