#include <stdio.h>
#include <string.h>


int conta_str(char str[]){
     int n = 0;
     for(int i = 0;str[i] != '\0';i++){
         n++;
     }
     return n;
 }

int compara_str(char str1[], char str2[]){
    int igualdade = 0;
    if(conta_str(str1) == conta_str(str2)){
        for(int i = 0;str1[i] != '\0';i++){
             if(str1[i] != str2[i])
                return ++igualdade;
        }
    }
    else
    {
        igualdade++;
    }

    return igualdade;
    

}

int main(int argc, char const *argv[]){
    char str1[] = "pao";
    char str2[] = "pam";

    printf("%d %d",compara_str(str1,str2),strcmp(str1,str2));
    return 0;
}
