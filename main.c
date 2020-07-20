#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TRUE (1==1)
#define FALSE (1==0)
#include "matriz.c"


int main()
{
    int i,j,result;
    //int k,l;
    int n;
    //int m,p,q;
    printf("digite a quantidade de linha a:\n");
    scanf("%d",&n);
    /*int nelTri = (n*n);
    nelTri -=n;
    nelTri /=2;
    printf("\nvalor:%d\n",nelTri);*/
    /*printf("digite a quantidade de coluna a:\n");
    scanf("%d",&m);
    printf("digite a quantidade de linha b:\n");
    scanf("%d",&p);
    printf("digite a quantidade de coluna b:\n");
    scanf("%d",&q);*/
    float *vma = (float*)malloc(sizeof(float)*n*n);
    vma = EleMatriz(n,n);
    printf("\nmatriz a\n");
    impMatriz(n,n,vma);
    result = ESimetrica(n,vma);
    printf("\n%d",result);
    /*float *vmb = (float*)malloc(sizeof(float)*p*q);
    vmb = EleMatriz(p,q);
    printf("\nmatriz b\n");
    impMatriz(p,q,vmb);
    float *recebemultATB;
    recebemultATB = MultATB(n,m,p,q,vma,vmb);
    for(k=0;k<m;k++){
        printf("\n");
        for(l=0;l<q;l++){
            printf("%.2f\t",recebemultATB[k*q+l]);
        }
    }
    */
    /*float *RecVet;
    RecVet = TriangularSuperior(n,vma);
    printf("\ntriangular superior:\n");
    for(i=0;i<nelTri;i++){
        printf("%.2f\t",RecVet[i]);
    }*/
    /*float *RecMat;
    RecMat= transposta(n,m,vma);
    for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%.2f \t",RecMat[i*n+j]);
        }
    }*/

}
