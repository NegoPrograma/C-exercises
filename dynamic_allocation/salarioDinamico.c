#include <stdio.h>
#include <stdlib.h>



int main(){
	
int n;
scanf("%d",&n);
char** vetor_de_nomes;
vetor_de_nomes = malloc(n*sizeof(char*));
for(;i<n;i++) vetor_de_nomes[i] = malloc(sizeof(char)*50);
float maior = 0;
float* salarios;
int i=0;
salarios = malloc(sizeof(float)*n);

	for(;i<n;i++){
		scanf("%s %f",vetor_de_nomes[i], &salarios[i]);
		if( i == 0 || salarios[i] > maior)
			maior = salarios[i];
	}

	for(i = 0; i< n; i++){
		if(salarios[i] == maior)
			printf("%s possui o maior salario \n", vetor_de_nomes[i]);
	}

	for(;i<n;i++) free(vetor_de_nomes[i]);
free(vetor_de_nomes);
free(salarios);


	return 0;
}