#ifndef INITILISATION_H_INCLUDED
#define INITILISATION_H_INCLUDED

void dimensionnement(int *n,int *m);
void initialisation(int **tab,int n,int m);
int nb_generation();
void affiche(int **tab,int n, int m);
void affiche_fichier(int **tab,int n, int m,char *nom);
void saisie_B_M(int B[9]);
void saisie_S_M(int S[9]);

//-------Partie des Von Neumann-----
void saisie_B_V(int BV[5]);
void saisie_S_V(int SV[5]);

//--------Partie V2 qui gère les cellules fantomes----
void initialisation_V2(int **tab,int n,int m);
void affiche_V2(int **tab,int n, int m);
void affiche_fichier_V2(int **tab,int n, int m,char *nom);

#endif // INITILISATION_H_INCLUDED
