#include <stdio.h>
#include <stdlib.h>
#define max_taille 10
void lireMatricA(float A[max_taille][max_taille], int n)
{printf("donner les elemants du matrice A:\n");
    for (int i = 0; i < n; i++)
    {for (int j = 0; j < n; j++)
        {printf("A[%d][%d]=", i, j);
            scanf("%f", &A[i][j]);}}}
void lireMatriceB(float B[max_taille], int n) 
{ printf("\n dooner la matric B :\n");
    for (int i = 0; i < n; i++)
    { printf("B[%d]=", i);
        scanf("%f", &B[i]);}}
void affichageMatricAgm(float A[max_taille][max_taille], float B[max_taille], int n)
{printf("La matrice AGMnti :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {if (j == 0)
                printf("|");
            printf(" %.f", A[i][j]);
            if (j == n - 1)
            {   printf("| %.f|", B[i]);
            }} printf("\n");}}
void procedur(float a[max_taille][max_taille], float b[max_taille], int n){
    for (int i = 0; i < n; i++){
       float pivot_sol[i] = i;
    for (int k = 0; k < n - 1; k++)
    {float ref = 0;
        for (int i = k; i < n; i++)
            for (int j = k; j < n; j++)
                if (fabs(a[i][j]) > ref)
                {  ref = fabs(a[i][j]);
                  int   ligne = i;
                   int  colonne = j;}
        for (int j = k; j < n; j++)
        {    int   temp = a[k][j];
            a[k][j] = a[ligne][j];
            a[ligne][j] = temp;}
       int  temp = b[k];
        b[k] = b[ligne];
        b[ligne] = temp;
        for (int i = 0; i < n; i++)
        {temp = a[i][k];
            a[i][k] = a[i][colonne];
            a[i][colonne] = temp;}}}}

            
    void triangularize(float A[max_taille][max_taille], float B[max_taille], int n)
    { for (int k = 0; k < n - 1; k++)   {
            if (A[k][k] != 0){
                for (int i = k + 1; i < n; i++)
                {int m = A[i][k] / A[k][k];
                    for (int j = k; j < n; j++)
                    {     A[i][j] -= m * A[k][j];}
                    B[i] -= m * B[k];} }}}
    void backSubstitution(int n, float A[max_taille][max_taille], float B[max_taille], float x[n])
    {for (int i = n - 1; i >= 0; i--)   {
            x[i] = B[i];
            for (int j = i + 1; j < n; j++)
            {    x[i] -= A[i][j] * x[j];}
            x[i] /= A[i][i];}}
    int main(){
        float A[max_taille][max_taille], B[max_taille];
        int n;

        printf("saisir la taille du systeme liniare:");
        scanf("%d", &n);
        float X[n];
        lireMatricA(A, n);
        lireMatriceB(B, n);
        affichageMatricAgm(A, B, n);
        triangularize(A, B, n);
        printf("\n apre la triungulisation :\n");
        affichageMatricAgm(A, B, n);
        backSubstitution(n, A, B, X);
        printf("Solution:\n");
        for (int i = 0; i < n; i++)
        {
            printf("x%d = %.2f\n", i + 1, X[i]);
        }

        return 0;
    }
