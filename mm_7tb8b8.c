#include <stdlib.h>
#include <stdio.h>

#define min(a,b) (((a)<(b))?(a):(b))

void transpose7_8x8(int n, double *A, double *At){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            At[i+n*j] = A[j+n*i];
        }    
    }
}

void mm_8x8(int lda, double *at, double *b, double *c){
    
    double a00 = at[0];
    double a01 = at[1];
    double a02 = at[2];
    double a03 = at[3];
    double a04 = at[4];
    double a05 = at[5];
    double a06 = at[6];
    double a07 = at[7];
    double a10 = at[0+lda*1];
    double a11 = at[1+lda*1];
    double a12 = at[2+lda*1];
    double a13 = at[3+lda*1];
    double a14 = at[4+lda*1];
    double a15 = at[5+lda*1];
    double a16 = at[6+lda*1];
    double a17 = at[7+lda*1];
    double a20 = at[0+lda*2];
    double a21 = at[1+lda*2];
    double a22 = at[2+lda*2];
    double a23 = at[3+lda*2];
    double a24 = at[4+lda*2];
    double a25 = at[5+lda*2];
    double a26 = at[6+lda*2];
    double a27 = at[7+lda*2];
    double a30 = at[0+lda*3];
    double a31 = at[1+lda*3];
    double a32 = at[2+lda*3];
    double a33 = at[3+lda*3];
    double a34 = at[4+lda*3];
    double a35 = at[5+lda*3];
    double a36 = at[6+lda*3];
    double a37 = at[7+lda*3];
    double a40 = at[0+lda*4];
    double a41 = at[1+lda*4];
    double a42 = at[2+lda*4];
    double a43 = at[3+lda*4];
    double a44 = at[4+lda*4];
    double a45 = at[5+lda*4];
    double a46 = at[6+lda*4];
    double a47 = at[7+lda*4]; 
    double a50 = at[0+lda*5];
    double a51 = at[1+lda*5];
    double a52 = at[2+lda*5];
    double a53 = at[3+lda*5];
    double a54 = at[4+lda*5];
    double a55 = at[5+lda*5];
    double a56 = at[6+lda*5];
    double a57 = at[7+lda*5]; 
    double a60 = at[0+lda*6];
    double a61 = at[1+lda*6];
    double a62 = at[2+lda*6];
    double a63 = at[3+lda*6];
    double a64 = at[4+lda*6];
    double a65 = at[5+lda*6];
    double a66 = at[6+lda*6];
    double a67 = at[7+lda*6];
    double a70 = at[0+lda*7];
    double a71 = at[1+lda*7];
    double a72 = at[2+lda*7];
    double a73 = at[3+lda*7];
    double a74 = at[4+lda*7];
    double a75 = at[5+lda*7];
    double a76 = at[6+lda*7];
    double a77 = at[7+lda*7];   

    double b00 = b[0];
    double b10 = b[1];
    double b20 = b[2];
    double b30 = b[3];
    double b40 = b[4];
    double b50 = b[5];
    double b60 = b[6];
    double b70 = b[7];
    double b01 = b[0+lda*1];
    double b11 = b[1+lda*1];
    double b21 = b[2+lda*1];
    double b31 = b[3+lda*1];
    double b41 = b[4+lda*1];
    double b51 = b[5+lda*1];
    double b61 = b[6+lda*1];
    double b71 = b[7+lda*1];
    double b02 = b[0+lda*2];
    double b12 = b[1+lda*2];
    double b22 = b[2+lda*2];
    double b32 = b[3+lda*2];
    double b42 = b[4+lda*2];
    double b52 = b[5+lda*2];
    double b62 = b[6+lda*2];
    double b72 = b[7+lda*2];
    double b03 = b[0+lda*3];
    double b13 = b[1+lda*3];
    double b23 = b[2+lda*3];
    double b33 = b[3+lda*3];
    double b43 = b[4+lda*3];
    double b53 = b[5+lda*3];
    double b63 = b[6+lda*3];
    double b73 = b[7+lda*3];
    double b04 = b[0+lda*3];
    double b14 = b[1+lda*4];
    double b24 = b[2+lda*4];
    double b34 = b[3+lda*4];
    double b44 = b[4+lda*4];
    double b54 = b[5+lda*4];
    double b64 = b[6+lda*4];
    double b74 = b[7+lda*4];
    double b05 = b[0+lda*5];
    double b15 = b[1+lda*5];
    double b25 = b[2+lda*5];
    double b35 = b[3+lda*5];
    double b45 = b[4+lda*5];
    double b55 = b[5+lda*5];
    double b65 = b[6+lda*5];
    double b75 = b[7+lda*5];
    double b06 = b[0+lda*6];
    double b16 = b[1+lda*6];
    double b26 = b[2+lda*6];
    double b36 = b[3+lda*6];
    double b46 = b[4+lda*6];
    double b56 = b[5+lda*6];
    double b66 = b[6+lda*6];
    double b76 = b[7+lda*6];
    double b07 = b[0+lda*7];
    double b17 = b[1+lda*7];
    double b27 = b[2+lda*7];
    double b37 = b[3+lda*7];
    double b47 = b[4+lda*7];
    double b57 = b[5+lda*7];
    double b67 = b[6+lda*7];
    double b77 = b[7+lda*7];     
    
    c[0] = a00*b00 + a01*b10 + a02*b20 + a03*b30+ a04*b40 + a05*b50 + a06*b60 + a07*b70;
    c[1] = a10*b00 + a11*b10 + a12*b20 + a13*b30+ a14*b40 + a15*b50 + a16*b60 + a17*b70;
    c[2] = a20*b00 + a21*b10 + a22*b20 + a23*b30+ a24*b40 + a25*b50 + a26*b60 + a27*b70;
    c[3] = a30*b00 + a31*b10 + a32*b20 + a33*b30+ a34*b40 + a35*b50 + a36*b60 + a37*b70;
    c[4] = a40*b00 + a41*b10 + a42*b20 + a43*b30+ a44*b40 + a45*b50 + a46*b60 + a47*b70;
    c[5] = a50*b00 + a51*b10 + a52*b20 + a53*b30+ a54*b40 + a55*b50 + a56*b60 + a57*b70;
    c[6] = a60*b00 + a61*b10 + a62*b20 + a63*b30+ a64*b40 + a65*b50 + a66*b60 + a67*b70;
    c[7] = a70*b00 + a71*b10 + a72*b20 + a73*b30+ a74*b40 + a75*b50 + a76*b60 + a77*b70;     
    c = c + lda;
    c[0] = a00*b01 + a01*b11 + a02*b21 + a03*b31+ a04*b41 + a05*b51 + a06*b61 + a07*b71;
    c[1] = a10*b01 + a11*b11 + a12*b21 + a13*b31+ a14*b41 + a15*b51 + a16*b61 + a17*b71;
    c[2] = a20*b01 + a21*b11 + a22*b21 + a23*b31+ a24*b41 + a25*b51 + a26*b61 + a27*b71;
    c[3] = a30*b01 + a31*b11 + a32*b21 + a33*b31+ a34*b41 + a35*b51 + a36*b61 + a37*b71;
    c[4] = a40*b01 + a41*b11 + a42*b21 + a43*b31+ a44*b41 + a45*b51 + a46*b61 + a47*b71;
    c[5] = a50*b01 + a51*b11 + a52*b21 + a53*b31+ a54*b41 + a55*b51 + a56*b61 + a57*b71;
    c[6] = a60*b01 + a61*b11 + a62*b21 + a63*b31+ a64*b41 + a65*b51 + a66*b61 + a67*b71;
    c[7] = a70*b01 + a71*b11 + a72*b21 + a73*b31+ a74*b41 + a75*b51 + a76*b61 + a77*b71;     
    c = c + lda;
    c[0] = a00*b02 + a01*b12 + a02*b22 + a03*b32+ a04*b42 + a05*b52 + a06*b62 + a07*b72;
    c[1] = a10*b02 + a11*b12 + a12*b22 + a13*b32+ a14*b42 + a15*b52 + a16*b62 + a17*b72;
    c[2] = a20*b02 + a21*b12 + a22*b22 + a23*b32+ a24*b42 + a25*b52 + a26*b62 + a27*b72;
    c[3] = a30*b02 + a31*b12 + a32*b22 + a33*b32+ a34*b42 + a35*b52 + a36*b62 + a37*b72;
    c[4] = a40*b02 + a41*b12 + a42*b22 + a43*b32+ a44*b42 + a45*b52 + a46*b62 + a47*b72;
    c[5] = a50*b02 + a51*b12 + a52*b22 + a53*b32+ a54*b42 + a55*b52 + a56*b62 + a57*b72;
    c[6] = a60*b02 + a61*b12 + a62*b22 + a63*b32+ a64*b42 + a65*b52 + a66*b62 + a67*b72;
    c[7] = a70*b02 + a71*b12 + a72*b22 + a73*b32+ a74*b42 + a75*b52 + a76*b62 + a77*b72;     
    c = c + lda;
    c[0] = a00*b03 + a01*b13 + a02*b23 + a03*b33+ a04*b43 + a05*b53 + a06*b63 + a07*b73;
    c[1] = a10*b03 + a11*b13 + a12*b23 + a13*b33+ a14*b43 + a15*b53 + a16*b63 + a17*b73;
    c[2] = a20*b03 + a21*b13 + a22*b23 + a23*b33+ a24*b43 + a25*b53 + a26*b63 + a27*b73;
    c[3] = a30*b03 + a31*b13 + a32*b23 + a33*b33+ a34*b43 + a35*b53 + a36*b63 + a37*b73;
    c[4] = a40*b03 + a41*b13 + a42*b23 + a43*b33+ a44*b43 + a45*b53 + a46*b63 + a47*b73;
    c[5] = a50*b03 + a51*b13 + a52*b23 + a53*b33+ a54*b43 + a55*b53 + a56*b63 + a57*b73;
    c[6] = a60*b03 + a61*b13 + a62*b23 + a63*b33+ a64*b43 + a65*b53 + a66*b63 + a67*b73;
    c[7] = a70*b03 + a71*b13 + a72*b23 + a73*b33+ a74*b43 + a75*b53 + a76*b63 + a77*b73;     
    c = c + lda;
    c[0] = a00*b04 + a01*b14 + a02*b24 + a03*b34+ a04*b44 + a05*b54 + a06*b64 + a07*b74;
    c[1] = a10*b04 + a11*b14 + a12*b24 + a13*b34+ a14*b44 + a15*b54 + a16*b64 + a17*b74;
    c[2] = a20*b04 + a21*b14 + a22*b24 + a23*b34+ a24*b44 + a25*b54 + a26*b64 + a27*b74;
    c[3] = a30*b04 + a31*b14 + a32*b24 + a33*b34+ a34*b44 + a35*b54 + a36*b64 + a37*b74;
    c[4] = a40*b04 + a41*b14 + a42*b24 + a43*b34+ a44*b44 + a45*b54 + a46*b64 + a47*b74;
    c[5] = a50*b04 + a51*b14 + a52*b24 + a53*b34+ a54*b44 + a55*b54 + a56*b64 + a57*b74;
    c[6] = a60*b04 + a61*b14 + a62*b24 + a63*b34+ a64*b44 + a65*b54 + a66*b64 + a67*b74;
    c[7] = a70*b04 + a71*b14 + a72*b24 + a73*b34+ a74*b44 + a75*b54 + a76*b64 + a77*b74;     
    c = c + lda;
    c[0] = a00*b05 + a01*b15 + a02*b25 + a03*b35+ a04*b45 + a05*b55 + a06*b65 + a07*b75;
    c[1] = a10*b05 + a11*b15 + a12*b25 + a13*b35+ a14*b45 + a15*b55 + a16*b65 + a17*b75;
    c[2] = a20*b05 + a21*b15 + a22*b25 + a23*b35+ a24*b45 + a25*b55 + a26*b65 + a27*b75;
    c[3] = a30*b05 + a31*b15 + a32*b25 + a33*b35+ a34*b45 + a35*b55 + a36*b65 + a37*b75;
    c[4] = a40*b05 + a41*b15 + a42*b25 + a43*b35+ a44*b45 + a45*b55 + a46*b65 + a47*b75;
    c[5] = a50*b05 + a51*b15 + a52*b25 + a53*b35+ a54*b45 + a55*b55 + a56*b65 + a57*b75;
    c[6] = a60*b05 + a61*b15 + a62*b25 + a63*b35+ a64*b45 + a65*b55 + a66*b65 + a67*b75;
    c[7] = a70*b05 + a71*b15 + a72*b25 + a73*b35+ a74*b45 + a75*b55 + a76*b65 + a77*b75;     
    c = c + lda;
    c[0] = a00*b06 + a01*b16 + a02*b26 + a03*b36+ a04*b46 + a05*b56 + a06*b66 + a07*b76;
    c[1] = a10*b06 + a11*b16 + a12*b26 + a13*b36+ a14*b46 + a15*b56 + a16*b66 + a17*b76;
    c[2] = a20*b06 + a21*b16 + a22*b26 + a23*b36+ a24*b46 + a25*b56 + a26*b66 + a27*b76;
    c[3] = a30*b06 + a31*b16 + a32*b26 + a33*b36+ a34*b46 + a35*b56 + a36*b66 + a37*b76;
    c[4] = a40*b06 + a41*b16 + a42*b26 + a43*b36+ a44*b46 + a45*b56 + a46*b66 + a47*b76;
    c[5] = a50*b06 + a51*b16 + a52*b26 + a53*b36+ a54*b46 + a55*b56 + a56*b66 + a57*b76;
    c[6] = a60*b06 + a61*b16 + a62*b26 + a63*b36+ a64*b46 + a65*b56 + a66*b66 + a67*b76;
    c[7] = a70*b06 + a71*b16 + a72*b26 + a73*b36+ a74*b46 + a75*b56 + a76*b66 + a77*b76;     
    c = c + lda;
    c[0] = a00*b07 + a01*b17 + a02*b27 + a03*b37+ a04*b47 + a05*b57 + a06*b67 + a07*b77;
    c[1] = a10*b07 + a11*b17 + a12*b27 + a13*b37+ a14*b47 + a15*b57 + a16*b67 + a17*b77;
    c[2] = a20*b07 + a21*b17 + a22*b27 + a23*b37+ a24*b47 + a25*b57 + a26*b67 + a27*b77;
    c[3] = a30*b07 + a31*b17 + a32*b27 + a33*b37+ a34*b47 + a35*b57 + a36*b67 + a37*b77;
    c[4] = a40*b07 + a41*b17 + a42*b27 + a43*b37+ a44*b47 + a45*b57 + a46*b67 + a47*b77;
    c[5] = a50*b07 + a51*b17 + a52*b27 + a53*b37+ a54*b47 + a55*b57 + a56*b67 + a57*b77;
    c[6] = a60*b07 + a61*b17 + a62*b27 + a63*b37+ a64*b47 + a65*b57 + a66*b67 + a67*b77;
    c[7] = a70*b07 + a71*b17 + a72*b27 + a73*b37+ a74*b47 + a75*b57 + a76*b67 + a77*b77;     
    c = c + lda;
}    
    
void square_dgemm7tb8b8(int n, double *A, double *B, double *C){
    int i,j,k;
    int M,N,K;
    double *At = malloc(n*n*sizeof(double));
    int BS = 8;
    transpose7(n,A,At);


    for(i=0;i<n;i=i+BS){
        M = min(BS,n - i);
        for(j=0;j<n;j=j+BS){
            N = min(BS,n - j);
            for(k=0;k<n;k=k+BS){
                K = min(BS,k - i);
                mm_8x8(n,At + k + i*n, B + k + j*n, C + i + j*n); 
            }
        }
    }
}