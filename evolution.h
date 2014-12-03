#ifndef EVOLUTION_H_INCLUDED
#define EVOLUTION_H_INCLUDED

void jeu_M(int **tab1,int n,int m,int B[9],int S[9],int ng);
void jeu_conway(int **tab1,int n, int m, int ng);
void jeu_fredkin_M(int **tab1,int n, int m, int ng);

//---------------PARTIE DES VON NEUMANN----------------
void jeu_V(int **tab1,int n,int m,int BV[5],int SV[5],int ng);
void automate_B13_S13_V(int **tab1,int n, int m, int ng);

//---------------AUTOMATE DE LA V2 DES MOORES ET JEU_M_V2 QUI GERE LES CELLULES FANTOMES-------------
void jeu_M_V2(int **tab1,int n,int m,int B[9],int S[9],int ng);
void automate_B2_S_M_V2(int **tab1,int n, int m, int ng);

#endif // EVOLUTION_H_INCLUDED
