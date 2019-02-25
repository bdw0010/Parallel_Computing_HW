#include <stdlib.h>
#include <stdio.h>
void mm_4x4(int lda,double *at, double *b, double *c){

	double a00 = a[0+lda*0];
	double a10 = a[1+lda*0];
	double a20 = a[2+lda*0];
	double a30 = a[3+lda*0];
	double a01 = a[0+lda*1];
	double a11 = a[1+lda*1];
	double a21 = a[2+lda*1];
	double a31 = a[3+lda*1];
	double a02 = a[0+lda*2];
	double a12 = a[1+lda*2];
	double a22 = a[2+lda*2];
	double a32 = a[3+lda*2];
	double a03 = a[0+lda*3];
	double a13 = a[1+lda*3];
	double a23 = a[2+lda*3];
	double a33 = a[3+lda*3];

	double b00 = b[0+lda*0];
	double b10 = b[1+lda*0];
	double b20 = b[2+lda*0];
	double b30 = b[3+lda*0];
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

	c[0] = a00*b00 + a01*b10 + a02*b20 + a03*b30 ;
	c[1] = a10*b00 + a11*b10 + a12*b20 + a13*b30 ;
	c[2] = a20*b00 + a21*b10 + a22*b20 + a23*b30 ;
	c[3] = a30*b00 + a31*b10 + a32*b20 + a33*b30 ;
	c = c + lda;
	c[0] = a00*b01 + a01*b11 + a02*b21 + a03*b31 ;
	c[1] = a10*b01 + a11*b11 + a12*b21 + a13*b31 ;
	c[2] = a20*b01 + a21*b11 + a22*b21 + a23*b31 ;
	c[3] = a30*b01 + a31*b11 + a32*b21 + a33*b31 ;
	c = c + lda;
	c[0] = a00*b02 + a01*b12 + a02*b22 + a03*b32 ;
	c[1] = a10*b02 + a11*b12 + a12*b22 + a13*b32 ;
	c[2] = a20*b02 + a21*b12 + a22*b22 + a23*b32 ;
	c[3] = a30*b02 + a31*b12 + a32*b22 + a33*b32 ;
	c = c + lda;
	c[0] = a00*b03 + a01*b13 + a02*b23 + a03*b33 ;
	c[1] = a10*b03 + a11*b13 + a12*b23 + a13*b33 ;
	c[2] = a20*b03 + a21*b13 + a22*b23 + a23*b33 ;
	c[3] = a30*b03 + a31*b13 + a32*b23 + a33*b33 ;
	c = c + lda;
}

void square_dgemm4b(int n, double *A, double *B, double *C){
	int i,j,k;
	int M,N,K;
	int BS = 4;


	for(i=0;i<n;i=i+BS){
		M = min(BS,n - i);
		for(j=0;j<n;j=j+BS){
			N = min(BS,n - j);
			for(k=0;k<n;k=k+BS){
				K = min(BS,k - i);
				mm_4x4(n,A + i + k*n, B + k + j*n, C + i + j*n);
			}
		}
	}
}
