  
    

void square_dgemm0(int n, double *A, double *B, double *C){
    int i,j,k;
    double c;
    
    for(i=0; i<n; ++i){
        for(j=0; j<n; ++j){
            c = 0.;
            for(k=0; k<n; ++k){
                c+= A[n*i+k]*B[n*k+j];
            }
            C[n*i+j] = c + C[n*i+j];
        }
    }
}    


    
    
    