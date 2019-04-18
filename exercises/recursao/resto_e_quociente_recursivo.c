#include <stdio.h>
#include <stdlib.h>

//resto recursivo
int resto_recursivo(int a, int b){
	if(a < b)
		return a;
	else
		return resto_recursivo(a-b,b);
}

int quociente(int a, int b){
	if(a < b)
		return 0;
	else
		return (quociente(a-b,b)+1);
}



int main(int argc, char const *argv[]){
	int a,b,c;
	scanf("%d %d",&a,&b);
	printf("%d, %d", resto_recursivo(a,b),quociente(a,b));







	return 0;
}
