#include <stdio.h>
#include <string.h>

 int conta_str(char str[]){
     int n = 0;
     for(int i = 0;str[i] != '\0';i++){
         n++;
     }
     return n;
 }

int main(int argc, char const *argv[]){

    int tam;
    char string[] = "eita bro bó conta as string tudo vei";
    
    printf("%d %d",strlen(string),conta_str(string));

    return 0;
}
