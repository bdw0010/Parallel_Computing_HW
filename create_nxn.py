import sys
import os

lsep = os.linesep

n = int(sys.argv[1])

rf = open('%ix%i.c'%(n,n),'w')
rf.write("#include <stdlib.h>%s"%lsep)
rf.write("#include <stdio.h>%s"%lsep)

rf.write("void mm_%ix%i(int lda,double *at, double *b, double *c){%s"%(n,n,lsep))
rf.write(lsep)
for i in range(n):
    for j in range(n):
        rf.write("\tdouble a%i%i = a[%i+lda*%i];%s"%(j,i,j,i,lsep))
rf.write(lsep)
for i in range(n):
    for j in range(n):
        rf.write("\tdouble b%i%i = b[%i+lda*%i];%s"%(j,i,j,i,lsep))
rf.write(lsep)


pluses = n*['+']
pluses[-1] = ';'+lsep

for k in range(n):
    for i in range(n):
        rf.write('\tc[%i] ='%i)
        for j in range(n):
            rf.write(' a%i%i*b%i%i %s'%(i,j,j,k,pluses[j]))
    rf.write('\tc = c + lda;%s'%lsep)
rf.write('}'+lsep+lsep)

rf.write('void square_dgemm%ib(int n, double *A, double *B, double *C){%s'% (n,lsep))
rf.write('\tint i,j,k;%s'%lsep)
rf.write('\tint M,N,K;%s'%lsep)
rf.write('\tint BS = %i;%s'%(n,lsep))
rf.write(lsep+lsep)
rf.write('\tfor(i=0;i<n;i=i+BS){%s'%lsep)
rf.write('\t\tM = min(BS,n - i);%s'%lsep)
rf.write('\t\tfor(j=0;j<n;j=j+BS){%s'%lsep)
rf.write('\t\t\tN = min(BS,n - j);%s'%lsep)
rf.write('\t\t\tfor(k=0;k<n;k=k+BS){%s'%lsep)
rf.write('\t\t\t\tK = min(BS,k - i);%s'%lsep)
rf.write('\t\t\t\tmm_%ix%i(n,A + i + k*n, B + k + j*n, C + i + j*n);%s'%(n,n,lsep))
rf.write('\t\t\t}%s'%lsep)
rf.write('\t\t}%s'%lsep)
rf.write('\t}%s'%lsep)
rf.write('}%s'%lsep)

rf.close()


