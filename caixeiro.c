#include<stdio.h>
#include<stdlib.h>

int c = 0, cost = 999999;

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

void cost_ar(int *ar, int n, int ** grafo , int* num){
	int i, soma = 0;
	for(i = 0; i <= n; i++){

		soma += grafo[ar[i % (n+1)]][ar[(i + 1) % (n+1)]];
	}
	
	if (cost > soma){	
		cost = soma;

		for(i = 0; i <= n; i++){
			num [i] = ar[i % (n+1)] + 1;//(caminho selecionado)
		}
   	}
}  

void permute(int *ar, int i, int n , int ** grafo , int*num){
	int j, k;
	if (i == n){
		cost_ar(ar, n, grafo, num);
	}
	else{
       		for (j = i; j <= n; j++){

        		swap((ar + i), (ar + j));
        		permute(ar, i + 1, n , grafo, num);
        		swap((ar + i), (ar + j));
       		
		}
   	}
} 

int main(int argc, char** argv){
	
	if (argc < 1) exit(EXIT_FAILURE);
	int size, i, j;
	scanf("%d", &size);

	int ** grafo = (int**) malloc(sizeof(int*)*size);
	int * ar = (int*) malloc(sizeof(int)*size);
	int * num = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size ; i++){
		ar[i] = i;
	}
	for(i = 0; i < size; i++){
		grafo[i] = (int*) malloc(sizeof(int)*size);
		for(j= 0; j < size; j++){
			scanf("%d", &grafo[i][j]);
		}
	}
	
	permute(ar, 0, size-1,grafo, num);
	printf("valor : %d \n", cost);
	printf("circuito : ");
	for(i =0 ; i < size ; i++){
		printf("%d - ", num[i]);
	}
	printf(" 1 ");

}
