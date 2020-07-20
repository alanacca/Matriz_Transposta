float *EleMatriz(int n,int m){
    //srand(time(NULL));
    int i,j;
    float *vma;
    vma = (float*)malloc(sizeof(float)*n*m);
    if(vma!=NULL){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                //scanf("%f",&vma[i*m+j]);
                printf("digite o valor:\n");
                scanf("%f",&vma[i*m+j]);
            }
        }
        return vma;
    }
    return NULL;
}

void impMatriz(int n,int m,float *vma){
    int i,j;
    if(vma != NULL){
        for(i=0;i<n;i++){
                printf("\n");
            for(j=0;j<m;j++){
                printf("%.2f ",vma[i*m+j]);
            }
        }
    }
}
/*Faça os seguintes algoritmos considerando todas as matrizes armazenadas no vetor
a)recebe a matriz MAnxm e retorna a sua transposta
b) recebe duas matrizes Manxm e MBpxq e retorna
    b.1) MC = MA X MBT
    b.2) MC = MAT X MB
obs: fazer das duas formas
1 - uma variavel para colocar as transposta
2 - so pode usar as tres variaveis principais(MC,MA,MB)
c)receba uma matriz MAnxm e retorna um vetor com os elementos da triangular superior da matriz
d) receba uma matriz MAnxm e retorna TRUE se ela é simétrica e FALSE caso contrário
*/

//LETRA A
float *transposta(int n,int m, float *vma){
    int i,j;
    //float aux;
    float *vmat;
    vmat = (float*)malloc(sizeof(float)*n*m);
    if(vmat!=NULL){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                vmat[j*n+i] = vma[i*m+j];
            }
        }
        return vmat;
    }
    return NULL;
}


//LETRA C
float *TriangularSuperior(int n,float *vma){
    int i,j,k=0;
    int nelTri = (((n*n)-n)/2);
    float *vts = (float*)malloc(sizeof(float)*nelTri);
    if(vts!=NULL){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j>i){
                    vts[k]=vma[i*n+j];
                    k++;
                }
            }
        }
        return vts;

    }return NULL;
}


//LETRA B
//B.1- forma 1

float *MultABT(int n,int m, int p, int q,float *vma,float*vmb){
    int i,j,k;
    float *vmc = (float*)malloc(sizeof(float)*n*p);
    float *vmbt;
    vmbt = transposta(p,q,vmb);
    printf("\nmatriz transposta\n");
    impMatriz(p,q,vmbt);
    if(vma != NULL && vmb != NULL && vmbt != NULL){
        if(m == q){
            for(i=0;i<n;i++){
                for(j=0;j<p;j++){
                    vmc[i*p+j] = 0;
                    for(k=0;k<m;k++){
                        vmc[i*p+j] += (vma[i*m+k]*vmbt[k*p+j]);
                        printf("\n%.2f\n",vmc[i*p+j]);
                    }
                }
            }
            return vmc;
        }
        return NULL;
    }
}

//LETRA B
//B1 - forma 2

float *MultABT(int n,int m,int p,int q,float *vma,float *vmb){
    int i,j,k;
    float *vmc = (float*)malloc(sizeof(float)*n*p);
    if(vma != NULL && vmb != NULL & vmc != NULL){
        if(m==q){
            for(i=0;i<n;i++){
                for(j=0;j<p;j++){
                    vmc[i*p+j] = 0;
                    for(k=0;k<m;k++){
                        vmc[i*p+j] += (vma[i*m+k]*vmb[j*m+k]);
                    }
                }
            }
            return vmc;
        }
        return NULL;
    }
}


//LETRA B
//B2 - forma 1
float *MultATB(int n,int m,int p,int q,float *vma,float *vmb){
    int i,j,k;
    float *vmc = (float*)malloc(sizeof(float)*m*q);
    float *vmat;
    vmat = transposta(n,m,vma);
    if(vma != NULL && vmb != NULL && vmat != NULL && vmc != NULL){
        if(n == p){
            for(i=0;i<m;i++){
                for(j=0;j<q;j++){
                    vmc[i*q+j] = 0;
                    for(k=0;k<n;k++){
                        vmc[i*q+j] += (vmat[i*n+k]*vmb[k*q+j]);
                    }
                }
            }
            return vmc;
        }
        return NULL;
    }
}


//LETRA B
//B3 - forma 2
float *MultATB(int n,int m,int p,int q,float *vma,float *vmb){
    int i,j,k;
    float *vmc = (float*)malloc(sizeof(float)*m*q);
    if(vma != NULL && vmb != NULL && vmc != NULL){
        if(n==p){
            for(i=0;i<m;i++){
                for(j=0;j<q;j++){
                    vmc[i*q+j] = 0;
                    for(k=0;k<n;k++){
                        vmc[i*q+j] += (vma[k*n+i]*vmb[k*q+j]);
                    }
                }
            }
            return vmc;
        }
        return NULL;
    }
}


//LETRA D
int ESimetrica(int n,float *vma){
    int i,j,verif=0;
    if(vma != NULL){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i!=j){
                    if(vma[i*n+j]==vma[j*n+i]){
                        verif = 0;
                    }else{
                        verif = 1;
                    }
                }
            }
        }
        if(verif == 0){
            return TRUE;
        }else{
            return FALSE;
        }
    }return NULL;
}
