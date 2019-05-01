#include <stdio.h>
#include <stdlib.h>

//the task here is to find if a given number is a palindrome

int check(int n,int number);


int main(){
    int n, number;
    scanf("%d%d",&n,&number);

    if(check(n,number))
        printf("Sim, %d é palíndromo.",number);
    else
        printf("nanao meu parceiro, %d não é palíndromo não",number);
    return 0;
}

int check(int n,int number){
    int slicedNumber[n], i = 0;
    for(; i < n; i++){
        slicedNumber[i] = number % 10;
        number = number / 10;
        printf("%d ",slicedNumber[i]);
    }
    
    for(i = 0;i <= n;i++){
        if(slicedNumber[i] != slicedNumber[n-1])
            return 0;
        n--;
    }

    return 1;

}