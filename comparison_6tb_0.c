#include <stdio.h>
#include <stdlib.h>
#include "mm_6tb.h"
#include "mm_0.h"
#include <time.h>

extern void dgemm_(char *transa, char *transb, int *m, int *n, int *k, double
        *alpha, double *a, int *lda, double *b, int *ldb, double *beta, double *c,
        int *ldc );


void main(){

    clock_t start, end;
    double cpu_time_used;
    
    for(int n = 16; n < 1000; n=n+16){

        double *A = malloc(n*n*sizeof(double));
        double *B = malloc(n*n*sizeof(double));
        double *C = malloc(n*n*sizeof(double));
        int i,j;

        srand(time(NULL));
        
        for (i=0;i < n; ++i){
            for (j=0; j < n; ++j){
                A[i + j*n] = rand()*1.;
                C[i + j*n] = 0.;
                B[i+j*n] = rand()*1.;    
            }
        }    
    
        double ave0; double ave6; double aveB; int num = 3; int BS = 32;
        ave0 = 0;
        ave6 = 0;
        aveB = 0;
        double alpha=1.0;
        double beta=1.0;
        for(i=0;i < num;++i){
            start = clock();
            dgemm_("N","N",&n,&n,&n, &alpha, A,&n, B, &n, &beta,C,&n);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            aveB += cpu_time_used/num;            
            
            start = clock();
            square_dgemm6tb(n,A,B,C,BS);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            ave6 += cpu_time_used/num;
                
            start = clock();
            square_dgemm0(n,A,B,C);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            ave0 += cpu_time_used/num;                
        }
        printf("\n n=%d: mm_6tb=%f s, mm_0=%f s, ratio = %f, ratioB = %f\n",n,ave6,ave0,ave0/ave6,ave0/aveB);
    }       
}    