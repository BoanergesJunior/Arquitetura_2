#include <immintrin.h>
#include <stdio.h>

int main(){

	/* Alocando memória para o vetor A de 8 posicoes*/
	float* a = (float*) aligned_alloc (32, 8*(sizeof(float)));
	
	/*For que captura a entrada de dados do console*/
	for (int i = 0; i < 8; i++){
		printf("Entre com os valores do vetor: ");
		scanf("%f", &a[i]);
	}
	/* Load usado para carregar o vetor "a" para a memória*/
	__m256 X =  _mm256_load_ps(a);
	
	/*método permute adjunto a uma mascara para que o vetor seja embaralhado com base no hexacimal ( segundo parametro passado)
	passado no proprio exercicio*/
	__m256 result =  _mm256_permute_ps(X, 0b11000110);
	
	/* Declaracao de ponteiros que carrega os respectivos valores de memória nos mesmos*/
	float* vetorX = (float*)&X;
	float* Result = (float*)&result;
	
	/* Local para a impressão dos resultados finais*/
	printf("X(0)= %f,X(1)= %f,X(2)= %f,X(3)= %f,X(4)= %f,X(5)= %f,X(6)= %f, X(7)= %f \n", 
    vetorX[0], vetorX[1], vetorX[2], vetorX[3],vetorX[4],vetorX[5],vetorX[6],vetorX[7]);
	
	printf("Result(0)= %f,Result(1)= %f,Result(2)= %f,Result(3)= %f,Result(4)= %f,Result(5)= %f,Result(6)= %f, Result(7)= %f \n", 
    Result[0], Result[1], Result[2], Result[3],Result[4],Result[5],Result[6],Result[7]);
	
	return 0;
}
	
