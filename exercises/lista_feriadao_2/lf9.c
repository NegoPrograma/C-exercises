
#include <stdio.h>
#include <stdlib.h>

/*

-> escreva uma tabela onde cada numero seja categorizado como linha x coluna.(0 não incluido.)

*/


int main(){

int n;
scanf("%d",&n);
int i,j;
while(n > 0){
for(i = 0; i < n;i++){
    for(j = 0;j < n;j++)
        printf("%d \t",(i+1)*(j+1));
    printf("\n");
}
printf("\n");
scanf("%d",&n);
printf("\n");

}




return 0;
};