#include <stdio.h>
#include <stdlib.h>
#define max_size 100

void LireDuTableau (int T[max_size],int n){
    for(int i=0; i<n ;i++){
printf("T[%d]=",i);
scanf("%d",&T[i]);
    }
}

void TriParSelection (int T[max_size],int n){
for(int i=0;i<n-1;i++){
    int idx_max = i;
    for(int j=i+1;j<n;j++){
     if (T[idx_max] < T[j]) idx_max=j;
    }
    echange(&T[idx_max],&T[i]);
}
}
void echange(int *a,int *b){
    int tmp = *a;
        *a = *b ;
        *b = tmp ;
         
}
void affichage (int T[max_size],int n){
    //message 
    printf("T=\n");
    for(int i=0;i<n;i++){
      printf("T[%d]=%d\n",i,T[i]);

    }
}

int main()
{
    int T[max_size];
    int n;
    printf("Saisir la taille du tableau ");
scanf("%d",&n);
    LireDuTableau(T[max_size],n);           
    TriParSelection(T[max_size],n);
    printf("\n Tableau tri :\n");
    affichage(T[max_size],n);       
     
    return 0;
}