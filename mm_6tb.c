#include <stdlib.h>
#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))

void transpose(int n, double *A, double *At){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            At[i+n*j] = A[j+n*i];
        }    
    }
}    

void mm_Block(int lda, int K, int M, int N, double *at, double *b, double *c){
    int m,p,k;
    
    if(K % 8 == 0){  
        register double cc1;
        register double cc2;
        register double cc3;
        register double cc4;
        register double cc5;
        register double cc6;
        register double cc7;
        register double cc8;
        for(p=0; p < N; p++){
            for(m=0; m < M; m++){
                cc1 = 0.;
                cc2 = 0.;
                cc3 = 0.;
                cc4 = 0.;
                cc5 = 0.;
                cc6 = 0.;
                cc7 = 0.;
                cc8 = 0.;
                for(k=0; k < K; k=k + 8){
                    cc1 += at[k+lda*m]*b[k+lda*p];
                    cc2 += at[k+1+lda*m]*b[k+1+lda*p];
                    cc3 += at[k+2+lda*m]*b[k+2+lda*p];
                    cc4 += at[k+3+lda*m]*b[k+3+lda*p];
                    cc5 += at[k+4+lda*m]*b[k+4+lda*p];
                    cc6 += at[k+5+lda*m]*b[k+5+lda*p];
                    cc7 += at[k+6+lda*m]*b[k+6+lda*p];
                    cc8 += at[k+7+lda*m]*b[k+7+lda*p];
                }
                c[m+p*lda] += cc1 + cc2 + cc3 + cc4+cc5 + cc6 + cc7 + cc8;
            }
        }
    }
    
    else if(K % 4 == 0){  
        register double cc1;
        register double cc2;
        register double cc3;
        register double cc4;    
        for(p=0; p < N; p++){
            for(m=0; m < M; m = m + 1){
                cc1 = 0.;
                cc2 = 0.;
                cc3 = 0.;
                cc4 = 0.;
                for(k=0; k < K; k=k + 4){
                    cc1 += at[k+lda*m]*b[k+lda*p];
                    cc2 += at[k+1+lda*m]*b[k+1+lda*p];
                    cc3 += at[k+2+lda*m]*b[k+2+lda*p];
                    cc4 += at[k+3+lda*m]*b[k+3+lda*p];
                }               
                c[m+p*lda] += cc1 + cc2 + cc3 + cc4;
            }
        }
    }
    else if(K % 2 == 0){  
        register double cc1;
        register double cc2;    
        for(p=0; p < N; p++){
            for(m=0; m < M; m++){
                cc1 = 0.;
                cc2 = 0.;
                for(k=0; k < K; k=k + 2){
                    cc1 += at[k+lda*m]*b[k+lda*p];
                    cc2 += at[k+1+lda*m]*b[k+1+lda*p];
                }
                c[m+p*lda] += cc1 + cc2;
            }
        }
    }
    else{
        register double cc1;        
        for(p=0; p < N; p++){
            for(m=0; m < M; m++){
                cc1 = 0.;
                for(k=0; k < K; k++){
                    cc1 += at[k+lda*m]*b[k+lda*p];
                }
                c[m+p*lda] += cc1;
            }
        }    
    }
}  

         
void square_dgemm6tb(int n, double *A, double *B, double *C,int BS){
    int i,j,k;
    int M,N,K;
    double *At = malloc(n*n*sizeof(double));
    transpose(n,A,At);


    for(i=0;i<n;i=i+BS){
        M = min(BS,n - i);
        for(j=0;j<n;j=j+BS){
            N = min(BS,n - j);
            for(k=0;k<n;k=k+BS){
                K = min(BS,k - i);
                mm_Block(n,K,M,N,At + k + i*n, B + k + j*n, C + i + j*n); 
            }
        }
    }
}

 

    
    
    