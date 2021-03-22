#include <immintrin.h>
#include <stdio.h>

int main(){

	/*Alocando memória para os vetores a e b*/
	double* a = (double*) aligned_alloc (32, 4*(sizeof(double)));
	double* b = (double*) aligned_alloc (32, 4*(sizeof(double)));
	
	/*Inserindo valores do vetor a*/
	for (int i = 0; i < 4; i++){
		printf("Entre com o primeiro vetor: ");
		scanf("%le", &a[i]);
	}
	
	/*Inserindo valores do vetor b*/
	for (int i = 0; i < 4; i++){
		printf("Entre com segundo vetor: ");
		scanf("%le", &b[i]);
	}

	/*Carrega vetores a e B para memória e referencia em A e B*/
	__m256d A =  _mm256_load_pd(a);
	__m256d B =  _mm256_load_pd(b);
	
	/*Realiza a soma horizontal dos vetores A e B*/
	__m256d result = _mm256_hadd_pd(A,B);
	
	
	/*Seta ponteiros para as posições de memória do vetor A, B e result para poder manipular*/
	double* vetorA = (double*)&A;
	double* vetorB = (double*)&B;
	double* Result = (double*)&result;
	
	 printf("A(0)= %lf,A(1)= %lf,A(2)= %lf,A(3)= %lf \n", 
    vetorA[0], vetorA[1], vetorA[2], vetorA[3]);	
	
	 printf("B(0)= %lf,B(1)= %lf,B(2)= %lf,B(3)= %lf \n", 
    vetorB[0], vetorB[1], vetorB[2], vetorB[3]);
    	
	 printf("R(0)= %lf,R(1)= %lf,R(2)= %lf,R(3)= %lf,\n", 
    Result[0], Result[1], Result[2], Result[3]);
    
    return 0;
}
