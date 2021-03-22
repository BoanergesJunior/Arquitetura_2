#include <immintrin.h>
#include <stdio.h>

int main(){

    __m256d A = _mm256_setr_pd(1.0, 2.0, 3.0, 4.0);
    __m256d B = _mm256_setr_pd(8.0, 9.0, 10.0, 11.0);
    __m256d C = _mm256_setr_pd(16.0, 17.0, 18.0, 19.0);

    /**
     * Recebe os valores de cada vetor por referência para poder imprimir*/
    __m256d result = _mm256_fnmadd_pd(A, B, C);
    double* vetorA = (double*)&A;
    double* vetorB = (double*)&B;
    double* vetorC = (double*)&C;
    double* res = (double*)&result;

    /**Print dos vetores resultantes*/
    printf("A(0)= %lf,A(1)= %lf,A(2)= %lf,A(3)= %lf \n", 
    vetorA[0], vetorA[1], vetorA[2], vetorA[3]);

    printf("B(0)= %lf,B(1)= %lf,B(2)= %lf,B(3)= %lf, \n", 
    vetorB[0], vetorB[1], vetorB[2], vetorB[3]);

    printf("C(0)= %lf,C(1)= %lf,C(2)= %lf,C(3)= %lf \n", 
    vetorC[0], vetorC[1], vetorC[2], vetorC[3]);

    /**Print do resultado da conta A + B + C*/
    printf("R(0)= %lf,R(1)= %lf,R(2)= %lf,R(3)= %lf \n", 
    res[0], res[1], res[2], res[3]);



    return 0;
}
