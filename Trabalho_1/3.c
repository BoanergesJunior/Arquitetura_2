#include <immintrin.h>
#include <stdio.h>

int main(){
	
	
	/* Declarando valor de epi 16 onde 32760 corresponde ao valor maximo do tipo inteiro e o 10 e para estourar
	a memoria reservada para a mesma*/
	__m256i a = _mm256_set1_epi16(32760);
	__m256i b = _mm256_set1_epi16(10);
	
	
	/* Realizando as somas e subtracoes de 16 bits, onde se encontra o S no fim representa a saturação */
	__m256i A = _mm256_add_epi16(a,b);
	__m256i B = _mm256_adds_epi16(a,b);
	__m256i C = _mm256_sub_epi16(a,b);
	__m256i D = _mm256_subs_epi16(a,b);
	
	
	 /* Declaracao de ponteiros que carrega os respectivos valores de memória dos mesmos*/
	short* add = (short*)&A;
	short* adds = (short*)&B;
	short* sub = (short*)&C;
	short* subs = (short*)&D;
	
	/* Declarando valor de epi 8 onde 256 corresponde ao valor maximo do tipo inteiro e o 10 e para estourar
	a memoria reservada para a mesma*/
	__m256i Z = _mm256_set1_epi8(256);
	__m256i Y = _mm256_set1_epi8(10);
	
	/* Realizando as somas e subtracoes de 8 bits, onde se encontra o S no fim representa a saturação */
	__m256i X = _mm256_add_epi16(Z,Y);
	__m256i W = _mm256_adds_epi16(Z,Y);
	__m256i V = _mm256_sub_epi16(Z,Y);
	__m256i U = _mm256_subs_epi16(Z,Y);
	
	/* Declaracao de ponteiros que carrega os respectivos valores de memória dos mesmos*/
	short* add8 = (short*)&X;
	short* adds8 = (short*)&W;
	short* sub8 = (short*)&V;
	short* subs8 = (short*)&U;
	
   
   /* Impressao no console dos respectivos valores de 16 e 8 bits */
    printf("\n Add sem saturacao de epi16: \n");
    for (int i = 0; i < 16; i++){
		
		printf("%hi ", &add[i]);
	}
	
    printf("\n Adds com saturacao de epi16: \n");
    for (int i = 0; i < 16; i++){
		printf("%hi ", &adds[i]);
	}
	

	printf("\n Sub sem saturacao de epi16: \n");
    for (int i = 0; i < 16; i++){
		printf("%hi ", &sub[i]);
		
	}

	printf("\n Subs com saturacao de epi16 : \n");
    for (int i = 0; i < 16; i++){
		printf("%hi ", &subs[i]);
	}
	/*A partir deste ponto as impressões de epi8*/
	 printf("\n Add sem saturacao epi8: \n");
    for (int i = 0; i < 32; i++){
		
		printf("%hi ", &add8[i]);
	}
	
    printf("\n Adds com saturacao epi8: \n");
    for (int i = 0; i < 32; i++){
		printf("%hi ", &adds8[i]);
	}
	

	printf("\n Sub sem saturacao epi8: \n");
    for (int i = 0; i < 32; i++){
		printf("%hi ", &sub8[i]);
		
	}

	printf("\n Subs com saturacao epi8: \n");
    for (int i = 0; i < 32; i++){
		printf("%hi ", &subs8[i]);
	}




    return 0;
}
