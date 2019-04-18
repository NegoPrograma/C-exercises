#include <stdio.h>
#include <stdlib.h>

//resto recursivo
int multiRec(int a, int b){
	if(a == 0)
		return a;
	else
		return (multiRec(a-1,b)+b);
}


int main(int argc, char const *argv[]){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d", multiRec(a,b));






	return 0;
}
