#include <stdio.h>
#include <stdlib.h>

/*

-> escreva recursivamente strlen.

*/

int strlenRecursivo(char word[],int index){
    if(word[index] == '\0'){
        return index;
    }
    else
        strlenRecursivo(word,index+1);
}

int main(){
    char palavra[] = "cinco";
    printf("%d",strlenRecursivo(palavra,0));

return 0;
};