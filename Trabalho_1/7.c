#include <immintrin.h>
#include <stdio.h>

int main(){

	/* Declaracao dos vetores A e B com os respectivos valores*/
	float vecA[] = {0.0,2.0,4.0,6.0,8.0,10.0,12.0,14.0};
	float vecB[] = {1.0,3.0,5.0,7.0,9.0,11.0,13.0,15.0};
	
	/*Carregando na memória os vetores A e B e salvando no A e B respectivamente*/
	__m256 A =  _mm256_load_ps(vecA);
	__m256 B =  _mm256_load_ps(vecB);
	
	/*Usando o método shuffle os vetores são embaralhado utilizando a mascara*/
	/* Para a descoberta da máscara foi testando a variação do código hexadecimal junto a documentação*/
	__m256 result =  _mm256_shuffle_ps(A,B,0b01110100);
	
	/*Pegando os vetores da memória e salvando nos respectivos ponteiros*/
	float* vetorA = (float*)&A;
	float* vetorB = (float*)&B;
	float* Result = (float*)&result;
	
	/*Impressão dos dados na tela*/
	printf("A(0)= %f,A(1)= %f,A(2)= %f,A(3)= %f,A(4)= %f,A(5)= %f,A(6)= %f ,A(7)= %f\n", 
    vetorA[0], vetorA[1], vetorA[2], vetorA[3],vetorA[4],vetorA[5],vetorA[6],vetorA[7]);
    
    
    
	printf("B(0)= %f,B(1)= %f,B(2)= %f,B(3)= %f,B(4)= %f,B(5)= %f,B(6)= %f ,B(7)= %f\n", 
    vetorB[0], vetorB[1], vetorB[2], vetorB[3],vetorB[4],vetorB[5],vetorB[6],vetorB[7]);
    
	
	
	printf("Valor de Controle: 0b01110100 \n");
	
	printf("Result(0)= %f,Result(1)= %f,Result(2)= %f,Result(3)= %f,Result(4)= %f,Result(5)= %f,Result(6)= %f ,Result(7)= %f\n", 
    Result[0], Result[1], Result[2], Result[3],Result[4],Result[5],Result[6],Result[7]);
    
    
    return 0;
}
	
	
	
