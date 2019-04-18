#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int horasProfessor1,horasProfessor2;
	float valorHoraP1, valorHoraP2;
	float salarioP1, salarioP2;

	scanf("%d %d",&horasProfessor1,&horasProfessor2);
	scanf("%f %f",&valorHoraP1,&valorHoraP2);
	salarioP1 = horasProfessor1*valorHoraP1;
	salarioP2 = horasProfessor2*valorHoraP2;

	if(salarioP1 > salarioP2)
		printf("%f",salarioP1);
	else
		printf("%f",salarioP2);
	
	return 0;
}