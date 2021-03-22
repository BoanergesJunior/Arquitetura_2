#include <immintrin.h>
#include <stdio.h>

int main(){
    
    /*declarando vetores vecX, vecY e a(escalar)*/
    double vecX[] = {1.0, 2.0, 3.0, 4.0};
    double vecY[] = {5.0, 6.0, 7.0, 8.0};
	double a[] = {1,2,3,4};    

    /*carregando vetores para memória*/
    __m256d X =  _mm256_load_pd(vecX);
    __m256d Y =  _mm256_load_pd(vecY);
    __m256d A =  _mm256_load_pd(a);

    
    /*Realizando a multiplicação do vetor X pelo escalar A atribuindo a result e somando o valor de result
    com vetor Y e atribuindo ao result2*/
    __m256d result =  _mm256_mul_pd (X,A);
    __m256d result2 =  _mm256_add_pd (result, Y);

    /*Pegando as referências dos vetores para manipular*/
    double* vetorX = (double*)&X;
    double* vetorY = (double*)&Y;
    /*vetor para receber o resultado da equação da memória*/
    double res[4];
    /*Armazenando na memória*/
    _mm256_store_pd((double*)&res, result2);

    printf("X(0)= %lf,X(1)= %lf,X(2)= %lf,X(3)= %lf \n", 
    vetorX[0], vetorX[1], vetorX[2], vetorX[3]);''

    printf("Y(0)= %lf,Y(1)= %lf,Y(2)= %lf,Y(3)= %lf, \n", 
    vetorY[0], vetorY[1], vetorY[2], vetorY[3]);
    
    printf("escalar(0)= %lf,escalar(1)= %lf,escalar(2)= %lf,escalar(3)= %lf, \n", 
    A[0], A[1], A[2], A[3]);

    printf("R(0)= %lf,R(1)= %lf,R(2)= %lf,R(3)= %lf \n", 
    res[0], res[1], res[2], res[3]);



    return 0;
}
