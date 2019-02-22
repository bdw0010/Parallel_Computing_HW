#include <stdio.h>
#include <stdlib.h>
#include "mm_7tb8b8.h"
#include "mm_7tb4b4.h"
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
    
        double ave0; double ave7_8; double ave7_4; double aveB; int num = 3;int BS = 32;
        ave0 = 0;
        ave7_4 = 0;
        ave7_8 = 0;
        aveB = 0;
        double alpha=1.0;
        double beta=1.0;
        for(i=0;i < num;++i){
            start = clock();
            dgemm_("N","N",&n,&n,&n, &alpha, A,&n, B, &n, &beta,C,&n);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            aveB += cpu_time_used/num;    
            for (int p=0;i < n; ++i){
                for (j=0; j < n; ++j){
                    C[p + j*n] = 1.;
                }
            }             

            start = clock();
            square_dgemm7tb(n,A,B,C);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            ave7_4 += cpu_time_used/num;
            for (int p=0;i < n; ++i){
                for (j=0; j < n; ++j){
                    C[p + j*n] = 1.;
                }
            } 
            
            start = clock();
            square_dgemm7tb8b8(n,A,B,C);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            ave7_8 += cpu_time_used/num;
            for (int p=0;i < n; ++i){
                for (j=0; j < n; ++j){
                    C[p + j*n] = 1.;
                }
            } 
            
            start = clock();
            square_dgemm0(n,A,B,C);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            ave0 += cpu_time_used/num; 
            for (int p=0;i < n; ++i){
                for (j=0; j < n; ++j){
                    C[p + j*n] = 1.;
                }
            }             
        }
        printf("\n n=%d: mm_0=%f s, mm_7tb4*4=%f s, mm_7tb8*8=%f s \n",n,ave0,ave7_4,ave7_8);
        printf(" n=%d: r7_4*4 = %f, r7_8*8 = %f, rB = %f, r7_8*8/rB = %f \n",n,ave0/ave7_4,ave0/ave7_8,ave0/aveB,aveB/ave7_8);    
    }       
}    