#include <immintrin.h>
#include <stdio.h>

int main() {

	/* Alocando espaço na memória do vetor A e B*/
	double* a = (double*) aligned_alloc (32, 4*(sizeof(double)));
	double* b = (double*) aligned_alloc (32, 4*(sizeof(double)));
	
	
	/* Entrada dos dados via console*/
	for (int i = 0; i < 4; i++){
		printf("Entre com o primeiro vetor: ");
		scanf("%le", &a[i]);
	}
	
	for (int i = 0; i < 4; i++){
		printf("Entre com segundo vetor: ");
		scanf("%le", &b[i]);
	}
	
	/* Carrega os vetores A e B na memoria*/
	__m256d vec1 = _mm256_load_pd(a);
	__m256d vec2 = _mm256_load_pd(b);
	
  
  /* Carrega o vetor neg na memoria utilizando o setr para carregar invertido*/
  __m256d neg = _mm256_setr_pd(1.0, -1.0, 1.0, -1.0);
  
  /* Passo 1: Multiplica-se o primeiro vetor com o segundo */
  __m256d vec3 = _mm256_mul_pd(vec1, vec2);

  /* Passo 2: Usando a mascara do permute alteramos o valor do vetor 2 onde o segundo
   * troca de lugar com o primeiro e o ultimo elemento troca com o terceiro elemento */
  vec2 = _mm256_permute_pd(vec2, 0x5);
  
  /*Passo 3: utilizando o vetor neg, transformamos o vetor 2 em numeros imaginarios utilizando
   * a intercalação de numeros positivos e negativos */
  vec2 = _mm256_mul_pd(vec2, neg);  
  
  /* Passo 4 : Multiplica-se o vetor1 com o vetor2 apos a modificação */
  __m256d vec4 = _mm256_mul_pd(vec1, vec2);

  /* Passo 5 : É realizado a soma de forma horizontal onde no primeiro vetor tem-se o A0 e A1 , com o B0 e B1
   * e no segundo vetor se encontra os valores A2 e A3 e o B2 e B3 */
  vec1 = _mm256_hsub_pd(vec3, vec4);
  
  /* Impressao dos valores no console*/
  double* res = (double*)&vec1;
  printf("%lf %lf %lf %lf\n", res[0], res[1], res[2], res[3]);
  
  return 0;
}
