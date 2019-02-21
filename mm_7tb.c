#include <stdlib.h>
#include <stdio.h>

#define min(a,b) (((a)<(b))?(a):(b))

void transpose7(int n, double *A, double *At){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            At[i+n*j] = A[j+n*i];
        }    
    }
}

void mm_4x4(int lda, double *at, double *b, double *c){
    
    double a00 = at[0];
    double a01 = at[1];
    double a02 = at[2];
    double a03 = at[3];
    double a10 = at[0+lda*1];
    double a11 = at[1+lda*1];
    double a12 = at[2+lda*1];
    double a13 = at[3+lda*1];
    double a20 = at[0+lda*2];
    double a21 = at[1+lda*2];
    double a22 = at[2+lda*2];
    double a23 = at[3+lda*2];
    double a30 = at[0+lda*3];
    double a31 = at[1+lda*3];
    double a32 = at[2+lda*3];
    double a33 = at[3+lda*3]; 

    double b00 = b[0];
    double b10 = b[1];
    double b20 = b[2];
    double b30 = b[3];
    double b01 = b[0+lda*1];
    double b11 = b[1+lda*1];
    double b21 = b[2+lda*1];
    double b31 = b[3+lda*1];
    double b02 = b[0+lda*2];
    double b12 = b[1+lda*2];
    double b22 = b[2+lda*2];
    double b32 = b[3+lda*2];
    double b03 = b[0+lda*3];
    double b13 = b[1+lda*3];
    double b23 = b[2+lda*3];
    double b33 = b[3+lda*3];     
    
    c[0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
    c[1] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
    c[2] = a20*b00 + a21*b10 + a22*b20 + a23*b30;
    c[3] = a30*b00 + a31*b10 + a32*b20 + a33*b30;    
    c = c + lda;
    c[0] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
    c[1] = a10*b01 + a11*b11 + a12*b21 + a13*b31;
    c[2] = a20*b01 + a21*b11 + a22*b21 + a23*b31;
    c[3] = a30*b01 + a31*b11 + a32*b21 + a33*b31;
    c = c + lda;
    c[0] = a00*b02 + a01*b12 + a02*b22 + a03*b32;
    c[1] = a10*b02 + a11*b12 + a12*b22 + a13*b32;
    c[2] = a20*b02 + a21*b12 + a22*b22 + a23*b32;
    c[3] = a30*b02 + a31*b12 + a32*b22 + a33*b32;
    c = c + lda;
    c[0] = a00*b03 + a01*b13 + a02*b23 + a03*b33;
    c[1] = a10*b03 + a11*b13 + a12*b23 + a13*b33;
    c[2] = a20*b03 + a21*b13 + a22*b23 + a23*b33;
    c[3] = a30*b03 + a31*b13 + a32*b23 + a33*b33;    
}    
    
void square_dgemm7tb(int n, double *A, double *B, double *C){
    int i,j,k;
    int M,N,K;
    double *At = malloc(n*n*sizeof(double));
    int BS = 4;
    transpose7(n,A,At);


    for(i=0;i<n;i=i+BS){
        M = min(BS,n - i);
        for(j=0;j<n;j=j+BS){
            N = min(BS,n - j);
            for(k=0;k<n;k=k+BS){
                K = min(BS,k - i);
                mm_4x4(n,At + k + i*n, B + k + j*n, C + i + j*n); 
            }
        }
    }
}