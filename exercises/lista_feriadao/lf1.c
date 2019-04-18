#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int n;
	scanf("%d",&n);
	if(n % 2 == 0)
		printf("Par!\n");
	else
		printf("Impar!\n");

	return 0;
}